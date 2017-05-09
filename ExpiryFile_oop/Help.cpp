// header for visual studio
#include "stdafx.h"

#include <iostream>
#include "Help.h"
#include "defVar.h"

// *****************
// methods (private)
// *****************

	// not needed for this class

// ****************
// methods (public)
// ****************

// Constructor

Help::Help(){}

// Destructor

Help::~Help(){}

// Getter

	// not needed for this class

// Setter 

	// not needed for this class

// other functions

void Help::print() {
	std::cout << std::endl;
	std::cout << "Help Mode" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << std::endl;
	std::cout << "|===============================================================|" << std::endl;
	std::cout << "|    | Explanation                | Example                     |" << std::endl;
	std::cout << "|===============================================================|" << std::endl;
	std::cout << "| -p | set the path to the file.  | -p C:/Users/uselessFile.txt |" << std::endl;
	std::cout << "|---------------------------------------------------------------|" << std::endl;
	std::cout << "| -d | set the expiry date.       |                             |" << std::endl;
	std::cout << "|    | use the format: dd.mm.yyyy | -d 20.04.2017               |" << std::endl;
	std::cout << "|---------------------------------------------------------------|" << std::endl;
	std::cout << "| -m | set the modus.             |                             |" << std::endl;
	std::cout << "|    | allowed are:               |                             |" << std::endl;
	std::cout << "|    |  0 delete the file without | -m 0                        |" << std::endl;
	std::cout << "|    |    ask for permission.     |                             |" << std::endl;
	std::cout << "|    |  1 delete the file without | -m 1                        |" << std::endl;
	std::cout << "|    |    ask for permission but  |                             |" << std::endl;
	std::cout << "|    |    informs you.            |                             |" << std::endl;
	std::cout << "|    |  2 ask for permission      | -m 2                        |" << std::endl;
	std::cout << "|    |    before delete the file. |                             |" << std::endl;
	std::cout << "|    |  3 give you a note that    | -m 3                        |" << std::endl;
	std::cout << "|    |    the file still exist.   |                             |" << std::endl;
	std::cout << "|---------------------------------------------------------------|" << std::endl;
	std::cout << "| -h | print the help to screen   |                             |" << std::endl;
	std::cout << "|---------------------------------------------------------------|" << std::endl;
	std::cout << "| -l | open the current list      |                             |" << std::endl;
	std::cout << "|===============================================================|" << std::endl;
	std::cout << std::endl;
	std::cout << "If you want to set a new expiry date to a file ou have to set the" << std::endl;
	std::cout << "first 3 parameter (p,d,m). For instant: " << std::endl;
	std::cout << "   " << PROG_NAME << " -p C:/Users/uselessFile.txt -d 20.04.2017 -m 1" << std::endl;
	std::cout << "The order is not importent!" << std::endl;
	std::cout << std::endl;
}
