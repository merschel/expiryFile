// expiryFile.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

// header for visual studio
#include "stdafx.h"
#include "start.h"
#include "test.h"

bool main(int argc, char **argv) {

	bool ok = true;
	
#if 0
	test();
#else
	ok = start(argc, argv);
#endif
	
	return ok;
}



