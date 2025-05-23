#pragma once
#include <iostream>
#include <string>

inline void error(std::string what){std::cerr << "\033[1;31m[X] Ошибка: \033[0m" << "\033[91m" << what << "\033[0m" << std::endl;}
inline void warning(std::string what){std::cout << "\033[1;33m[!] Предупреждение: \033[0m" << "\033[93m" << what << "\033[0m" << std::endl;}
inline void help(std::string what){std::cout << "\033[1;34m[?] Подсказка: \033[0m" << "\033[94m" << what << "\033[0m" << std::endl;}
inline void seccess(){std::cout << "\033[1;32m[+] Успешно\033[0m" << std::endl;}
