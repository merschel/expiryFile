#include "stdafx.h"
#include "defVar.h"
#include "FileList.h"
#include "Exception.h"
#include <iostream>
#include "Input.h"
#include <math.h>  
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
	fileList.erase(it);
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

void FileList::findExpiredFile(){
	time_t now;
	now = time(NULL);
	for(it = fileList.begin(); it != fileList.end(); it++){
		TempFile tempFile = *it;
		if(!tempFile.get_expiry_date().isDateInFuture()){
			return; // leave the the iterator in his position, use get_iterator() 
		}
	}
	it = fileList.end(); // if no rotten file is found
}

bool FileList::deleteFile() {
	TempFile tempFile = *it;
	if (std::remove( tempFile.get_path().c_str() )) {
		return true;
	}
	else {
		return false;
	}
}