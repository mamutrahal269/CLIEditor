#pragma once
#include <string>
#include <fstream>
namespace cliedit{
	
	int write(std::fstream& file,std::string str);
	int erase(const std::string& filename,int start,int count);
	int paste(const std::string& file,const std::string& str,int byte);
	
}
