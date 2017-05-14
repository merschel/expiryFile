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

	input.set_input(argc,argv);
	input.extract_prog_mode();

	switch (input.get_prog_mode()) {
	case 'h':  // start the help mode
		help_Mode();
		break;
	case 'l': // start the list mode
		list_Mode();
		break;
	case 'c': // starts the check mode
		check_Mode();
		break;
	case '1': // everthing is fine goes further with normal mode
		new_Mode();
		break;
	default: // normaly, this sould never happend
		std::cerr << "Something goes horrible wrong!" << std::endl;
	}
}

//bool handleFileAndList(input input) {
void Start::new_Mode(){

	FileList fileList;
	
	input.extract_input_values();
	
	//load the list
	fileList.load();

	// check whether the file exist
	if (!existsFile(input.get_path())) {
		throw Exception(7);
	}

	// check whether the file is already in the list.
	if(fileList.isFileInList(input.get_path())){
		throw Exception(9);
	}
	
	// add the new file to the list
	fileList.add(input.get_path(), input.get_expiry_date(), input.get_modus());
	
	// save the list in the list.txt file
	fileList.save();
}

void Start::list_Mode(){
	FileList fileList;

	fileList.load();
	fileList.print();
	std::cout << "Type r for remove or q for quit." << std::endl;
	std::cout << std::endl;
	switch (getche()) {
	case 'r':
		list_Mode_r(&fileList);
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
		break;
	}
}

void Start::list_Mode_r(FileList *fileList){ // remove mode
	int id;
	std::cout << std::endl;
	std::cout << "id?" << std::endl;
	std::cin >> id;
	std::cout << std::endl;
	fileList->remove(id);
	fileList->save();
}

void Start::list_Mode_f(FileList *fileList){ // filter mode
}

void Start::list_Mode_s(FileList *fileList){ // search mode
}

void Start::list_Mode_o(FileList *fileList){ // sort mode
}

void Start::help_Mode(){
	Help help;
	help.print();
}

void Start::check_Mode() {
	std::cout << "check mode" << std::endl;
	FileList fileList;
	fileList.load();
	fileList.SearchAndTreat();
	fileList.save();
}

bool Start::existsFile(std::string path) {
	std::ifstream ifs(path);
	if (ifs.fail()) {
		return false;
	}
	else {
		ifs.close();
		return true;
	}
}