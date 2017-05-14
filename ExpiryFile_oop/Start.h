#pragma once
#include "Input.h"
#include "FileList.h"
class Start{
	private:
		// ********************
		// properties (private)
		// ********************
		
		Input input;

		// *****************
		// methods (private)
		// *****************

		void new_Mode();
		void list_Mode();
		void list_Mode_r(FileList *fileList);
		void list_Mode_f(FileList *fileList);
		void list_Mode_s(FileList *fileList);
		void list_Mode_o(FileList *fileList);
		void check_Mode();
		void help_Mode();
		void check_Mode_0(FileList fileList, TempFile tempFile);
		void check_Mode_1(FileList fileList, TempFile tempFile);
		void check_Mode_2(FileList fileList, TempFile tempFile);
		void check_Mode_3(FileList fileList, TempFile tempFile);
		bool existsFile(std::string path);
		void Start::check_Mode_massage(TempFile tempFile, std::string text);
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
		
};
