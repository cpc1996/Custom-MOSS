#!/usr/bin/env ruby
#Input --> One code file
#Output --> The length of hashlist and hashlist elements and filesize

require_relative '../lib/myth.rb'


class Fingerprint

	def initialize

		#language noise confile
		lang_confile=File.open(File.expand_path('../../conf/java.conf', __FILE__))
		winnower_confile=File.open(File.expand_path('../../conf/winnower.conf', __FILE__))
		
# 		text=File.read(File.expand_path('../customtest6/Nguyễn Xuân Tuấn Anh - 20002105/Nguyen_Xuan_Tuan_Anh_20002105_Cau_2.c', __FILE__))
# 		size=File.size(File.expand_path('../customtest6/Nguyễn Xuân Tuấn Anh - 20002105/Nguyen_Xuan_Tuan_Anh_20002105_Cau_2.c', __FILE__))
		text=File.read(File.expand_path(ARGV[0], __FILE__))
		size=File.size(File.expand_path(ARGV[0], __FILE__))
		
		#Initialize configuration set for NoiseConfig
		lang_ins=Myth::Filter::FilterConfset.new(lang_confile)

		#Initialize ther filter
		filtered_text=Myth::Filter::NoiseFilter.new(text,lang_ins).get_filtered_text

		File.open(File.expand_path('../testcode/filtered', __FILE__),'w') do |f|
			f.print filtered_text
		end

		winnower_confile_ins=Myth::Winnowing::WinnowerConfset.new(winnower_confile)

		#Initialize the winnower
		winnower_ins=Myth::Winnowing::RobustWinnower.new(winnower_confile_ins,filtered_text)

		hash_list=winnower_ins.get_fingerprint

		print hash_list.length(), "\n"
		hash_list.each { |h| print h[:value], "\n", h[:line_span].begin() , "\n", h[:line_span].end() , "\n" }
		print size, "\n"


	end

end

Fingerprint.new
