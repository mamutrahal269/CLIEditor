#include "../include/File_edit.hpp"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int cliedit::write(fstream& file,string str){
	if(!file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	int i = 0;
	while(str[i]) file.put(str[i++]);
	file.close();
	return 0;
}
int cliedit::erase(const std::string& filename,int start,int count){
	fstream file(filename,ios::in);
	if(!file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	string temp;
	char ch;
	while(file.get(ch)) temp += ch;
	try{
		temp.erase(start,count);
	}catch(out_of_range& err){
		cerr << "Выход за границы файла!\n";
		return 1;
	}
	file.close();
	file.open(filename,ios::out | ios::trunc);
	file << temp;
	file.close();
	return 0;
}
int cliedit::paste(const std::string& file,const std::string& str,int byte){
	ofstream write_file;
	ifstream read_file;
	read_file.open(file);
	if(!read_file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	string temp;
	char ch;
	while(read_file.get(ch)) temp += ch;
	try{
		temp.insert(byte,str);
	}catch(out_of_range& err){
		cerr << "Выход за границы файла! \n";
		return 1;
	}
	read_file.close();
	write_file.open(file,ios::out | ios::trunc);
	if(!write_file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	write_file<<temp;
	write_file.close();
	return 0;
}
