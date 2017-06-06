#pragma once
#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

class ExpiryDate{
	private:
		// ********************
		// properties (private)
		// ********************
		
		time_t expiryDate;
		bool valid;
		
		// *****************
		// methods (private)
		// *****************

			// not needed in this file

	public:
		
		// *******************
		// properties (public)
		// *******************
		
			// not needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		ExpiryDate();
		
		// Destructor
		~ExpiryDate();
		
		// Getter
		time_t get_expiryDate();
		
		// Setter 
		void set_expiryDate(std::string _expiryDate);
		
		// other functions
		bool isValid();
		std::string to_string();
		void ExpiryDate::extractTime(std::string str, char s);
		bool ExpiryDate::isDateInFuture();
};
