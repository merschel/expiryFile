#include "stdafx.h"
#include "TempFile.h"

// *****************
// methods (private)
// *****************
		
// not needed for this class

// ****************
// methods (public)
// ****************
	
// Constructor
		
TempFile::TempFile(){
}

TempFile::TempFile(Hash _hash, std::string _path, Date _expiry_date, std::string _modus) {
	hash = _hash;
	path = _path;
	expiry_date = _expiry_date;
	modus = _modus;
}

TempFile::TempFile(std::string _path, Date _expiry_date, std::string _modus) {
	Hash hash(_path);
	std::cout << "hash in TempFile : " << hash.to_string() << std::endl;
	path = _path;
	expiry_date = _expiry_date;
	modus = _modus;
}
		
// Destructor

TempFile::~TempFile(){
};

// Getter
	
Hash TempFile::get_hash(){
	return hash;
}

Date TempFile::get_expiry_date(){
	return expiry_date;
}

std::string TempFile::get_modus(){
	return modus;
}

std::string TempFile::get_path(){
	return path;
}	

// Setter 
		
	// not needed for this class
		
// other functions

	// not needed for this class





