#pragma once
#include "Color_output.hpp"
#include <iostream>
#include <string>
const char NL = '\n';
namespace editor{
inline void user_help(){
	std::cout << "Использование:" << NL <<
	"| Чтение: ./programm file.name -rd" << NL <<
	"| Перезапись: ./programm file.name -rw \"текст\"" << NL <<
	"| Добавление: ./programm file.name -a \"текст\"" << NL <<
	"| Копирование: ./programm file.name -cp file2.name" << NL <<
	"| Вставка: ./programm file.name -p байт \"текст\"" << NL <<
	"| Стереть: ./programm file.name -e начало количество" << NL <<
	"| Поиск: ./programm file.name -f \"текст\"" << NL <<
	"| Справка: ./programm --help" << NL <<
	"| Справка по команде: ./programm --help команда" << NL;
	return;
}
inline void command_help(const std::string command){
	if(command == "rd"){
		std::cout << "Использование команды rd: " << NL <<
		"./programm file.name -rd" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -rd\n(чтение файла log.txt из текущей директории,программа сообщит,если файл отсутсвует" << NL;
		return;
	}
	if(command == "rw"){
		std::cout << "Использование команды rw:" << NL <<
		"./programm file.name -rw \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -rw \"Был перезаписан файл\"\n(перезапись файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "a"){
		std::cout << "Использование команды a:" << NL <<
		"./programm file.name -a \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -a \"Добавлено в конец\"\n(добавление текста в конец файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "cp"){
		std::cout << "Использование команды cp:" << NL <<
		"./programm file.name -cp file2.name" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -cp doc.txt\n(копирование из файла log.txt в файл doc.txt из текущей директории,программа сообщит"
		",если файл(тут log.txt) отсутсвует)" << NL;
		return;
	}
	if(command == "p"){
		std::cout << "Использование команды p:" << NL <<
		"./programm file.name -p байт \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -p 2 \"вставленный текст\"\n(вставка текста после 2 байта файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "e"){
		std::cout << "Использование команды e:" << NL <<
		"./programm file.name -e начальный_байт количество_байт" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -e 2 3\n(удаление 2-5 байт из файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "f"){
		std::cout << "Использование команды f:" << NL <<
		"./programm file.name -f \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -f \"искать\"\n(поиск начала строки в файле log.txt из текущей директории)" << NL;
		return;
	}
	else{
		error("команда не существет");
		return;
	}
}
}
