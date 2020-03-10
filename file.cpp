#include <iostream>
#include "file.h"


File::File(std::string name){
	this -> name = name;
	count = 1;
}

void File::increase_count() {
	this -> count += 1;
}

