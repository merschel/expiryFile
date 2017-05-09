#include <iostream>
//#include "Date.h"
//#include "Hash.h"
//#include "tempFile.h"
#include "input.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	/*
	
	// **********
	// ** Date **
	// **********
	// Erzeugen eines Date Objektes. Mittels Konstruktor und set
	Date date1("22.03.2019");
	Date date2;
	date2.set_date("24.04.2020");
	
	std::cout << date1.to_string() << " ist valide " << date1.get_isValid() << std::endl;
	std::cout << date2.to_string() << " ist valide " << date2.get_isValid() << std::endl;
	
	// Erzeugen nicht valider Date objekte
	Date date3("22.032019");
	Date date4;
	date4.set_date("24.04.2020w");    // get_date ist dann ein leerer string!!!
	
	std::cout << date3.to_string() << " ist valide " << date3.get_isValid() << std::endl;
	std::cout << date4.to_string() << " ist valide " << date4.get_isValid() << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	// **********
	// ** Hash **
	// **********
	Hash hash1("tempFiles\\Test.txt");
	Hash hash2("tempFiles\\Test.txt");
	Hash hash3("tempFiles\\Text.docx");
	
	std::cout << hash1.to_string() << std::endl;
	std::cout << hash2.to_string() << std::endl;
	std::cout << hash3.to_string() << std::endl;
	
	std::cout << "hash1 ist gleich hash2: " << hash1.compare(hash2) << std::endl;
	std::cout << "hash1 ist gleich hash3: " << hash1.compare(hash3) << std::endl;
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	// **************
	// ** tempFile **
	// **************
	
	Date date1("22.03.2019");
	tempFile tf1("tempFiles\\Test.txt",date1,"2");

	
	std::cout << "hash in main: " << tf1.get_hash().to_string() << std::endl;
	std::cout << tf1.get_path() << std::endl;
	std::cout << tf1.get_expiry_date().to_string() << std::endl;
	std::cout << tf1.get_modus() << std::endl;
	
	
//	tempFile tf2(hash2,"tempFiles\\Text.docx",date1,"2");
//	std::cout << tf1.get_hash().compare(tf2.get_hash()) << std::endl;
	
	*/
	
	
	Input input;
	
	input.set_input(argc,argv);
	input.extract_prog_mode(); 
	
	switch (input.get_prog_mode()){
		case 'l':
		case 'h':
		case 'c':
		case '0':
		default:
			
	}
	
	std::cout << input.get_prog_mode() << std::endl;
	
	return 0;
}
