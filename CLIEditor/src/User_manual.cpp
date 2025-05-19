#include "../include/User_manual.hpp"
#include <iostream>
using namespace std;
#define NL '\n'
void cliedit::show_manual(){
	cout << "Использование:" << NL <<
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
void cliedit::show_command_manual(string command){
	if(command == "rd"){
		cout << "Использование команды rd: " << NL <<
		"./programm file.name -rd" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -rd\n(чтение файла log.txt из текущей директории,программа сообщит,если файл отсутсвует" << NL;
		return;
	}
	if(command == "rw"){
		cout << "Использование команды rw:" << NL <<
		"./programm file.name -rw \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -rw \"Был перезаписан файл\"\n(перезапись файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "a"){
		cout << "Использование команды a:" << NL <<
		"./programm file.name -a \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -a \"Добавлено в конец\"\n(добавление текста в конец файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "cp"){
		cout << "Использование команды cp:" << NL <<
		"./programm file.name -cp file2.name" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -cp doc.txt\n(копирование из файла log.txt в файл doc.txt из текущей директории,программа сообщит"
		",если файл(тут log.txt) отсутсвует)" << NL;
		return;
	}
	if(command == "p"){
		cout << "Использование команды p:" << NL <<
		"./programm file.name -p байт \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -p 2 \"вставленный текст\"\n(вставка текста после 2 байта файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "e"){
		cout << "Использование команды e:" << NL <<
		"./programm file.name -e начальный_байт количество_байт" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -e 2 3\n(удаление 2-5 байт из файла log.txt из текущей директории)" << NL;
		return;
	}
	if(command == "f"){
		cout << "Использование команды f:" << NL <<
		"./programm file.name -f \"текст\"" << NL <<
		"Пример:" << NL <<
		"./CLIEditor log.txt -f \"искать\"\n(поиск начала и конца строки в файле log.txt из текущей директории)" << NL;
		return;
	}
	else{
		cout << "Команда не существует" << NL;
		return;
	}
}
