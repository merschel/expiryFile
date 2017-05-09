#include "stdafx.h"
#include "Hash.h"
#include <string>
// *****************
// methods (private)
// *****************
		
// not needed for this class

// ****************
// methods (public)
// ****************
	
// Constructor

Hash::Hash(){
	hash = "";
}

Hash::Hash(std::string path) {
	// calc the md5 hash 
	hashwrapper *hw = new md5wrapper();
	try {
		hash = hw->getHashFromFile(path);
		std::cout << "hash in Hash: " << hash << std::endl;
	}
	catch (hlException &e) {
		std::cerr << "The md5 sum of this file can not be calculated!" << std::endl;
		//std::cerr << e << std::endl;
		hash = "";
	}
}

// Destructor

Hash::~Hash(){
}

// Getter

std::string Hash::to_string(){
	return hash;
}

// Setter 
		
void Hash::set_hash(std::string _hash) {
	hash = _hash;
}
		
// other functions

bool Hash::compare(Hash _hash){
	return hash == _hash.to_string();
}

