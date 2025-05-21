#include "../include/File_readonly.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace editor;

File_readonly::File_readonly(const std::string filename){
	if(filename == ""){
		throw std::runtime_error("пустое имя файла");
	}
	file.open(filename);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл ");
	}
}
File_readonly::~File_readonly() noexcept{
	if(file.is_open()) file.close();
	if(helpfile.is_open()) helpfile.close();
}
void File_readonly::open_file(std::string filename){
	file.open(filename);
	if(!file.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
}
void File_readonly::readfile(){
	char ch;
	int size = 0;
	while(file.get(ch)){
		size++;
		std::cout << ch;
	}
	std::cout << "\n------------------------------\n";
	std::cout << "Размер файла: " << size << " байт\n";
}
void File_readonly::search(const std::string str){
	std::string temp;
	char ch;
	while(file.get(ch)) temp += ch;
	int index = temp.find(str);
	if(index == -1){
		throw std::runtime_error("строка не найдена");
	}
	index++;
	std::cout << "Байт начала строки: " << index << '\n';
}
void File_readonly::copyfile(const std::string filename) {
    helpfile.open(filename,std::ios::out | std::ios::trunc);
    if(!helpfile.is_open()){
		throw std::runtime_error("не удалось открыть файл");
	}
	
    char ch;
    while (file.get(ch)) {
        helpfile.put(ch);
    }
}
	
