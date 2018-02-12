#include "strptime.h"
#include <iostream>
#include <string>
#include "stdafx.h"
#include "Start.h"
#include "tempFile.h"
#include "Exception.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

Start start;
start.set_input(argc, argv);

try {
	start.handleInput();
	return 1;
}catch (Exception e){
	std::cerr << e.to_string() << std::endl;
	return 0;
}
catch (...) {
	std::cerr << "Someting goes horrible wrong!" << std::endl;
	return 0;
}

}
