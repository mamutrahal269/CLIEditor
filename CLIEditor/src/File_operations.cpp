#include "../include/File_operations.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define NL '\n'
int cliedit::read(fstream& file){
	if(!file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	char ch;
	int size = 0;
	cout << NL;
	while(file.get(ch)){
		cout << ch;
		size++;
	}
	cout << NL <<"--------------------------" << NL << "Размер файла: " << size << " байт" << NL ;
	file.close();
	return 0;
}
int cliedit::search(fstream& file,const string& str){
	if(!file.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	string temp;
	char ch;
	while(file.get(ch)) temp += ch;
	int index = temp.find(str);
	if(index == string::npos){
		cout << "Строка не найдена" << NL;
		return 1;
	}
	index++;
	int size = index + str.size() - 1;
	cout << "Байт начала строки: " << index << NL;
	cout << "Байт конца строки: " << size << NL;
	cout << "Размер строки: " << str.size() << NL;
	file.close();
	return 0;
}
int cliedit::copy(fstream &file,fstream& file2){
	if(!file.is_open() || !file2.is_open()){
		cerr << "Файл не открыт\n";
		return 1;
	}
	char ch;
	while(file.get(ch)) file2.put(ch);
	file.close();
	file2.close();
	return 0;
}
