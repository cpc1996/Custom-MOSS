#!/usr/bin/env ruby
#Designing a rolling hash function.
#Inspired from the Rabin-Karp Algorithm

module Myth
  module Hasher
    
    #Defining a Hash Structure
    #A hash is a integer value + line number where the word for this hash existed in the source file
    Struct.new('Hash',:value,:line_number)
    
    #For hashing a piece of text we ned two sets of parameters
    #k-->k grams hashes    
    def calc_hash(text_to_process,k)
      
      text_length=text_to_process.length
      radix=26
      
      highorder=(radix**(text_length-1))
      
      #Individual hashes for k-grams
      text_hash=0
      
      #the entire k-grams hashes list for the document
      text_hash_string=""

      #Preprocessing
      for c in 0..k do
        text_hash=(radix*text_hash+text_to_process[c].ord)
      end

      text_hash_string << text_hash.to_s << " "
      
      loop=text_length-k
      
      for c in k...loop do
        text_hash=(radix*(text_hash-(text_to_process[k+1].ord)*highorder)+(text_hash[k+text_length].ord))
        text_hash_string<< text_hash_string << " "
      end      
    end
    
  end
end