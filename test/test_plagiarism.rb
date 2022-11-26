#!/usr/bin/env ruby
#Test whether for two similar documents after winnowing their line numbers are actually making sense
#Input --> Two similar code files
#Output --> Line Pairs which are Plagiarised form each other

require_relative '../lib/myth.rb'


class TestPlagiarism

  def initialize

    #language noise confile
    lang_confile=File.open(File.expand_path('../../conf/java.conf', __FILE__))
    winnower_confile=File.open(File.expand_path('../../conf/winnower.conf', __FILE__))

# 	text_one=File.read(File.expand_path('../customtest3/Nguyen_Thanh_Long_20002142_Cau_2.c', __FILE__))
# 	text_two=File.read(File.expand_path('../customtest3/Luu_The_Trung_20002170_cau_3.c', __FILE__))
# 	size_one=File.size(File.expand_path('../customtest3/Nguyen_Thanh_Long_20002142_Cau_2.c', __FILE__))
# 	size_two=File.size(File.expand_path('../customtest3/Luu_The_Trung_20002170_cau_3.c', __FILE__))
	text_one=File.read(File.expand_path(ARGV[0], __FILE__))
	text_two=File.read(File.expand_path(ARGV[1], __FILE__))
	size_one=File.size(File.expand_path(ARGV[0], __FILE__))
	size_two=File.size(File.expand_path(ARGV[1], __FILE__))
	
# 	print size_one, "\n"
# 	print size_two, "\n"
	swap = 0
	
	if size_one < size_two then
		text_three = text_one
		text_one = text_two
		text_two = text_three
		swap = 1
	end

    #Initialize configuration set for NoiseConfig
    lang_ins=Myth::Filter::FilterConfset.new(lang_confile)

    #Initialize ther filter
    filtered_text_one=Myth::Filter::NoiseFilter.new(text_one,lang_ins).get_filtered_text
    filtered_text_two=Myth::Filter::NoiseFilter.new(text_two,lang_ins).get_filtered_text

    File.open(File.expand_path('../testcode/filtered', __FILE__),'w') do |f|
      f.print filtered_text_one
    end

    File.open(File.expand_path('../testcode/filtered2', __FILE__),'w') do |f|
      f.print filtered_text_two
    end


    winnower_confile_ins=Myth::Winnowing::WinnowerConfset.new(winnower_confile)

    #Initialize the winnower
    winnower_ins=Myth::Winnowing::RobustWinnower.new(winnower_confile_ins,filtered_text_one)
    winnower_ins2=Myth::Winnowing::RobustWinnower.new(winnower_confile_ins,filtered_text_two)

    hash_list=winnower_ins.get_fingerprint
    hash_list2=winnower_ins2.get_fingerprint
	
# 	puts 'List1'
# 	hash_list.each { |h| print h[:value], " " }
# # 	hash_list.each { |h| print h[:value], " ", h[:line_span] , "\n" }
# 	print "\n\n"
	
# 	puts 'List2'
# 	hash_list2.each { |h| print h[:value], " " }
# # 	hash_list2.each { |h| print h[:value], " ", h[:line_span] , "\n" }
# 	print "\n\n"

    #A hashtable for detecting common elements between two Hash List
    #For the 1st list we mark all the elements present in table with 'Y'
    #For the next list, we check if hash is in the table.
    #If Yes, we have a  duplicate and we report the two line spans
    common=Hash.new

    hash_list.each do |h|
      common[h[:value]]=h[:line_span]
    end

	len1 = hash_list.length()
	len2 = hash_list2.length()
	clen = 0
	
    #Match the fingerprints
	merged_line_span_1 = (-1..-1)
	merged_line_span_2 = (-1..-1)
    hash_list2.each do |h|
		if common.include?(h[:value]) then
			merged_line_span_1 = [merged_line_span_1, common[h[:value]]].map { |r| Array(r) }.inject( :+ )
			merged_line_span_2 = [merged_line_span_2, h[:line_span]].map { |r| Array(r) }.inject( :+ )
# 			print '(', h[:value] , ')' , common[h[:value]] , " " , h[:line_span], "\n"
			clen = clen + 1
		end
    end
	
	merged_line_span_1 = merged_line_span_1.uniq
	merged_line_span_2 = merged_line_span_2.uniq
# 	print "clen: ", clen, "\n"
# 	print "merged_line_span_1: ", merged_line_span_1.length, "\n"
# 	print "merged_line_span_2: ", merged_line_span_2.length, "\n"
	
	score1 = 100.0 * clen / len1
	score2 = 100.0 * clen / len2
	nline = [merged_line_span_1.length, merged_line_span_2.length].min
	
	if swap === 1
		tmp = score1
		score1 = score2
		score2 = tmp
	end
	
	print size_one, "\n", size_two, "\n"
	print score1, "\n", score2, "\n", nline, "\n"

  end

end

TestPlagiarism.new
