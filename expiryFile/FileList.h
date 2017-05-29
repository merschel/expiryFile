#pragma once
#include <list>
#include <vector>
#include "TempFile.h"
class FileList{
	private:
		// ********************
		// properties (private)
		// ********************
		
		std::list<TempFile> fileList;
		std::list<TempFile>::iterator it;
		
		// *****************
		// methods (private)
		// *****************

			// not needed for this class
		
	public:
		
		// *******************
		// properties (public)
		// *******************
		
			// not needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		
		FileList();

		// Destructor

		~FileList();

		// Getter
		
		std::list<TempFile> get_list();
		std::list<TempFile>::iterator get_iterator();
		
		// Setter 
		
			// not needed for this class

		// other functions
		
		void load();
		void save();
		void print();
		void remove(unsigned int id);
		void remove();
		void add(std::string path, Date expiry_date, std::string modus);
		std::list<TempFile>::iterator find(Hash hash);
		bool isFileInList(std::string path);
		bool deleteFile();
		void SearchAndTreat();
		bool existsFile(std::string path);
		void check_Mode_0(TempFile tempFile);
		void check_Mode_1(TempFile tempFile);
		void check_Mode_2(TempFile tempFile);
		void check_Mode_3(TempFile tempFile);
		void check_Mode_massage(TempFile tempFile, std::string text);
};
