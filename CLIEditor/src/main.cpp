
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "../include/File_operations.hpp"
#include "../include/File_edit.hpp"
#include "../include/User_manual.hpp"
#define n '\n'
using namespace std;
int main(int argc,char* argv[]){
	vector<string> args(argv, argv + argc);
	if(args.size() == 2 && args[1] == "--help"){
		cliedit::show_manual();
		return 0;
	}
	if(args.size() == 4 && args[2] == "--help"){
		cliedit::show_command_manual(args[3]);
		return 0;
	}
	if(args.size() < 3){
		cliedit::show_manual();
		return 1;
	}
	string filename = args[1];
	string command = args[2];
	
	if(command == "-rd"){
		if(args.size()>3){
			cliedit::show_command_manual("rd");
			return 1;
		}
		fstream file(filename,ios::in);
		if(cliedit::read(file)){
			cout << "Ошибка!\n";
			return 1;
		}
		return 0;
	}
	if(command == "-rw"){
		if(args.size()<4){
			cliedit::show_command_manual("rw");
			return 1;
		}
		fstream file(filename,ios::out | ios::trunc);
		if(cliedit::write(file,args[3])){
			cout << "Ошибка!\n";
			return 1;
		}
		cout << "Успешно\n";
		return 0;
	}
	if(command == "-a"){
		if(args.size()<4){
			cliedit::show_command_manual("a");
			return 1;
		}
		fstream file(filename,ios::out | ios::app);
		if(cliedit::write(file,args[3])){
			cout << "Ошибка!\n";
			return 1;
		}
		cout << "Успешно\n";
		return 0;
	}
	if(command == "-cp"){
		if(args.size()<4){
			cliedit::show_command_manual("cp");
			return 1;
		}
		fstream file(filename,ios::in);
		if (filename == args[3]) {
			cerr << "Ошибка: исходный и целевой файлы совпадают!" << n;
			return 1;
		}
		fstream file2(args[3],ios::out);
		if(cliedit::copy(file,file2)){
			cout << "Ошибка!\n";
			return 1;
		}
		cout << "Успешно\n";
		return 0;
	}
	if(command == "-p"){
		if(args.size()<5){
			cliedit::show_command_manual("p");
			return 1;
		}
		int byte;
		try{
			byte = stoi(args[3]);
		} catch (invalid_argument& err) {
			cerr << "Некорректный числовой аргумент: " << args[3] << n;
			return 1;
		} catch (out_of_range& err) {
			cerr << "Число вне диапазона: " << args[3] << n;
			return 1;
		}
		if(cliedit::paste(filename,args[4],byte)){
			cout << "Ошибка!\n";
			return 1;
		}
		cout << "Успешно\n";
		return 0;
	}
	if(command == "-e"){
		if(args.size() < 5){
			cliedit::show_command_manual("e");
			return 1;
		}
		int start,count;
		try{
			start = stoi(args[3]);
		} catch (invalid_argument& err) {
			cerr << "Некорректный числовой аргумент: " << args[3] << n;
			return 1;
		} catch (out_of_range& err) {
			cerr << "Число вне диапазона: " << args[3] << n;
			return 1;
		}
		try{
			count = stoi(args[4]);
		} catch (invalid_argument& err) {
			cerr << "Некорректный числовой аргумент: " << args[4] << n;
			return 1;
		} catch (out_of_range& err) {
			cerr << "Число вне диапазона: " << args[4] << n;
			return 1;
		}
		if(cliedit::erase(filename,start,count)){
			cout << "Ошибка!\n";
			return 1;
		}
		cout << "Успешно\n";
		return 0;
	}
	if(command == "-f"){
		if(args.size()<4){
			cliedit::show_command_manual("f");
			return 1;
		}
		fstream file(filename,ios::in);
		if(cliedit::search(file,args[3])){
			cout << "Ошибка!\n";
			return 1;
		}
		return 0;
	}
	else{
		cliedit::show_manual();
		return 1;
	}
}
	
