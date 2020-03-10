#ifndef _FILE_H
#define _FILE_H

#include <string>

class File{
private:
	std::string name;
	int count;

public:
	File() {name = ""; count = -1;}
	File(std::string name);
	void increase_count();
	std::string get_name() const {return name;};
	int get_count() const {return count;};
};


#endif