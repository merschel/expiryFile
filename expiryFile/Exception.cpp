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
	additionalNote = "";
}
		
Exception::Exception(int _exception, std::string _additionalNote) {
	exception = _exception;
	additionalNote = _additionalNote;
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
		break;
	case 1:
		ess << PROG_NAME << ": Expiry date is not valid." << std::endl;
		break;
	case 2:
		ess << PROG_NAME << ": The value for -m is not allowed." << std::endl;
		break;
	case 3:
		ess << PROG_NAME << ": You use unknown parameter. Type -h for more help." << std::endl;
		break;
	case 4:
		ess << PROG_NAME << ": Unable to open file " << LIST_NAME << std::endl;
		break;
	case 5:
		ess << PROG_NAME << ": Unable to save file " << LIST_NAME << std::endl;
		break;
	case 6:
		ess << PROG_NAME << ": Hash is not in the List " << LIST_NAME << std::endl;
		break;
	case 7:
		ess << PROG_NAME << ": File does not exist." << std::endl;
		break;
	case 8:
		ess << PROG_NAME << ": The md5 sum of this file can not be calculated!" << std::endl;
		break;
	case 9:
		ess << PROG_NAME << ": File is already in the list." << std::endl;
		break;
	case 10:
		ess << PROG_NAME << ": Id not in the list." << std::endl;
		break;
	case 11:
		ess << PROG_NAME << ": ." << std::endl;
		break;
	default:
		return "A unspecific error occurred!";
	}

	ess << std::endl;
	ess << additionalNote << std::endl;

	return ess.str();
}
