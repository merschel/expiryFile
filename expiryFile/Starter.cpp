#include "stdafx.h"
#include "Starter.h"
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

Starter::Starter(){}

// Destructor

Starter::~Starter(){}

// Getter
	
	// not needed for this class
	
// Setter 
		
void Starter::set_input(int _argc, char **_argv) {
	argc = _argc;
	argv = _argv;
}

// other functions
		
void Starter::run() {
	switch (extract_prog_mode()) {
	case 'h':  // start the help mode
		help_Mode();
		break;
	case 'l': // start the list mode
		list_Mode();
		break;
	case 'c': // starts the check mode
		check_Mode();
		break;
	case 'n': // everthing is fine goes further with normal mode
		new_Mode();
		break;
	default: // normaly, this sould never happend
		std::cerr << "Something goes horrible wrong!" << std::endl;
	}
}

void Starter::new_Mode(){

	FileList fileList;
	
	extract_input_values();
	
	//load the list
	fileList.load();

	// check whether the file exist
	if (!existsFile(&path)) {
		throw Exception(7);
	}

	// check whether the file is already in the list.
	if(fileList.isFileInList(path)){
		throw Exception(9);
	}
	
	// add the new file to the list
	fileList.add(path, expiry_date, modus);
	
	// save the list in the list.txt file
	fileList.save();
}

void Starter::list_Mode(){
	FileList fileList;

	fileList.load();
	while (true) {
		fileList.print();
		std::cout << "Type r for remove or q for quit." << std::endl;
		std::cout << std::endl;
		switch (_getche()) {
		case 'r':
			try {
				list_Mode_r(&fileList);
			}
			catch (Exception e) {
				std::cout << e.to_string() << std::endl;
			}
			break;
		case 'f':
			list_Mode_f(&fileList);
			break;
		case 's':
			list_Mode_s(&fileList);
			break;
		case 'o':
			list_Mode_o(&fileList);
			break;
		default:
			std::cout << std::endl;
			return;
		}
	}
}

void Starter::list_Mode_r(FileList *fileList){ // remove mode
	int id;
	std::cout << std::endl;
	std::cout << "id?" << std::endl;
	std::cin >> id;
	std::cout << std::endl;
	fileList->remove(id);
	fileList->save();
}

void Starter::list_Mode_f(FileList *fileList){ // filter mode
}

void Starter::list_Mode_s(FileList *fileList){ // search mode
}

void Starter::list_Mode_o(FileList *fileList){ // sort mode
}

void Starter::help_Mode(){
	Help help;
	help.print();
}

void Starter::check_Mode() {
	std::cout << "check mode" << std::endl;
	FileList fileList;
	fileList.load();
	fileList.SearchAndTreat();
	fileList.save();
}

bool Starter::existsFile(std::string *path) {
	std::ifstream ifs(*path);
	if (ifs.fail()) {
		return false;
	}
	else {
		ifs.close();
		return true;
	}
}

char Starter::extract_prog_mode() {
	if (argc == 2 && std::string(argv[1]) == "-h") {// help
		return 'h'; //helpMode
	}
	else if (argc == 2 && std::string(argv[1]) == "-l") {// list
		return 'l'; //listMode
	}
	else if (argc == 2 && std::string(argv[1]) == "-c") {//check
		return 'c';
	}
	else if (argc != 7 && argc != 2) {
		throw Exception(0); // miss some parameter
	}
	else if (argc == 2 && (std::string(argv[1]) != "-h" ||
		std::string(argv[1]) != "-l" ||
		std::string(argv[1]) != "-c")) {
		throw Exception(3); // use wrong parameter
	}
	else {
		return 'n'; // if everything is fine. Start normal mode.
	}

};

void Starter::extract_input_values() {
	for (int i = 1; i < argc; i += 2) {
		if (std::string(argv[i]) == "-p") { // path
			path = std::string(argv[i + 1]);
		}
		else if (std::string(argv[i]) == "-d") { // expiry date
			expiry_date.set_expiryDate(std::string(argv[i + 1]));
			if (!expiry_date.isValid() || !expiry_date.isDateInFuture()) {
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
