#include "bag.h"
#include<iostream>

using namespace std;


Bag::Bag(){
	count=0;
	head_word = NULL;
}

Bag::~Bag(){
	dnode<Word*>* curr = head_word;
	while (curr){
		delete curr -> data();
		curr = curr -> link();
	}

	list_clear(head_word);
}

bool Bag::insert(std::string new_word, std::string file_name){

	int i = 0;
	dnode<Word*>* curr = head_word;
	dnode<Word*>* previous;
	Word* curr_word;
	if (!head_word)
	{
		Word* word = new Word (new_word);
		word -> insert(file_name);
		head_word = new dnode<Word*>(word);
		//cout << file_name << "  " << new_word << "  " << count << endl ;
		count++;
	}
	while (curr)
	{
		curr_word = curr -> data();
		if (curr_word -> get_word() == new_word)
		{
			curr_word -> insert(file_name);
			break;
		}
		else if (new_word < curr_word -> get_word())
		{
			//cout << "Now " << new_word << "  " << curr -> prev() -> data() -> get_word() << "  " << curr_word -> get_word() << endl;
			Word* word = new Word(new_word);
			word -> insert(file_name);
			if (curr -> prev())
			{
				previous = curr -> prev();
				list_insert(previous, word);
			}
			else {
				list_head_insert(curr, word);
				head_word = curr -> prev();
			}
			//cout << file_name << "  " << new_word << "  " << count << endl;
			count++;
			break;
		}
		else if (!curr -> link())
		{
			Word* word = new Word(new_word);
			word -> insert(file_name);
			list_insert(curr, word);
			//cout << file_name << "  " << new_word << "  " << count << endl;
			count++;
			break;
		}
		curr = curr -> link();
	}
	return true;
	
}


void Bag::print_files_containing(std::string word, int threshold){
	dnode<Word*>* curr = head_word;
	Word* curr_word;
	while (curr) {
		curr_word = curr -> data();
		if (curr_word -> get_word() == word)
		{
			//cout << "entro" << endl;
			curr_word -> print_files_containing(threshold);
		}
		curr = curr -> link();

	}

}

void Bag::print_words(std::string word){
	dnode<Word*>* curr = head_word;
	Word* curr_word;
	while (curr)
	{
		curr_word = curr -> data();
		if (curr_word -> get_word() == word)
		{
			curr_word -> print_info();
			return;
		}
		curr = curr -> link();
	}
	cout << "Word not found in database" << endl;
}


void Bag::word_union(std::string word1, std::string word2){
	dnode<Word*>* curr = head_word;
	Word* curr_word; 
	Word* word1_ptr = NULL;
	Word* word2_ptr = NULL; 
	while (curr)
	{
		curr_word = curr -> data();
		if (curr_word -> get_word() == word1)
		{
			word1_ptr = curr_word;
		}
		else if (curr_word -> get_word() == word2)
		{
			word2_ptr = curr_word;
		}
		curr = curr -> link();
	}
	if (word1_ptr && word2_ptr)
	{
		word1_ptr -> word_union(*word2_ptr);
	}
	else if (word1_ptr)
	{
		word1_ptr -> print_files();
	}
	else{
		word2_ptr -> print_files();
	}


}