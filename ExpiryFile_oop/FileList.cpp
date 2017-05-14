#include "stdafx.h"
#include "defVar.h"
#include "FileList.h"
#include "Exception.h"
#include <iostream>
#include "Input.h"
#include <math.h>  
#include <conio.h>
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
	
std::list<TempFile> FileList::get_list() {
	return fileList;
}
	
std::list<TempFile>::iterator FileList::get_iterator(){
	return it;
}	

// Setter 
		
	// not needed for this class

// other functions
		
// open the list file and write the list in a list of tempFile objects
void FileList::load() {
	std::string hash_string, path, expiry_date_string, modus, line;
	std::ifstream file(LIST_NAME);
	if (file.is_open()) {
		Hash hash;
		Date expiry_date;
		while (getline(file, line)) { //go through the file 
			std::istringstream ss(line);   // in the file: hash, path, date, modus
			getline(ss, hash_string, LIST_DELIMITER);
			getline(ss, path, LIST_DELIMITER);
			getline(ss, expiry_date_string, LIST_DELIMITER);
			getline(ss, modus, LIST_DELIMITER);
			hash.set_hash(hash_string);
			expiry_date.set_date(expiry_date_string);
			TempFile tempFile(hash, path, expiry_date, modus);    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Vieleicht auslagern
			fileList.push_back(tempFile);
		}
		file.close();
		it = fileList.begin();
	}
	else {
		throw Exception(4);
	}
}

//This function save the list in a file LIST_NAME.
// return true if successful saved, ohterwise false
void FileList::save() {
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
	int id = 1;
	int s = fileList.size();
	int m = (s == 0) ? 1 : floor(log10(s)) + 1;
		
	std::cout << std::endl;
	std::cout << "List Mode" << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << std::endl;
	std::cout << "| ID"<< std::string(m - 1,' ') <<"| Hash                             | expiry date | modus | path + file " << std::endl;
	std::cout << "|---------------------------------------------------------------------------" << std::endl;
	
	for (it = fileList.begin(); it != fileList.end(); it++, id++) { // print the list to the screen
		TempFile tempFile = *it;
		std::cout << "| " << std::string(m-(floor(log10(id)) + 1),' ') << id
				  << " | " << tempFile.get_hash().to_string()
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

void FileList::remove(int id) {
	if(id <= 0 || id > fileList.size()){
		throw Exception(10);
	}
	it = fileList.begin();
	std:advance(it,id-1);
	fileList.erase(it);
}

void FileList::remove() {
	it = fileList.erase(it);
}

std::list<TempFile>::iterator FileList::find(Hash hash) {
	for (it = fileList.begin(); it != fileList.end(); it++) {
		TempFile tempFile = *it;
		if (tempFile.get_hash().compare(hash)) {
			return it;
		}
	}
	throw Exception(6);
}

bool FileList::isFileInList(std::string path){
	Hash hash;
	hash.compute(path);
	for (it = fileList.begin(); it != fileList.end(); it++) {
		TempFile tempFile = *it;
		if (tempFile.get_hash().compare(hash) && tempFile.get_path() == path ){
			return true;
		}
	}
	return false;
}

bool FileList::deleteFile() {
	TempFile tempFile = *it;
	if (std::remove( tempFile.get_path().c_str() ) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void FileList::SearchAndTreat() {
	Hash hash;
	//for (it = fileList.begin(); it != fileList.end(); it++) {
	while (it != fileList.end()) {
		TempFile tempFile = *it;
		if (!tempFile.get_expiry_date().isDateInFuture()) { // find a rooten file int the list
			
			// check whether the file still exist
			if (!existsFile(tempFile.get_path())) {
				check_Mode_massage(tempFile, "do not exist anymore.");
				std::cout << "    Remove from list now? (y/n) ";
				if (getche() == 'y') {
					remove();
					continue;
				}
			}

			// check whether the file has change
			hash.compute(tempFile.get_path());
			if (!tempFile.get_hash().compare(hash)) { // If the file has change do not delete it
				check_Mode_massage(tempFile, "has changed.");
				std::cout << "    Remove from list now? (y/n) ";
				if (getche() == 'y') {
					remove();
					continue;
				}
			}

			switch (*tempFile.get_modus().c_str()) {
			case '0':
				check_Mode_0(tempFile);
				break;
			case '1':
				check_Mode_1(tempFile);
				break;
			case '2':
				check_Mode_2(tempFile);
				break;
			case '3':
				check_Mode_3(tempFile);
				break;
			default:
				throw Exception(2);
			}

		}
	}
}

bool FileList::existsFile(std::string path) {
	std::ifstream ifs(path);
	if (ifs.fail()) {
		return false;
	}
	else {
		ifs.close();
		return true;
	}
}

void FileList::check_Mode_0(TempFile tempFile) {
	if (deleteFile()) {
		remove();
	}
	else {
		std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
		it++;
	}
}

void FileList::check_Mode_1(TempFile tempFile) {
	if (deleteFile()) {
		remove();
		check_Mode_massage(tempFile, "has deleted.");
	}
	else {
		std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
		it++;
	}
}

void FileList::check_Mode_2(TempFile tempFile) {
	check_Mode_massage(tempFile, "is registered for delete.");
	std::cout << "    Delete File and remove from list now? (y/n) ";
	if (getche() == 'y') {
		if (deleteFile()) {
			remove();
		}
		else {
			std::cerr << "can not delete the file " << tempFile.get_path() << std::endl;
			it++;
		}
	}
}

void FileList::check_Mode_3(TempFile tempFile) {
	check_Mode_massage(tempFile, "still exist.");
	std::cout << "    Press any key to go further! ";
	getche();
	it++;
}



void FileList::check_Mode_massage(TempFile tempFile, std::string text) {
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