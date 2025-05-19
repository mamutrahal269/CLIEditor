cmake_minimum_required(VERSION 3.10)
project(CLIEditor)

add_executable(CLIEditor
    src/main.cpp
    src/File_operations.cpp
    src/File_edit.cpp
    src/User_manual.cpp
)

target_include_directories(CLIEditor PRIVATE include)
