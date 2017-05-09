#include "stdafx.h"
#include "Exception.h"
#include "defVar.h"
#include <string>
#include <sstream>

// *****************
// methods (private)
// *****************

	// not needed for this class
			
// ****************
// methods (public)
// ****************
		
// Constructor

Exception::Exception(){
}

Exception::Exception(int _exception){
	exception = _exception;
}
		
// Destructor

Exception::~Exception(){
}

// Getter
	
int Exception::get_exception(){
	return exception;
}
	
// Setter 
		
	// not needed for this class

// other functions
		
std::string Exception::to_string() {
	std::stringstream ess;
	switch (exception) {
	case 0:
		ess << PROG_NAME << ": Miss some parameter." << std::endl;
		return ess.str();
	case 1:
		ess << PROG_NAME << ": Expiry date is not valid." << std::endl;
		return ess.str();
	case 2:
		ess << PROG_NAME << ": The value for -m is not allowed." << std::endl;
		return ess.str();
	case 3:
		ess << PROG_NAME << ": You use unknown parameter. Type -h for more help." << std::endl;
		return ess.str();
	case 4:
		ess << PROG_NAME << ": Unable to open file " << LIST_NAME << std::endl;
		return ess.str();
	case 5:
		ess << PROG_NAME << ": Unable to save file " << LIST_NAME << std::endl;
		return ess.str();
	case 6:
		ess << PROG_NAME << ": Hash is not in the List " << LIST_NAME << std::endl;
		return ess.str();
	default:
		return "A unspecific error occurred!";
	}
}
