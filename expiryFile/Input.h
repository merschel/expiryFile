#pragma once
#include <string>
#include "Date.h"
#include <iostream>
class Input{
	private:
		// ********************
		// properties (private)
		// ********************
		
		int argc;
		char **argv;
		
		std::string path;
		Date expiry_date;
		std::string modus;
		bool ok;
		
		char prog_mode;
		
		// *****************
		// methods (private)
		// *****************

		// check whether all nessesary parameter are passed by. 
		
			// not needed in this class
		
	public:
		
		// *******************
		// properties (public)
		// *******************
		
			// not needed in this file
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		
		Input();
		
		// Destructor

		~Input();

		// Getter
		
		std::string get_path();
		Date get_expiry_date();
		std::string get_modus();
		bool isValid();
		char get_prog_mode();
		// Setter 
		
		void set_input(int _argc,char **_argv);
		
		// other functions
		
		void extract_prog_mode();
		void extract_input_values();
};
