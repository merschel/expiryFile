#include "stdafx.h"
#include "Start.h"
#include "Input.h"
#include "Exception.h"
#include "Help.h"
#include "TempFile.h"
#include "FileList.h"
#include <conio.h>
#include <string>
// *****************
// methods (private)
// *****************

	// not needed for this class
				
// ****************
// methods (public)
// ****************
		
// Constructor

Start::Start(){}

// Destructor

Start::~Start(){}

// Getter
	
	// not needed for this class
	
// Setter 
		
	// not needed for this class

// other functions
		
	// not needed for this class

void Start::handleInput(int argc, char **argv) {
	//Input input;
	Help help;
	FileList fileList;
	std::string hash_string;
	Hash hash;

	input.set_input(argc,argv);
	try {
		input.extract_prog_mode();
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
		return;
	}

	switch (input.get_prog_mode()) {
	case 'h':  // start the help mode
		help.print();
		break;
	case 'l': // start the list mode
		try {
			fileList.load();
		}
		catch (Exception e) {
			std::cerr << e.to_string() << std::endl;
			return;
		}
		fileList.print();
		std::cout << "Type r for remove or q for quit." << std::endl;
		std::cout << std::endl;
		switch (getche()) {
		case 'r':
			std::cout << "hash?" << std::endl;
			std::cin >> hash_string;
			std::cout << std::endl;
			hash.set_hash(hash_string);
			try {
				fileList.remove(hash);
				fileList.save();
			}
			catch (Exception e) {
				std::cerr << e.to_string() << std::endl;
				return;
			}
			break;
		default:
			std::cout << std::endl;
			break;
		}
		break;
	case 'c': // starts the check mode
		break;
	case '1': // everthing is fine goes further with normal mode
		try {
			input.extract_input_values();
			handleFileList();
		}
		catch (Exception e) {
			std::cerr << e.to_string() << std::endl;
		}
		break;
	default: // normaly, this sould never happend
		std::cerr << "Something goes horrible wrong!" << std::endl;
	}
}

//bool handleFileAndList(input input) {
void Start::handleFileList(){
	//load the list
	FileList fileList;
	try{
		fileList.load();
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
	}

	// check whether the file exist
	std::ifstream ifs(input.get_path());
	if (ifs.fail()) {
		std::cerr << input.get_path() << " file does not exists!" << std::endl;
	}
	ifs.close();

	// check whether the file is already in the list.
	try {
		Hash hash(input.get_path());
		fileList.find(hash);
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
	}
	
	// add the new file to the list
	fileList.add(input.get_path(), input.get_expiry_date(), input.get_modus());
	
	// save the list in the list.txt file
	try {
		fileList.save();
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
	}

}