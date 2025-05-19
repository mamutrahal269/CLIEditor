cmake_minimum_required(VERSION 3.15)
project(CLIEditor)
set(CMAKE_CXX_STANDART 17)

add_executable(CLIEditor
    src/main.cpp
    src/File_operations.cpp
    src/File_edit.cpp
    src/User_manual.cpp
)

target_include_directories(CLIEditor PRIVATE include)
