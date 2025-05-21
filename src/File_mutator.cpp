#include "../include/File_mutator.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace editor;

File_mutator::File_mutator(const std::string filename) : file_name(filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename,std::ios::in | std::ios::out);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл " + filename);
	}
}
File_mutator::File_mutator(const std::string filename,std::ios::openmode mode)  : file_name(filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename,std::ios::in | std::ios::out | mode);
	if(!file.is_open()){
		throw std::runtime_error("Не удалось открыть файл " + filename);
	}
}
File_mutator::~File_mutator() noexcept{
	if(file.is_open()) file.close();
}
void File_mutator::open_file(const std::string filename){
	file_name = filename;
	file.open(filename,std::ios::in | std::ios::out);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_mutator::open_file(const std::string filename,std::ios::openmode mode){
	file_name = filename;
	file.open(filename,std::ios::in | std::ios::out | mode);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_mutator::erase_bytes(int start,int count){
	std::string temp;
	char ch;
	while(file.get(ch)) temp += ch;
	start--;
	try{
		temp.erase(start,count);
	}catch(std::out_of_range& err){
		throw std::runtime_error("выход за границы файла");
	}
	file.close();
	file.open(file_name,std::ios::in | std::ios::out | std::ios::trunc);
	file<<temp;
}
void File_mutator::insert(int byte,const std::string str){
	std::string temp;
	char ch;
	while(file.get(ch)) temp += ch;
	try{
		temp.insert(byte,str);
	}catch(std::out_of_range& err){
		throw std::runtime_error("выход за границы файла");
	}
	file.close();
	file.open(file_name,std::ios::in | std::ios::out | std::ios::trunc);
	file<<temp;
}
File_mutator& File_mutator::operator<<(const std::string str){
	file<<str;
	return *this;
}
