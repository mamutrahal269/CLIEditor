#pragma once
#include <string>
#include <fstream>

namespace cliedit{
	
	int read(std::fstream& file);
	int search(std::fstream& file,std::string str);
	int copy(std::fstream& file1,std::fstream& file2);
	
}
