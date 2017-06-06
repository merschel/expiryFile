#include "stdafx.h"
#include "ExpiryDate.h"
#include "strptime.h"
#include <time.h>
//#define _CRT_SECURE_NO_WARNINGS

// *****************
// methods (private)
// *****************
		
bool ExpiryDate::isValid(){
	return valid;
}

// ****************
// methods (public)
// ****************
		
// Constructor
ExpiryDate::ExpiryDate(){
	expiryDate = -1;
}

// Destructor
ExpiryDate::~ExpiryDate(){}

// Getter
time_t ExpiryDate::get_expiryDate(){
	return expiryDate;
}
	
// Setter 
void ExpiryDate::set_expiryDate(std::string _expiryDate){
	struct tm ts;

	if (_expiryDate.find("d") != std::string::npos) {
		extractTime(_expiryDate, 'd');
	}
	else if (_expiryDate.find("m") != std::string::npos) {
		extractTime(_expiryDate, 'm');
	}
	else if (_expiryDate.find("y") != std::string::npos) {
		extractTime(_expiryDate, 'y');
	}
	else {
		if (strptime(_expiryDate.c_str(), "%d.%m.%Y", &ts) == NULL) {
			valid = false;
			return;
		}
		// Check whether the year is valid	
		if (ts.tm_year < -900) { // maybe the given year format is %y, not %Y.
			if (strptime(_expiryDate.c_str(), "%d.%m.%y", &ts) == NULL) {
				valid = false;
				return;
			}
		}

		ts.tm_hour = 12;
		ts.tm_min = 30;
		ts.tm_sec = 30;
		ts.tm_isdst = -1;

		expiryDate = mktime(&ts);
		if (expiryDate == -1) {
			valid = false;
			return;
		}

		// everythink is fine
		valid = true;
		
	}
}

// other function

std::string ExpiryDate::to_string() {
	if (valid) {
		char buffer[11];
		std::strftime(buffer, 11, "%d.%m.%Y", localtime(&expiryDate));
		return std::string(buffer);
	}
	else {
		return "";
	}
}

void ExpiryDate::extractTime(std::string str, char s) {
	int h;
	struct tm * now;
	time_t t;
	try {
		std::size_t pos = str.find(s);
		h = std::stoi(str.substr(0, pos));
		t = time(0);
		now = localtime(&t);
		switch (s) {
		case 'd':
			now->tm_mday += h;
			break;
		case 'm':
			now->tm_mon += h;
			break;
		case 'y':
			now->tm_year += h;
			break;
		}
		expiryDate = mktime(now);
		if (expiryDate == -1) {
			valid = false;
		}
		else {
			valid = true;
		}
	}
	catch(...){
		valid = false;
	}
}

bool ExpiryDate::isDateInFuture() {
	return time(0) < expiryDate;
}