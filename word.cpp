#include <iostream>
#include "word.h"

using namespace std;

Word::Word(std::string name){
	word = name;
	count = 0;
	total_count = 0;
	head_file = NULL;
}

Word::~Word(){
	dnode<File*>* curr = head_file;
	while (curr){
		delete curr -> data();
		curr = curr -> link();
	}

	list_clear(head_file);
}

bool Word::insert(std::string file_name){
	dnode<File*>* curr = head_file;
	dnode<File*>* previous;
	File* curr_file;
	if (!head_file)
	{
		//File new_file (file_name);
		File* new_file = new File (file_name);
		head_file = new dnode<File*>(new_file);
		count++;
		total_count++;
	}
	while (curr){
		curr_file = curr -> data();
		if (curr_file -> get_name() == file_name)
		{
			curr_file -> increase_count();
			total_count++;
			return true;	
		}
		else if (file_name < curr_file -> get_name())
		{
			//File new_file (file_name);
			File* new_file = new File (file_name);
			if (curr -> prev())
			{
				previous = curr -> prev();
				list_insert(previous, new_file);
			}
			else {
				list_head_insert(curr, new_file);
				head_file = curr -> prev();
			}
			count++;
			total_count++;
			return true;
		}
		if (!curr -> link())
		{
			//File new_file (file_name);
			File* new_file = new File (file_name);
			list_insert(curr, new_file);
			count++;
			total_count++;
			return true;
		}
		curr = curr -> link();
	}
	
}

void Word::print_files_containing(int threshold){
	dnode<File*>* curr = head_file;
	File* curr_file;
	while(curr){
		curr_file = curr -> data();
		if (curr_file -> get_count() >= threshold)
		{
			cout << curr_file -> get_name() << endl;
		}
		curr = curr -> link();
	}
}

void Word::print_info(){
	cout << "Total Count: " << total_count << endl;
	dnode<File*>* curr = head_file;
	File* curr_file;
	while(curr){
		curr_file = curr -> data();
		cout << curr_file -> get_name() << "::" << curr_file -> get_count() << endl;
		curr = curr -> link();
	}
}

/*dnode<File*>* Word::word_union (const Word*& word2){
	dnode<File*>* result = new dnode<File*>;
	result = head_file;
	dnode<File*>* curr2 = word2 -> head_file;
	File* curr_file;
	while(curr2){
		curr_file = curr2 -> data();
		if (!this -> contains(curr_file -> get_name()))
		{
			result
		}


		curr2 = curr2 -> link()
	}
}
*/

bool Word::contains(std::string file_name){
	dnode<File*>* curr = head_file;
	File* curr_file;
	while(curr){
		curr_file = curr -> data();
		if (curr_file -> get_name() == file_name)
		{
			return true;
		}
		else if (file_name < curr_file -> get_name())
		{
			return false;
		}
		curr = curr -> link();
	}
	return false;
}

void Word::word_union(const Word& word2){
	Word new_word(" ");
	dnode<File*>* curr = head_file;
	File* curr_file;
	while(curr){
		curr_file = curr -> data();
		new_word.insert(curr_file -> get_name());
		curr = curr -> link();
	}
	dnode<File*>* curr2 = word2.head_file;
	while(curr2){
		curr_file = curr2 -> data();
		if (!new_word.contains(curr_file -> get_name()));
		{
			new_word.insert(curr_file -> get_name());
		}
		curr2 = curr2 -> link();
	}
	new_word.print_files();
}

void Word::print_files(){
	dnode<File*>* curr = head_file;
	File* curr_file;
	while(curr){
		curr_file = curr -> data();
		cout << curr_file -> get_name() << endl;
		curr = curr -> link();
	}
}

