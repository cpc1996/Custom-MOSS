#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Mossum is a tool for summarizing results from Stanford's Moss. The tool
generates a graph for (multiple) results from Moss, which can help in
identifying groups of students that have shared solutions.

The tool can also generate a report, which shows which solutions are similar
between all pairs of students. When submitting multiple parts of an assignment
to Moss, this can help in identifying which students have multiple similar
solutions.
"""

"""
Example of a normal run:
	Step 0: Change parameters in run2.cpp
	Step 1: g++ -g -Wall run2.cpp -o run2 && ./run2 >! log2.txt 2>&1
	Step 2: tail -f -n 100 log2.txt
	Step 3: python3 mossum2.py data2.txt --identify -p 60
"""

import re
import sys
import os
import datetime
import pydot
import argparse
import requests as r
import collections
import numpy as np

from bs4 import BeautifulSoup
from faker import Faker
from collections import defaultdict, Counter
from itertools import chain
from matplotlib import pyplot as plt

exist_name_mapping = False

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('files', metavar='FILE', nargs='*',
                    help='Table of pairs of student, similar to urls data.')
#parser.add_argument('--urls', metavar='URL', nargs='*', default=None,
                    #help='URLs to Moss result pages.')
parser.add_argument('--min-percent', '-p', dest='min_percent', metavar='P', type=int, default=50,
                    help='All matches where less than P%% of both files are matched are ignored. (Default: %(default)s)')
parser.add_argument('--min-lines', '-l', dest='min_lines', metavar='L', type=int, default=1,
                    help='All matches where fewer than L lines are matched are ignored. (Default: %(default)s)')
parser.add_argument('--format', '-f', default='png',
                    help='Format of output files. See Graphviz documentation.')
parser.add_argument('--transformer', '-t', default='.*',
                    help='A regular expression that is used to transform the name of them matched files.')
parser.add_argument('--anonymize', '-a', default=False, action='store_true',
                    help='Substitute names of matched files for random names')
parser.add_argument('--identify', '-i', default=False, action='store_true',
                    help='Substitute names of matched files for names from name_mapping.txt')
parser.add_argument('--examine', '-e', default=False, action='store_true',
                    help='Plot the plagiarism score histogram from the data')
parser.add_argument('--name-mapping', '-n', default=False, action='store_true',
                    help='Create name_mapping.txt from the data')
parser.add_argument('--merge', '-m', default=False, action='store_true',
                    help='Merge all reports into one image')
parser.add_argument('--report', '-r', default=False, action='store_true',
                    help='Generates a report showing how many submissions each pair has in common.')
parser.add_argument('--hide-labels', default=False, action='store_true',
                    help='Hide edge labels, which otherwise show the percentage and lines of code matches have in common')
parser.add_argument('--show-links', default=False, action='store_true',
                    help='DEPRECATED: Labels with links are shown by default, use --hide-labels to hide them')
parser.add_argument('--output', '-o', default=None,
                    help='Name of output file.')
parser.add_argument('--show-loops', default=False, action='store_true',
                    help='Include loops in the output graph')
parser.add_argument('--filter', metavar='N', nargs='+', default=None,
                    help='Include only matches between these names.')
parser.add_argument('--filteri', metavar='N', nargs='+', default=None,
                    help='Include only matches involving these names.')
parser.add_argument('--filterx', metavar='N', nargs='+', default=None,
                    help='Exclude matches between these names.')
parser.add_argument('--filterxi', metavar='N', nargs='+', default=None,
                    help='Exclude matches involving any of these names.')
parser.add_argument('--min-matches', metavar='N', default=1, type=int,
                    help='Show only files with N or more matches between each other. This is only applicable to merged results. (Default: %(default)s).')
parser.add_argument('--title', dest='title', type=str, default='',
                    help='Title to be inserted in the final image')


class Results:
	def __init__(self, name, matches):
		self.name = name
		self.matches = matches


class Match:
	def __init__(self, first, second, lines, url):
		self.first = first
		self.second = second
		self.lines = lines
		self.url = url

	@property
	def percent(self):
		return max(self.first.percent, self.second.percent)
	
	@property
	def percent2(self):
		# exp((x-a)/ (a*pi*1.5))
		# a: threshold number of line for code copying
		# when a=15, 1/(a*pi*1.5) = 0.014147106
		# when a=15,     1/(a*pi) = 0.021220659
		# when a=20,     1/(a*pi) = 0.015915494
		# when a=25,     1/(a*pi) = 0.012732395
		e = np.exp((self.lines - 20) * .015915494) # exp((x-a)/a 
		return min(self.percent * e, 100)


class File:
	def __init__(self, name, percent):
		self.name = name
		self.percent = percent
		self.xname = name


class Filter:
	def __init__(self):
		filters = ['filter', 'filteri', 'filterx', 'filterxi']
		for f in filters:
			setattr(self, f, None)

		for f in filters:
			if getattr(args, f) != None:
				setattr(self, f, set(getattr(args, f)))

	def include(self, match):
		first = match.first.name
		second = match.second.name
		if (self.filter is not None and (first not in self.filter or second not
											in self.filter)):
			return False
		if (self.filteri is not None and (first not in self.filteri and second
											not in self.filteri)):
			return False
		if (self.filterx is not None and (first in self.filterx and second in
											self.filterx)):
			return False
		if (self.filterxi is not None and (first in self.filterxi or second in
											self.filterxi)):
			return False
		#return match.lines > args.min_lines and (match.first.percent > args.min_percent or
                                                 #match.second.percent > args.min_percent)
		return match.lines > args.min_lines and (match.percent2 > args.min_percent)


def date_str():
	return datetime.datetime.today().strftime('%d-%m-%Y_%H%M%S')


def parse_col(col):
	name, per = col.split()
	m = re.match(args.transformer, name) # 're' is python library for Regular expression operations
	if m:
		if m.groups():
			name = '_'.join(m.groups())
		else:
			name = m.group()
	per = int(re.search(r'\d+', per).group())
	return File(name, per)


def random_names(length):
	fake = Faker()

	names = set()
	while len(names) < length:
		names.add(fake.first_name())

	return names


def link_color(ratio):
	high = 0xE9, 0x01, 0x01
	low = 0xFF, 0xE3, 0x05

	# Normalized ratio
	if args.min_percent != 100:
		min_ratio = args.min_percent / 100
		ratio = (ratio - min_ratio) / (1 - min_ratio)

	color = [h * ratio + l * (1 - ratio) for h, l in zip(high, low)]
	return '#' + ''.join(hex(int(c))[2:].zfill(2) for c in color)


def anonymize(matches):
	# set() method is used to convert any of the iterable to sequence of iterable elements with distinct elements, commonly called Set. 
	s = set()
	for m in matches:
		s.add(m.first.name)
		s.add(m.second.name)

	# zip() method takes iterable or containers and returns a single iterator object, having mapped values from all the containers. 
	new_names = dict(zip(s, random_names(len(s))))

	for m in matches:
		m.first.name = new_names[m.first.name]
		m.second.name = new_names[m.second.name]


def identify(matches):
	global exist_name_mapping
	
	try:
		f = open('name_mapping.txt', 'r')
		exist_name_mapping = True
		
		print('There exists name_mapping.txt. Reading name_mapping.txt ...')
		lines = f.readlines()
		
		new_names = {}
		for aline in lines:
			aline = aline.split('\t\t', 2)
			val = aline[0]
			key = aline[1].rstrip()
			new_names[key] = val
			
		for m in matches:
			m.first.name = new_names[m.first.name]
			m.second.name = new_names[m.second.name]
			
	except IOError as error:
		print('There is no name_mapping.txt:', error)
		print('Solution: Run mossum again with low min_percent and \'--name-mapping\' flag!')
		exit()
		
	except KeyError as error:
		print('There is missing a key in name_mapping.txt:', error)
		print('Solution: Run mossum again with low min_percent and \'--name-mapping\' flag!')
		exit()
		
	finally:
		f.close()
	print('DONE\n')


def generate_report(results):
	pairs = defaultdict(list)
	xname = {}
	for res in results:
		for match in res.matches:
			pairs[(match.first.name, match.second.name)].append((res.name, match))
			xname[match.first.name] = match.first.xname
			xname[match.second.name] = match.second.xname

	if args.output:
		base = args.output
	else:
		#base = '+'.join(map(lambda x: x.name, results))
		base = get_filename() + "_all_report"
	filename = '%s.txt' % base

	xname = collections.OrderedDict(sorted(xname.items()))
	
	print('Generating', filename, '...')
	with open(filename, 'w') as f:
		for aname in xname:
			f.write('%s\t\t%s\n' % (aname, xname[aname]))
			
		f.write('\n\n')
		
		for pair, matches in sorted(pairs.items(),
									key=lambda x: (len(x[1]), sorted(map(lambda x: x[0], x[1]))), reverse=True):
			f.write('Pair: %s and %s\n' % pair)
			for name, match in sorted(matches):
				f.write('%s: %s\n' % (name, match.url))
				f.write('similarity score: %s\n' % match.percent)
				f.write('number of common lines: %s\n' % match.lines)

			f.write('\n\n')
	print('DONE\n')
	
	if (exist_name_mapping == False or args.anonymize == True):
		print('Updating name_mapping.txt ...')
		with open('name_mapping.txt', 'w') as f:
			for aname in xname:
				f.write('%s\t\t%s\n' % (aname, xname[aname]))
		print('DONE\n')
			

def generate_score_histogram(matches):
	x = np.array([])
	for m in matches:
		p = m.percent
		if p > 0: x = np.append(x, p)
		
	binwidth = 1
	plt.hist(x, bins=range(0, 100 + binwidth, binwidth))
	
	plt.title('Plagiarism score histogram')
	plt.xlabel('score (%)')
	plt.ylabel('count')
	plt.grid(color='gray', linestyle='--')
	#plt.show()
	plt.savefig('score_histogram.png')
	

def generate_name_mapping(matches):
	anonymize(matches)
	
	xname = {}
	for m in matches:
		xname[m.first.name] = m.first.xname
		xname[m.second.name] = m.second.xname

	xname = collections.OrderedDict(sorted(xname.items()))
	
	print('Updating name_mapping.txt ...')
	with open('name_mapping.txt', 'w') as f:
		for aname in xname:
			f.write('%s\t\t%s\n' % (aname, xname[aname]))
	print('DONE\n')


def merge_filter(matches):
	pairs = [tuple(sorted([match.first.name, match.second.name])) for match in matches]
	intereseting = {pair for pair, count in Counter(
		pairs).items() if count >= args.min_matches}
	return [match for match in matches if tuple(sorted([match.first.name, match.second.name])) in intereseting]


def merge_results(results):
	# join() method is a string method and returns a string in which the elements of the sequence have been joined by the str separator.
	name = '+'.join(map(lambda x: x.name, results))
	matches = merge_filter(list(chain(*map(lambda x: x.matches, results))))
	return Results(name, matches)


#def get_results(moss_url):
    #resp = r.get(moss_url)
    ## Beautiful Soup is a Python package for parsing HTML and XML documents.
    #soup = BeautifulSoup(resp.content.decode('utf-8'), 'html5lib')

    #ps = soup('p') # The <p> HTML element represents a paragraph.
    
    ## Find name
    #name = None
    #if len(ps) >= 2:
        #name = ps[2].text.strip()
    #if not name:
        #name = 'moss_%s' % date_str()

	## Find matches from table of results
    #matches = []

    #for row in soup.table('tr')[1:]:
		## map() function returns a map object(which is an iterator) of the results after applying the given function to each item of a given iterable (list, tuple etc.)
        #first, second, lines = map(lambda x: x.text, row('td')) # convert a row to 3 texts and map to first, second, and lines
        #first = parse_col(first) # first and second are now Files (name + percent)
        #second = parse_col(second)
        #lines = int(lines)
        #url = row.a['href'] # url only for additional information of report + image
        #matches.append(Match(first, second, lines, url))

	#fil = Filter()
    #matches = list(filter(fil.include, matches)) 
    ## filter() method filters the given sequence with the help of a function that tests each element in the sequence to be true or not.
    ## in this case, matches only includes elements satisfied given conditions (min/max percent, specified names, etc.)

    #return Results(name, matches) # matches = list of Match = list of ((name + percent1), (name + percent2), nline, url, percent)


def get_results_2(afile):
	f = open(afile, 'r')
    
	# Find name
	name = f.readline() # name can also be a comment
	name = name.strip() 
	if not name:
		name = 'moss_%s' % date_str()

	# Find matches from table of results
	matches = []

	lines = f.readlines()
	
	for aline in lines:
		aline = aline.split('\t')
		first = File(aline[0], float(aline[1]))
		second = File(aline[2], float(aline[3]))
		lines = int(aline[4])
		url = 'url not found'
		matches.append(Match(first, second, lines, url))
		
	f.close()

	fil = Filter()
	matches = list(filter(fil.include, matches)) 

	return Results(name, matches) # matches = list of Match = list of ((name + percent1), (name + percent2), nline, url, percent)


def get_filename():
	name = os.path.splitext(args.files[0])[0]
	if args.anonymize:
		name = name + '_anonymize'
	elif args.identify:
		name = name + '_identify'
	name = name + '_p-' + str(args.min_percent) # add min_percent
	name = name + '_' + date_str() # add date
	return name


def image(results, index=None, label=None):
	graph = pydot.Dot(label=label, graph_type='graph')

	print('Generating image for %s' % args.files[0], '...')
	for m in results.matches:
		#ratio = m.percent / 100
		ratio = m.percent2 / 100
		color = link_color(ratio)
		extra_opts = {
			'color': color,
			'penwidth': 3,
		}
		if not args.hide_labels:
			extra_opts.update({
				'label': '{0}% ({1})'.format(m.percent, m.lines),
				'labelURL': m.url,
				'URL': m.url,
				'fontcolor': color,
			})
		if m.first.name != m.second.name or args.show_loops:
			graph.add_edge(pydot.Edge(m.first.name, m.second.name, **extra_opts))

	if args.output:
		name = args.output
		if index is not None:
			name = '%s-%d' % (name, index)
	else:
		#name = results.name
		name = get_filename()
		
	filename = '%s.%s' % (name, args.format)

	if os.path.exists(filename):
		os.remove(filename)

	graph.write(filename, format=args.format)
	if args.format == 'xlib':
		os.remove(filename)
	print('DONE\n')


def main():
	global args
	args = parser.parse_args()
	
	if args.examine or args.name_mapping: args.min_percent = 0

	#urls = args.urls
	#if not urls:
		#urls = sys.stdin.read().splitlines()

	# sys.stdin.readline() waits forever until it receives a newline.
	files = args.files
	if not files:
		files = sys.stdin.read().splitlines()

	all_res = []
	for x in files:
		#res = get_results(x)
		print('Reading file', x, '...')
		res = get_results_2(x)
		all_res.append(res)
		print('DONE\n')
		
	if args.examine:
		merged = merge_results(all_res)
		generate_score_histogram(merged.matches)
		exit()
		
	if args.name_mapping:
		merged = merge_results(all_res)
		generate_name_mapping(merged.matches)
		exit()
		
	if args.merge:
		merged = merge_results(all_res)
		if args.anonymize:
			anonymize(merged.matches)
		elif args.identify:
			identify(merged.matches)
		image(merged, label=args.title)
	else:
		for i, res in enumerate(all_res):
			if args.anonymize:
				anonymize(res.matches)
			elif args.identify:
				identify(res.matches)
			image(res, i+1, label=args.title)


	#if args.report:
	generate_report(all_res)


if __name__ == '__main__':
	main()

### Custom name_mapping
### Loop over subfolders of customtest5
### space character in name -> "\ "
### Specify name of file .png
### Improve formula of similarity: depending on number of lines, etc

# Improve formula of similarity: depending on number of test (test 1, test 2, test 3, etc.)
# Database of previous codes of previous tests
# Prevent malware from student code (auto/online judge) (using sand box such as docker)
# Include students with high number of similar lines (high nline)
# Extract graph to file -> for modifying -> re-color graph: edges + nodes




