#pragma once
#include <list>
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
		void remove(int id);
		void remove();
		void add(std::string path, Date expiry_date, std::string modus);
		std::list<TempFile>::iterator find(Hash hash);
		bool isFileInList(std::string path);
		void findExpiredFile();
		bool deleteFile();
};
