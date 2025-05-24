cmake_minimum_required(VERSION 3.10)
project(CLIEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CLIEditor
    src/main.cpp
    src/File_readonly.cpp
    src/File_mutator.cpp
)
