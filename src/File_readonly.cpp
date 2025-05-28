#include "../include/File_readonly.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace editor;

File_readonly::File_readonly(const std::string filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename,std::ios::binary);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл ");
	}
}
File_readonly::~File_readonly() noexcept{
	if(file.is_open()) file.close();
	if(helpfile.is_open()) helpfile.close();
}
void File_readonly::open_file(std::string filename){
	file.open(filename,std::ios::binary);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_readonly::readfile(){
	std::string temp("");
	char buffer[4096];
	while(file){
		file.read(buffer,4096);
		temp.append(buffer,file.gcount());
	}
	std::cout << temp;
	std::cout << "\n------------------------------\n";
	std::cout << "Размер файла: " << temp.size() << " байт\n";
}
void File_readonly::search(const std::string str){
	std::string temp("");
	char buffer[4096];
	while(file){
		file.read(buffer,4096);
		temp.append(buffer,file.gcount());
	}
	int index = temp.find(str);
	if(index == -1){
		throw std::runtime_error("строка не найдена");
	}
	index++;//пользователь считает от 1,а не от 0
	std::cout << "Байт начала строки: " << index << '\n';
}
void File_readonly::copyfile(const std::string filename) {
    helpfile.open(filename,std::ios::out | std::ios::trunc | std::ios::binary);
    if(!helpfile.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
	char buffer[4096];
	while(file){
		file.read(buffer,4096);
		helpfile.write(buffer,file.gcount());
	}
}
	
