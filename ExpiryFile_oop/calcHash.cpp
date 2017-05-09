// header for visual studio
#include "stdafx.h"

#include <string>
#include <iostream>

#include "hl_md5wrapper.h"
#include "hl_md5.h"
#include "hl_hashwrapper.h"
#include "calcHash.h"



// calc the md5 hash 
std::string calcHash(std::string path) {
	hashwrapper *hw = new md5wrapper();
	try {
		return hw->getHashFromFile(path);
	}
	catch (hlException &e) {
		std::cerr << "The md5 sum of this file can not be calculated!" << std::endl;
		return "";
	}
}
