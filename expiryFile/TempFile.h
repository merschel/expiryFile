#pragma once
#include "stdafx.h"
#include "Hash.h"
#include "ExpiryDate.h"
#include <string>
class TempFile {
	private:
		
		// ********************
		// properties (private)
		// ********************
		
		Hash hash;
		std::string path;
		ExpiryDate expiryDate;
		std::string modus;
	
		// *****************
		// methods (private)
		// *****************
		
			// not needed for this class
	
	public:
		
		// *******************
		// properties (public)
		// *******************
		
			// not needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		
		TempFile();
		TempFile(Hash _hash, std::string _path, ExpiryDate _expiryDate, std::string _modus);
		TempFile(std::string _path, ExpiryDate _expiryDate, std::string _modus);
		
		// Destructor
		
		~TempFile();
		
		// Getter
		Hash get_hash();
		std::string get_path();
		ExpiryDate get_expiryDate();
		std::string get_modus();
		
		// Setter
		
			// not needed for this class
			
		// other functions
		
			// not needed for this class
};
