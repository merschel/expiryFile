#pragma once
#include <string>
#include <exception>
class Exception : public std::exception {
	private:
		// ********************
		// properties (private)
		// ********************
		
		int exception;
		std::string additionalNote;

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
		
		Exception();
		Exception(int _exception);
		Exception(int _exception, std::string _additionalNote);
		
		// Destructor

		~Exception();

		// Getter
		
		int get_exception();
	
		// Setter 
		
			// not needed for this class

		// other functions
		
		std::string to_string();
		
		
};

