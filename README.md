# CLIEditor - Консольный редактор файлов

![C++](https://img.shields.io/badge/C++-17-blue?logo=cplusplus)
![License](https://img.shields.io/badge/License-MIT-green)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey)

Простой консольный редактор файлов с поддержкой различных операций.

## Возможности

- Чтение файлов с отображением размера
- Перезапись и дополнение файлов
- Копирование файлов
- Вставка и удаление текста по байтовому смещению
- Поиск текста в файле
- Цветной вывод ошибок и подсказок

## Установка

### Требования
- Компилятор C++17 (g++, clang, MSVC)
- CMake 3.10+

### Сборка
```bash
git clone https://github.com/mamutrahal269/CLIEditor.git
cd CLIEditor
mkdir build && cd build
cmake ..
make