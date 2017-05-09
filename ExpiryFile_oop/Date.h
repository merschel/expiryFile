#pragma once
#include "stdafx.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

class Date{
	private:
		// ********************
		// properties (private)
		// ********************
		
		std::string date;
		bool ok;
		
		// *****************
		// methods (private)
		// *****************
		bool validDate(std::string date);
		bool containNumDot(std::string date);
		bool contain2Dots(std::string date);
		bool checkMonth(int month);
		int getProperYear(std::string year);
		bool checkDay(int day, int month, int year);
		bool isDateInFuture(time_t t);
		bool isLeapYear(int year);
		std::string adjustProperFormat(std::string date);
		std::string addLeadingZero(std::string s);
		tm date2struct(std::string date);
		
	public:
		
		// *******************
		// properties (public)
		// *******************
		
		// not needed for this class
		
		// ****************
		// methods (public)
		// ****************
		
		// Constructor
		Date();
		Date(std::string _date);
		
		// Destructor
		~Date();
		
		// Getter
		std::string to_string();
		bool isValid();
		
		// Setter 
		void set_date(std::string _date);
		
		// other functions
};
