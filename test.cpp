#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

// ADD ANY HEADER FILES YOU NEED
#include "bag.h"



using namespace std;

int main(int argc, char const *argv[])
{
	
	Bag bag;
	//Word word("hola");
	bag.insert("hola", "file1.txt");
	bag.insert("hola", "file2.txt");
	bag.insert("hola", "file1.txt");
	bag.insert("holaa", "file1.txt");
	bag.insert("hola", "file3.txt");
	bag.insert("hola", "file3.txt");
	bag.insert("hol", "file3.txt");
	bag.print_files_containing("hola", 1);
	//word.insert("file1.txt");
	//word.insert("file2.txt");
	//word.insert("file1.txt");
	//word.insert("file1.txt");
	//word.insert("file4.txt");
	//word.insert("file1.txt");
	//bag.print_words("hola");
	//cout << "holaa" << endl;
	return 0;
}