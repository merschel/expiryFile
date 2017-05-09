#include "stdafx.h"

#include <list>
#include <ctime>
#include <iostream>
#include <conio.h>
#include "fileList.h"
#include "date.h"
#include "calcHash.h"

bool deleteFile(std::string path, std::string hash);

//#include "tempFile.h"
void checkMode() {

	std::list<tempFile>::iterator it;

	// load the list
	std::list<tempFile> tfList = loadList();

	// get the current date
	time_t now = time(NULL);

	// go through the list and 
	for (it = tfList.begin(); it != tfList.end(); it++) {
		tempFile tf = *it;
		if (!isDateInFuture(mktime(&date2struct(tf.expiry_date)))) {
			//check whether file exist 
			if (!existFile(tf.path)) {
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << " -> The file " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.path << std::endl;
				std::cout << std::endl;
				std::cout << "    with the hash " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.hash << std::endl;
				std::cout << std::endl;
				std::cout << "    do not exist anymore." << std::endl;
				std::cout << std::endl;
				std::cout << "    Expiry date: " << tf.expiry_date << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "    Remove from list now? (y/n) ";
				//std::cin >> kbin;
				if (getche() == 'y') {
					it = tfList.erase(it);
					it--;
					//removeFileFromList(tfList, tf.hash);
				}
				break;
			}

			switch (std::stoi(tf.modus)) {
			case 0: // delete the file
				if (!deleteFile(tf.path, tf.hash)) {
					std::cerr << "can not delete the file " << tf.path << std::endl;
				}
				else {
					//removeFileFromList(tfList, tf.hash);
					it = tfList.erase(it);
					it--;
				}
				break;
			case 1: // delete the file and print a note
				if (!deleteFile(tf.path, tf.hash)) {
					std::cerr << "can not delete the file " << tf.path << std::endl;
				}
				else{
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << " -> The file " << std::endl;
					std::cout << std::endl;
					std::cout << "      " << tf.path << std::endl;
					std::cout << std::endl;
					std::cout << "    with the hash " << std::endl;
					std::cout << std::endl;
					std::cout << "      " << tf.hash << std::endl;
					std::cout << std::endl;
					std::cout << "    has been deleted." << std::endl;
					std::cout << std::endl;
					std::cout << "    Expiry date: " << tf.expiry_date << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					it = tfList.erase(it);
					it--;
					std::cout << "    Press return to go further ";
					getchar();
				}
				break;
			case 2: // delete the file but first ask for permission
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << " -> The file " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.path << std::endl;
				std::cout << std::endl;
				std::cout << "    with the hash " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.hash << std::endl;
				std::cout << std::endl;
				std::cout << "    is registered for delete." << std::endl;
				std::cout << std::endl;
				std::cout << "    Expiry date: " << tf.expiry_date << std::endl;
				std::cout << std::endl;
				std::cout << "    Delete now? (y/n) ";
				//std::cin >> kbin;
				if (getche() == 'y'){
					if (!deleteFile(tf.path, tf.hash)) {
						std::cerr << "can not delete the file " << tf.path << std::endl;
					}
					else {
						std::cout << "222222" << std::endl;
						it = tfList.erase(it);
						it--;
					}
				}
				std::cout << std::endl;
				std::cout << std::endl;
				break;
			case 3: // just inform the user that the file still exist
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << " -> The file " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.path << std::endl;
				std::cout << std::endl;
				std::cout << "    with the hash " << std::endl;
				std::cout << std::endl;
				std::cout << "      " << tf.hash << std::endl;
				std::cout << std::endl;
				std::cout << "    still exist." << std::endl;
				std::cout << std::endl;
				std::cout << "    Expiry date: " << tf.expiry_date << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << "    Press return to go further ";
				getchar();
				break;
			default: // something is wrong!
				return;
			}
		}
	}
	if (!saveList(tfList)) {
		std::cerr << "can not save file!" << std::endl;
	}
}

bool deleteFile(std::string path, std::string hash) {
	// check whether the given file have the same hash like the file in the list.
	if (hash == calcHash(path)) { 
		if (std::remove(path.c_str()) == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

