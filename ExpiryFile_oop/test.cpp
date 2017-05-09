

// header for visual studio
#include "stdafx.h"
#include "date.h"
#include <ctime>
#include <iostream>

void test(){
	
	bool ok = true;

	//
	// date.cpp
	//
	{
		// isLeapYear
		std::cout << "isLeapYear" << std::endl;
		ok &= isLeapYear(2016) ? true : false; // leap year, since 2016 % 4 == 0
		std::cout << ok << std::endl;
		ok &= isLeapYear(2013) ? false : true; // no leap year, since 2013 % 4 != 0
		std::cout << ok << std::endl;
		ok &= isLeapYear(2000) ? true : false; // leap year, since 2000 % 4 == 0 AND 2000 % 100 == 0 AND 2000 % 400 == 0
		std::cout << ok << std::endl;
		ok &= isLeapYear(1900) ? false : true; // no leap year, since 1900 % 4 == 0 AND 1900 % 100 == 0 AND 1900 % 400 != 0
		std::cout << ok << std::endl;

		// containNumDot
		std::cout << "containNumDot" << std::endl;
		ok &= containNumDot("32.43.54") ? true : false;  // true, since the string contains only numbers and dots
		std::cout << ok << std::endl;
		ok &= containNumDot(".") ? true : false;  // true, since the string contains only dots
		std::cout << ok << std::endl;
		ok &= containNumDot("24") ? true : false;  // true, since the string contains only numbers
		std::cout << ok << std::endl;
		ok &= containNumDot("b2.4.3") ? false : true;  // false, since the string contains a character
		std::cout << ok << std::endl;

		// contain2Dots  // here assume that date only contains numbers and dots
		std::cout << "contain2Dots" << std::endl;
		ok &= contain2Dots("3.4.3") ? true : false;  // true, since the string contains only 2 dots
		std::cout << ok << std::endl;
		ok &= contain2Dots("..") ? true : false;  // true, since the string contains only 2 dots
		std::cout << ok << std::endl;
		ok &= contain2Dots("3.43") ? false : true;  // false, since the string contains only 1 dots
		std::cout << ok << std::endl;
		ok &= contain2Dots("343") ? false : true;  // false, since the string contains non dots
		std::cout << ok << std::endl;
		ok &= contain2Dots("3.4.3.") ? false : true;  // false, since the string contains 3 dots
		std::cout << ok << std::endl;

		//bool checkMonth(int m);
		std::cout << "checkMonth" << std::endl;
		ok &= checkMonth(1) ? true : false; // true, since 1 is in the range
		std::cout << ok << std::endl;
		ok &= checkMonth(2) ? true : false; // true, since 2 is in the range
		std::cout << ok << std::endl;
		ok &= checkMonth(11) ? true : false; // true, since 11 is in the range
		std::cout << ok << std::endl;
		ok &= checkMonth(0) ? true : false; // true, since 0 is not in the range
		std::cout << ok << std::endl;
		ok &= checkMonth(12) ? false : true; // true, since 12 is not in the range
		std::cout << ok << std::endl;

		// int getProperYear(int y);  //assume y is a string contain only numbers
		std::cout << "getProperYear" << std::endl;
		ok &= getProperYear("23") == 123 ? true : false; // true, since tm expect 123 for the year 2023
		std::cout << ok << std::endl;
		ok &= getProperYear("2013") == 113 ? true : false; //  true, since tm expect 113 for the year 2013
		std::cout << ok << std::endl;
		ok &= getProperYear("013") == -1 ? true : false; //  true, since 013 in not valid
		std::cout << ok << std::endl;
		ok &= getProperYear("2") == -1 ? true : false; // treu, since 2 in not valid
		std::cout << ok << std::endl;

		ok &= getProperYear("1966") == 66 ? true : false; // treu, since 2 in not valid
		std::cout << ok << std::endl;

		//bool checkDay(int day, int month, int year);
		std::cout << "checkDay" << std::endl;
		ok &= checkDay(23, 4, 2014) ? true : false; // true, since 23 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(0, 4, 2014) ? false : true; // false, since 0 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(33, 4, 2014) ? false : true; // false, since 33 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(29, 2, 2016) ? true : false; // true, since 29 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(29, 2, 2014) ? false : true; // false, since 29 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 4, 2014) ? false : true; // false, since 31 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 6, 2014) ? false : true; // false, since 31 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 9, 2014) ? false : true; // false, since 31 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 11, 2014) ? false : true; // false, since 31 is not a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 1, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(28, 2, 2014) ? true : false; // true, since 28 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 3, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 5, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 7, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 8, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 10, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;
		ok &= checkDay(31, 12, 2014) ? true : false; // true, since 31 is a valid day for this year and month
		std::cout << ok << std::endl;

		//bool isDateInFuture(time_t t);
		struct tm ts;
		std::cout << "isDateInFuture" << std::endl;

		ts.tm_sec = 0;
		ts.tm_min = 0;
		ts.tm_hour = 13;
		ts.tm_mday = 1;
		ts.tm_mon = 2;
		ts.tm_year = 199;  // 2099
		ok &= isDateInFuture(mktime(&ts)) ? true : false; // true, since 01.02.2099 is in the future
		std::cout << ok << std::endl;

		/*std::cout << "----" << std::endl;
		time_t t = time(NULL);
		struct tm *te = localtime(&t);
		std::cout << isDateInFuture(mktime(te)) << std::endl;
		ok &= isDateInFuture(mktime(te)) ? false : true; // false, since date is today
		std::cout << ok << std::endl;
		std::cout << "----" << std::endl;
		*/

		ts.tm_sec = 0;
		ts.tm_min = 0;
		ts.tm_hour = 13;
		ts.tm_mday = 26;
		ts.tm_mon = 3;
		ts.tm_year = 117;  // 2017
		ok &= isDateInFuture(mktime(&ts)) ? false : true; // false, since 26.03.2017 is in the past
		std::cout << ok << std::endl;

		// valid date
		std::cout << "validDate" << std::endl;
		ok &= validDate("01.01.2020") ? true : false; // true, since 01.01.2017 is a valid date
		std::cout << ok << std::endl;
		ok &= validDate("01.01.2015") ? false : true; // true, since 01.01.2015 is in the past
		std::cout << ok << std::endl;
		ok &= validDate("01.01.20153") ? false : true; // false, since 01.01.20153 is not a valid date
		std::cout << ok << std::endl;
		ok &= validDate("01.01,2020") ? false : true; // false, since ',' is not a valid for date
		std::cout << ok << std::endl;
		ok &= validDate("01.01.202a") ? false : true; // false, since 01.01.201a is not a valid date
		std::cout << ok << std::endl;
		ok &= validDate("01.01.1988") ? false : true; // false, since 01.01.1988 is in the past
		std::cout << ok << std::endl;
		ok &= validDate("0101.2020") ? false : true; // false, since a dot is missing.  
		std::cout << ok << std::endl;

		//std::string addLeadingZero(std::string s);
		std::cout << "addLeadingZero" << std::endl;
		ok &= addLeadingZero("02") == "02" ? true : false; // true, since 01 transform to 01 
		std::cout << ok << std::endl;
		ok &= addLeadingZero("2") == "02" ? true : false; // true, since 1 transform to 01 
		std::cout << ok << std::endl;

		//std::string adjustProperFormat(std::string date);
		std::cout << "adjustProperFormat" << std::endl;
		ok &= adjustProperFormat("01.01.2020") == "01.01.2020" ? true : false; // true, since 01.01.2020 is the rigth format 
		std::cout << ok << std::endl;
		ok &= adjustProperFormat("1.01.2020") == "01.01.2020" ? true : false; // true, since 1.01.2020 is the rigth format 
		std::cout << ok << std::endl;
		ok &= adjustProperFormat("01.1.2020") == "01.01.2020" ? true : false; // true, since 1.01.2020 is the rigth format 
		std::cout << ok << std::endl;
		ok &= adjustProperFormat("1.1.2020") == "01.01.2020" ? true : false; // true, since 1.01.2020 is the rigth format 
		std::cout << ok << std::endl;
		
	}
	std::cout << std::endl;
	std::cout << "Total result: " << ok << std::endl;
	
}
