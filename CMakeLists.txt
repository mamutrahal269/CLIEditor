cmake_minimum_required(VERSION 3.10)
project(CLIEditor2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CLIEditor2
    src/main.cpp
    src/File_readonly.cpp
    src/File_mutator.cpp
    src/User_help.cpp
)
