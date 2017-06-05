#pragma once
#include "FileList.h"
class Starter{
	private:
		// ********************
		// properties (private)
		// ********************
		
		int argc;
		char **argv;

		std::string path;
		ExpiryDate expiry_date;
		std::string modus;
		bool ok;

		// *****************
		// methods (private)
		// *****************

		void new_Mode();
		void list_Mode();
		void list_Mode_r(FileList *fileList);
		void list_Mode_f(FileList *fileList);
		void list_Mode_s(FileList *fileList);
		void list_Mode_o(FileList *fileList);
		void check_Mode();
		void help_Mode();
		bool existsFile(std::string *path);

		char extract_prog_mode();
		void extract_input_values();

	public:
		
		// *******************
		// properties (public)
		// *******************
		
			// not needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		
		Starter();

		// Destructor

		~Starter();

		// Getter
		
			// not needed for this class
	
		// Setter 
		
		void set_input(int argc,char **argv);

		// other functions
		
		void run();
};
