#pragma once
#include <string>
class Exception{
	private:
		// ********************
		// properties (private)
		// ********************
		
		int exception;

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
		
		// Destructor

		~Exception();

		// Getter
		
		int get_exception();
	
		// Setter 
		
			// not needed for this class

		// other functions
		
		std::string to_string();
		
		
};

