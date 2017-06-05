
#include "ExpiryDate.h"
#include <string>
#include <iostream>
void test() {

	bool ok = true;

	ExpiryDate ed;

	ed.set_expiryDate("22.03.2018");
	ok &= ed.isValid() ? true : false ;
	std::cout << ok << std::endl;
	ok &= ed.to_string() == "22.03.2018" ? true : false;
	std::cout << ok << std::endl;

	ed.set_expiryDate("22q.03.2018");
	ok &= ed.isValid() ? false : true;
	std::cout << ok << std::endl;

	ed.set_expiryDate("22.p3.2018");
	ok &= ed.isValid() ? false : true;
	std::cout << ok << std::endl;

	ed.set_expiryDate("22.03.2018w");
	ok &= ed.isValid() ? true : false;
	std::cout << ok << std::endl;

	ed.set_expiryDate("22.03.18");
	ok &= ed.isValid() ? true : false;
	std::cout << ok << std::endl;
	ok &= ed.to_string() == "22.03.2018" ? true : false;
	std::cout << ok << std::endl;

	ed.set_expiryDate("22.3.2018");
	ok &= ed.isValid() ? true : false;
	std::cout << ok << std::endl;
	ok &= ed.to_string() == "22.03.2018" ? true : false;
	std::cout << ok << std::endl;

	ed.set_expiryDate("2.03.2018");
	ok &= ed.isValid() ? true : false;
	std::cout << ok << std::endl;
	ok &= ed.to_string() == "02.03.2018" ? true : false;
	std::cout << ok << std::endl;

	ed.set_expiryDate("2203.2018");
	ok &= ed.isValid() ? false : true;
	std::cout << ok << std::endl;

	ed.set_expiryDate("33.03.2018");
	ok &= ed.isValid() ? false : true;
	std::cout << ok << std::endl;

	ed.set_expiryDate("32.03.2018");
	ok &= ed.isValid() ? false : true;
	std::cout << ok << std::endl;

	ed.set_expiryDate("29.02.2020");
	ok &= ed.isValid() ? true : false;
	std::cout << ok << std::endl;
	ok &= ed.to_string() == "29.02.2020" ? true : false;
	std::cout << ok << std::endl;

	std::cout << "overall result" << std::endl;
	std::cout << ok << std::endl;

}