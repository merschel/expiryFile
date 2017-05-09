#pragma once
#include "Input.h"
class Start{
	private:
		// ********************
		// properties (private)
		// ********************
		
		Input input;

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
		
		Start();

		// Destructor

		~Start();

		// Getter
		
			// not needed for this class
	
		// Setter 
		
			// not needed for this class

		// other functions
		
		void handleInput(int argc, char **argv);
		void handleFileList();

};
