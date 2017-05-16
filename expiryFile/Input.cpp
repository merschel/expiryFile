#include "stdafx.h"
#include "defVar.h"
#include <string>
#include <iostream>
#include "Input.h"
#include "Exception.h"
// *****************
// methods (private)
// *****************

	// not needed for this class
	
// ****************
// methods (public)
// ****************
		
// Constructor

Input::Input(){
	ok = true;
	path = "";
	modus = "";
	expiry_date.set_date("");
}

// Destructor

Input::~Input(){
}

// Getter
	
Date Input::get_expiry_date(){
	return expiry_date;
}
	
std::string Input::get_modus(){
	return modus;
}
	
std::string Input::get_path(){
	return path;
}
	
bool Input::isValid(){
	return ok;
}
	
char Input::get_prog_mode(){
	return prog_mode;
}

// Setter 
		
void Input::set_input(int _argc,char **_argv){
	argc = _argc;
	argv = _argv;
}

// other functions
		
void Input::extract_prog_mode(){
	if (argc == 2 && std::string(argv[1]) == "-h") {// help
		prog_mode = 'h'; //helpMode
	}
	else if (argc == 2 && std::string(argv[1]) == "-l") {// list
		prog_mode = 'l'; //listMode
	}
	else if (argc == 2 && std::string(argv[1]) == "-c") {//check
		prog_mode = 'c';
	}
	else if (argc != 7 && argc != 2) {
		throw Exception(0); // miss some parameter
	}
	else if (argc == 2 && (std::string(argv[1]) != "-h" ||
						   std::string(argv[1]) != "-l" ||
						   std::string(argv[1]) != "-c")){
		throw Exception(3); // use wrong parameter
	}
	else {
		prog_mode = '1'; // if everything is fine. Start normal mode.
	}
	
};
		
void Input::extract_input_values(){
	for (int i = 1; i < argc; i += 2) {
		if (std::string(argv[i]) == "-p") { // path
			path = std::string(argv[i + 1]);
		}
		else if (std::string(argv[i]) == "-d") { // expiry date
			expiry_date.set_date(std::string(argv[i + 1]));
			if (!expiry_date.isValid()) {
				throw Exception(1); // the given date is nod valid.
			}
		}
		else if (std::string(argv[i]) == "-m") { // modus
			if (std::string(argv[i + 1]) == "0" || std::string(argv[i + 1]) == "1" || std::string(argv[i + 1]) == "2" || std::string(argv[i + 1]) == "3") { // only modus 0,1,2,3 are allowed
				modus = std::string(argv[i + 1]);
			}
			else {
				throw Exception(2); // the given modus is not allowed 
			}
		}
		else {
			throw Exception(3); // if the given parameter is unknown
		}
	}

}
