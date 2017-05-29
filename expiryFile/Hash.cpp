#include "stdafx.h"
#include "Hash.h"
#include <string>
#include "Exception.h"
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

void Hash::compute(std::string path){
	// calc the md5 hash 
	hashwrapper *hw = new md5wrapper();
	try {
		hash = hw->getHashFromFile(path);
	}
	catch (hlException e) {
		throw Exception(8);
	}
}

