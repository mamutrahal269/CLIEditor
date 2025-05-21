#pragma once
#include <iostream>
#include <fstream>
#include <string>
namespace editor{
	
	class File_readonly{
		std::ifstream file;
		std::fstream helpfile;
		public:
		
		File_readonly(const std::string filename);
		~File_readonly() noexcept;
		File_readonly(const File_readonly&) =delete;
		File_readonly& operator=(const File_readonly&) =delete;
		File_readonly() =delete;
		
		void open_file(const std::string filename);
		void readfile();
		void search(const std::string str);
		void copyfile(const std::string filename);
	};
	
}
