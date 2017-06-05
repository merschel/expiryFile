#include "stdafx.h"
#include "Starter.h"
#include "Exception.h"
#include "test.h"

//#define TEST
#undef TEST

int main(int argc, char** argv) {

#ifdef TEST
	test();
#else
	Starter s;
	s.set_input(argc, argv);
	try {
		s.run();
		return 1;
	}
	catch (Exception e) {
		std::cerr << e.to_string() << std::endl;
		return 0;
	}
	catch (...) {
		std::cerr << "Someting goes horrible wrong!" << std::endl;
		return 0;
	}
#endif

int ok;
std::cin >> ok;

}
