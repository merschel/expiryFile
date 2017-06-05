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

TempFile::TempFile(Hash _hash, std::string _path, ExpiryDate _expiryDate, std::string _modus) {
	hash = _hash;
	path = _path;
	expiryDate = _expiryDate;
	modus = _modus;
}

TempFile::TempFile(std::string _path, ExpiryDate _expiryDate, std::string _modus) {
	hash.compute(_path);
	path = _path;
	expiryDate = _expiryDate;
	modus = _modus;
}
		
// Destructor

TempFile::~TempFile(){
};

// Getter
	
Hash TempFile::get_hash(){
	return hash;
}

ExpiryDate TempFile::get_expiryDate(){
	return expiryDate;
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





