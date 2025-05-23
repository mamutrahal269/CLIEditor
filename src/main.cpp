#include "../include/File_readonly.hpp"
#include "../include/File_mutator.hpp"
#include "../include/User_help.hpp"
#include "../include/Color_output.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using namespace editor;
enum ExitCode{
	Success = 0,
	Wrong_Arg,
	Fail
};
int main(int argc,char* argv[]){
	vector<string> args(argv, argv + argc);
	if(args.size() == 2 && args[1] == "--help"){
		user_help();
		return ExitCode::Success;
	}
	if(args.size() == 3 && args[1] == "--help"){
		command_help(args[2]);
		return ExitCode::Success;
	}
	if(args.size()<3){
		warning("неверное число параметров");
		user_help();
		return ExitCode::Wrong_Arg;
	}
	string command = args[2];
	string filename = args[1];
	if(command == "-rd"){
		if(args.size() != 3){
			warning("неверное число параметров");
			command_help("rd");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_readonly file_readonly(filename);
			file_readonly.readfile();
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		return ExitCode::Success;
	}
	if(command == "-rw"){
		if(args.size() != 4){
			warning("неверное число параметров");
			command_help("rw");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_mutator file_mutator(filename,ios::trunc);
			file_mutator << args[3];
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		success();
		return ExitCode::Success;
	}
	if(command == "-a"){
		if(args.size() != 4){
			warning("неверное число параметров");
			command_help("a");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_mutator file_mutator(filename,ios::app);
			file_mutator << args[3];
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		success();
		return ExitCode::Success;
	}
	if(command == "-cp"){
		if(args.size() != 4){
			warning("неверное число параметров");
			command_help("cp");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_readonly file_readonly(filename);
			file_readonly.copyfile(args[3]);
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		success();
		return ExitCode::Success;
	}
	if(command == "-p"){
		if(args.size() != 5){
			warning("неверное число параметров");
			command_help("p");
			return ExitCode::Wrong_Arg;
		}
		int byte;
		try{
			byte = stoi(args[3]);
		}catch (invalid_argument& err) {
			error("неверный параметр");
			help("сначала число потом строка");
			return ExitCode::Wrong_Arg;
		} catch (out_of_range& err) {
			error("неверный параметр");
			help("можно указывать только числа не более 2147483647");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_mutator file_mutator(filename);
			file_mutator.insert(byte,args[4]);
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		success();
		return ExitCode::Success;
	}
	if(command == "-e"){
		if(args.size() != 5){
			warning("неверное число параметров");
			command_help("e");
			return ExitCode::Wrong_Arg;
		}
		int start,count;
		try{
			start = stoi(args[3]);
			count = stoi(args[4]);
		}catch (invalid_argument& err) {
			error("неверный параметр");
			help("можно указывать только числа");
			return ExitCode::Wrong_Arg;
		} catch (out_of_range& err) {
			error("неверный параметр");
			help("можно указывать только числа не более 2147483647");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_mutator file_mutator(filename);
			file_mutator.erase_bytes(start,count);
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		success();
		return ExitCode::Success;
	}
	if(command == "-f"){
		if(args.size() != 4){
			warning("неверное число параметров");
			command_help("f");
			return ExitCode::Wrong_Arg;
		}
		try{
			File_readonly file_readonly(filename);
			file_readonly.search(args[3]);
		}catch(runtime_error& err){
			error(err.what());
			return ExitCode::Fail;
		}
		return ExitCode::Success;
	}
	else{
		user_help();
		return ExitCode::Wrong_Arg;
	}
}
