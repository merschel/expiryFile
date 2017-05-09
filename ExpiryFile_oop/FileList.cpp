#include "stdafx.h"
#include "defVar.h"
#include "FileList.h"
#include "Exception.h"
#include <iostream>

// *****************
// methods (private)
// *****************

	// not needed for this class
				
// ****************
// methods (public)
// ****************
		
// Constructor

FileList::FileList(){}

// Destructor

FileList::~FileList(){}

// Getter
	
std::list<TempFile> FileList::get_fileList() {
	return fileList;
}
	
// Setter 
		
	// not needed for this class

// other functions
		
// open the list file and write the list in a list of tempFile objects
void FileList::load() {
	std::string hash_string, path, expiry_date_string, modus, line;
	std::ifstream file(LIST_NAME);
	if (file.is_open()) {
		std::list<TempFile>::iterator it = fileList.begin();
		while (getline(file, line)) { //go through the file 
			Hash hash;
			Date expiry_date;
			std::istringstream ss(line);   // in the file: hash, path, date, modus
			getline(ss, hash_string, LIST_DELIMITER);
			getline(ss, path, LIST_DELIMITER);
			getline(ss, expiry_date_string, LIST_DELIMITER);
			getline(ss, modus, LIST_DELIMITER);
			hash.set_hash(hash_string);
			expiry_date.set_date(expiry_date_string);
			TempFile tempFile(hash, path, expiry_date, modus);
			fileList.push_back(tempFile);
		}
		file.close();
	}
	else {
		throw Exception(4);
	}
}

//This function save the list in a file LIST_NAME.
// return true if successful saved, ohterwise false
void FileList::save() {
	std::list<TempFile>::iterator it;
	std::ofstream file(LIST_NAME);
	if (file.is_open()) {
		for (it = fileList.begin(); it != fileList.end(); it++) {
			TempFile tempFile = *it;
			file << tempFile.get_hash().to_string() << LIST_DELIMITER
				 << tempFile.get_path() << LIST_DELIMITER
				 << tempFile.get_expiry_date().to_string() << LIST_DELIMITER
				 << tempFile.get_modus() << std::endl;
		}
		file.close();
	}
	else {
		throw Exception(5);
	}
}

void FileList::print() {
	std::list<TempFile>::iterator it;
	std::cout << std::endl;
	std::cout << "List Mode" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << std::endl;
	std::cout << "| Hash                             | expiry date | modus | path + file " << std::endl;
	std::cout << "|----------------------------------------------------------------------" << std::endl;
	for (it = fileList.begin(); it != fileList.end(); it++) { // print the list to the screen
		TempFile tempFile = *it;
		std::cout << "| " << tempFile.get_hash().to_string()
			      << " | " << tempFile.get_expiry_date().to_string()
			      << "  |   " << tempFile.get_modus() 
			      << "   | " << tempFile.get_path() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------" << std::endl;
}



void FileList::add(std::string path, Date expiry_date, std::string modus) {
	TempFile tempFile(path, expiry_date, modus);
	fileList.push_back(tempFile);
}

void FileList::remove(Hash hash) {
	try{
		std::list<TempFile>::iterator it = find(hash);
		fileList.erase(it);
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
	}
	/*std::list<TempFile>::iterator it;
	//go thought list and check whether the hash exists in the list
	for (it = fileList.begin(); it != fileList.end(); it++) {
		TempFile tempFile = *it;
		if (tempFile.get_hash().compare(hash)) {
			fileList.erase(it++);
			std::cout << "removed file with the hash " << hash.to_string() << std::endl;
			return;
		}
	}*/
	//std::cerr << "The hash " << hash << " not found!" << std::endl;
}

/*
void listMode() {
std::string path, expiry_date, modus;
std::list<tempFile> tfList = loadList(); // load the list
listMode_printList(tfList); // print list

// what's next? remove a file from the list or quit?
std::cout << "Type r for remove or q for quit." << std::endl;
std::cout << std::endl;
switch (getche()) {
case 'r':
std::cout << std::endl;
listMode_r(tfList);
return;
default:
std::cout << std::endl;
return;
}
}

void listMode_r(std::list<tempFile> tfList) {
std::string hash;

std::cout << "hash?" << std::endl;
std::cin >> hash;

removeFileFromList(tfList, hash);

}
*/


// go through the list and compare the md5 hashs
// with the md5 hash from the given file.
// return true if the hash was found, otherwise false.
/*int FileList::existInList(std::string path, std::list<tempFile> tfList) {
std::list<tempFile>::iterator it;
std::string hash = calcHash(path);
for (it = tfList.begin(); it != tfList.end(); it++) {
tempFile tf = *it;
if (hash == tf.hash) {
return true;
}
}
return false;
}*/

std::list<TempFile>::iterator FileList::find(Hash hash) {
	std::list<TempFile>::iterator it;
	for (it = fileList.begin(); it != fileList.end(); it++) {
		TempFile tempFile = *it;
		if (tempFile.get_hash().compare(hash)) {
			return it;
		}
	}
	throw Exception(6);
}

