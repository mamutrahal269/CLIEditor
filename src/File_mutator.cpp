#include "../include/File_mutator.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace editor;

File_mutator::File_mutator(const std::string filename) : file_name(filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename,std::ios::in | std::ios::out | std::ios::binary);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
File_mutator::File_mutator(const std::string filename,std::ios::openmode mode)  : file_name(filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename,std::ios::in | std::ios::out | std::ios::binary | mode);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
File_mutator::~File_mutator() noexcept{
	if(file.is_open()) file.close();
}
void File_mutator::open_file(const std::string filename){
	file_name = filename;
	file.open(filename,std::ios::in | std::ios::out | std::ios::binary);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_mutator::open_file(const std::string filename,std::ios::openmode mode){
	file_name = filename;
	file.open(filename,std::ios::in | std::ios::out | std::ios::binary | mode);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_mutator::erase_bytes(int start,int count){
	std::string temp("");
	char buffer[4096];
	while(file){
		file.read(buffer,4096);
		temp.append(buffer,file.gcount());
	}
	try{
		temp.erase(start - 1,count);//уменьшение start,потому что пользователь считает от 1, а не от 0
	}catch(std::out_of_range& err){
		throw std::runtime_error("выход за границы файла");
	}
	file.close();
	file.open(file_name,std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
	file<<temp;
}
void File_mutator::insert(int byte,const std::string str){
	std::string temp("");
	char buffer[4096];
	while(file){
		file.read(buffer,4096);
		temp.append(buffer,file.gcount());
	}
	try{
		temp.insert(byte,str);
	}catch(std::out_of_range& err){
		throw std::runtime_error("выход за границы файла");
	}
	file.close();
	file.open(file_name,std::ios::in | std::ios::out | std::ios::trunc | std::ios::binary);
	file<<temp;
}
File_mutator& File_mutator::operator<<(const std::string str){
	file<<str;
	return *this;
}
