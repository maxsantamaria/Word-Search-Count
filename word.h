#ifndef _WORD_H
#define _WORD_H

#include <string>
#include "file.h"
#include "dnode.h"


#define LIMIT_FILES 10 


class Word{
private:
	std::string word;
	//File container[10];
	dnode<File*>* head_file;

	int count;  // Number of files
	int total_count;  // Count of words

public:
	Word() {word = ""; count = -1;};
	Word(std::string name);
	~Word();

	void print_info();
	void print_files_containing(int threshold);
	void print_files();

	bool insert(std::string file_name);
	int size() const {return count;};
	std::string get_word() const {return word;};
	//dnode<File*>* word_union (const Word*& word2); 
	bool contains(std::string file_name);	
	void word_union(const Word& word2);

};


#endif