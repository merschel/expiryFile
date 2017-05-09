#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
#include "hl_md5wrapper.h"
#include "hl_md5.h"
#include "hl_hashwrapper.h"

class Hash{
	private:
		// ********************
		// properties (private)
		// ********************
		
		std::string hash;
		
		// *****************
		// methods (private)
		// *****************
		
	public:
		
		// *******************
		// properties (public)
		// *******************
		
		// note needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		
		Hash();
		Hash(std::string path);
		
		// Destructor
		~Hash();
		
		// Getter
		std::string to_string();
		
		// Setter 
		
		void set_hash(std::string _hash);

		// other functions
		bool compare(Hash _hash);
};
