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
	Hash hash;
	fileList.load();
	fileList.findExpiredFile();
	std::list<TempFile>::iterator it = fileList.get_iterator();
	while(it != fileList.get_list().end()){
		std::cout << "7" << std::endl;
		TempFile tempFile = *it;
		std::cout << "8" << std::endl;
		std::cout << tempFile.get_path() << std::endl;
		// check whether the file still exist
		if (!existsFile(tempFile.get_path())) {
			check_Mode_massage(tempFile, "do not exist anymore.");
			std::cout << "    Remove from list now? (y/n) ";
			if (getche() == 'y') {
				fileList.remove();
			}
		}

		// check whether the file has change
		hash.compute(tempFile.get_path());
		if( !tempFile.get_hash().compare(hash) ){ // If the file has change do not delete it
			check_Mode_massage(tempFile, "has changed.");
			std::cout << "    Remove from list now? (y/n) ";
			if (getche() == 'y') {
				fileList.remove();
			}
		}

		switch (*tempFile.get_modus().c_str()){
		case '0':
			check_Mode_0(fileList, tempFile);
		case '1':
			check_Mode_1(fileList, tempFile);
		case '2':
			check_Mode_2(fileList, tempFile);
		case '3':
			check_Mode_3(fileList, tempFile);
		default:
			throw Exception(2);
		}
		fileList.findExpiredFile();
		it = fileList.get_iterator();
	}
	fileList.save(); 
}

void Start::check_Mode_0(FileList fileList, TempFile tempFile) {
	if (fileList.deleteFile()) {
		fileList.remove();
	}
	else {
		std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
	}
}

void Start::check_Mode_1(FileList fileList, TempFile tempFile) {
	if (fileList.deleteFile()) {
		fileList.remove();
		check_Mode_massage(tempFile, "has deleted.");
	}
	else {
		std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
	}
}

void Start::check_Mode_2(FileList fileList, TempFile tempFile) {
	check_Mode_massage(tempFile, "is registered for delete.");
	std::cout << "    Delete File and remove from list now? (y/n) ";
	if (getche() == 'y') {
		if (fileList.deleteFile()) {
			fileList.remove();
		}
		else {
			std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
		}
	}
}

void Start::check_Mode_3(FileList fileList, TempFile tempFile) {
	check_Mode_massage(tempFile, "still exist.");
	std::cout << "    Press any key to go further! ";
	getche();
}

bool Start::existsFile(std::string path) {
	std::ifstream ifs(input.get_path());
	if (ifs.fail()) {
		return false;
	}
	else {
		ifs.close();
		return true;
	}
}

void Start::check_Mode_massage(TempFile tempFile, std::string text) {
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << " -> The file " << std::endl;
	std::cout << std::endl;
	std::cout << "      " << tempFile.get_path() << std::endl;
	std::cout << std::endl;
	std::cout << "    with the hash " << std::endl;
	std::cout << std::endl;
	std::cout << "      " << tempFile.get_hash().to_string() << std::endl;
	std::cout << std::endl;
	std::cout << "    " << text << std::endl;
	std::cout << std::endl;
	std::cout << "    Expiry date: " << tempFile.get_expiry_date().to_string() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}