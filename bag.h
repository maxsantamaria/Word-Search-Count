#ifndef _BAG_H
#define _BAG_H

#include <string>
#include "word.h"

#define LIMIT 10000 

class Bag{
  //Word container[LIMIT];
  dnode<Word*>* head_word;

  int count;  // Number of words
  
public:
  // the below function is used to print the contents of
  // container array (declared at line 40)  in the format <WORD::COUNT>
  void print_words(std::string word);
  void print_files_containing(std::string word, int threshold);

  // ADD NEW MEMBER FUNCTIONS HERE AS NEEDED
  Bag();
  ~Bag();
  bool insert(std::string new_word, std::string file_name);
  int size() const {return count;};
  void word_union(std::string word1, std::string word2);
};

#endif