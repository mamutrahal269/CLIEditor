#pragma once
#include <iostream>
#include <fstream>
#include <string>
namespace editor{
	
	class File_mutator{
		std::fstream file;
		std::string file_name;
		public:
		
		explicit File_mutator(const std::string filename);
		explicit File_mutator(const std::string filename,std::ios::openmode mode);
		~File_mutator() noexcept;
		File_mutator(const File_mutator&) =delete;
		File_mutator& operator=(const File_mutator&) =delete;
		File_mutator() =delete;
		
		void open_file(const std::string filename);
		void open_file(const std::string filename,std::ios::openmode mode);
		void write_file(const std::string str);
		void erase_bytes(int start,int count);
		void insert(int byte,const std::string str);
	};
	
}
