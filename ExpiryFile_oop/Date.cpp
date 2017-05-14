#include "stdafx.h"
#include "Date.h"

// *****************
// methods (private)
// *****************
		
bool Date::validDate(std::string date){

	struct tm ts;
		
	if(!containNumDot(date)){
		return false;
	}
		
	if(!contain2Dots(date)){
		return false;
	}
		
	//
	// From here the string date can contain 2 dots and numbers only.
	//
	
	// convert the date string into a tm struct
	ts = date2struct(date);
	
	// Check whether the year is valid	
	if (ts.tm_year == -1) { // get no proper year
		return false;
	}

	// Check whether the month is valid
	if(!checkMonth(ts.tm_mon)){
		return false;
	}
	
	// Check whether the day valid
	if(!checkDay(ts.tm_mday, ts.tm_mon, ts.tm_year)){
		return false;
	}
	
	// the date have to be in the future to be valide   	
	/*if(!isDateInFuture(mktime(&ts))){
		return false;
	}*/
	
	// if everthink went fine
	return true;
	
}

bool Date::containNumDot(std::string date){
	for(int i = 0; i < date.length(); i++){
		if(!(date[i] == '.' || '0' <= date[i] && date[i] <= '9')){ 
			return false; // if an non valid character was found
		} 
	}
	return true;
}

bool Date::contain2Dots(std::string date){
	short n = 0;
	for(int i = 0; i < date.length(); i++){
		if (date[i] == '.') {
			n++;    // Count how many dots in date
		}
	}
	
	if (n != 2){  // if more or less than 2 dots in the string date return false
		return false;   
	}
	else{
		return true;
	}
	
}

bool Date::checkMonth(int month){
	if(0 <= month && month <= 11){ // 0 == Jan, ... , 11 == Dec.
		return true;
	}
	else{
		return false;
	}
}

int Date::getProperYear(std::string year){
	// returns the proper year for the struct tm (a int in the xxx fomat)
	// 117 for the year 2017 if the user type 2017, as the year
	// 117 for the year 2017 if the user type 17, as the year
	switch(year.length()){
		case 2:
			return strtol(year.c_str(),NULL,10) + 100;
		case 4:
			return strtol(year.c_str(),NULL,10) - 1900;
		default:
			return -1;
	}	
}

bool Date::checkDay(int day, int month, int year){
	// check if the day is correct, depends on the month 
	return day >= 1 &&
           day <= (month == 1 ? (isLeapYear(year) ? 29 : 28) :
                   month == 3 || month == 5 || month == 8 || month == 10 ? 30 : 31);
                   // "30 days has September, April, June and November..."
                   // Month: Jan == 0, Feb == 1, ..., Dec == 11
}


bool Date::isDateInFuture(){
	// check if the date is in the future
	struct tm ts;
	ts = date2struct(date);	
	time_t t = mktime(&ts);
	if(t - time(NULL) > 0 ){
		return true;
	}
	else{
		return false;
	}
}

bool Date::isLeapYear(int year){
	// check if year is leap year
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

std::string Date::adjustProperFormat(std::string date) {
	std::string day, month, year;
	std::istringstream ss(date);
	getline(ss, day, '.');
	getline(ss, month, '.');
	getline(ss, year, '.');

	if(year.length() == 2){
		year = "20" + year;
	}

	return addLeadingZero(day) + "." + addLeadingZero(month) + "." + year;
}

std::string Date::addLeadingZero(std::string s) {
	if (s.length() >= 2) {
		return s;
	}
	else {
		return "0" + s;
	}
}

tm Date::date2struct(std::string date) {
	struct tm ts;
	std::string day;
	std::string month;
	std::string year;
	// split the date by dot.
	std::istringstream ss(date);
	getline(ss, day, '.');
	getline(ss, month, '.');
	getline(ss, year, '.');
	ts.tm_mon = strtol(month.c_str(), NULL, 10) - 1;  // -1, since 0 = Jan, 1 = Feb, ... in struct tm
	ts.tm_year = getProperYear(year);
	ts.tm_mday = strtol(day.c_str(), NULL, 10);
	// must also be set to work
	ts.tm_sec = 0;
	ts.tm_min = 0;
	ts.tm_hour = 13; // to set the day explicit set the hour to middle of the day. 13 is 12 o'clock since min == 0 and sec == 0!

	return ts;
}

// ****************
// methods (public)
// ****************
		
// Constructor
Date::Date(){
	ok = false;
	date    = ""; 
}
		
Date::Date(std::string _date){
	ok = validDate(_date);
	if(ok){
		date = adjustProperFormat(_date) ;
	}
	else{
		date = "";
	}
}
		
// Destructor
Date::~Date(){}

// Getter
std::string Date::to_string(){
	return date;
}
		
bool Date::isValid(){
	return ok;
}
		
// Setter 
void Date::set_date(std::string _date){
	ok = validDate(_date);
	if(ok){
		date = adjustProperFormat(_date);
	}
	else{
		date = "";
	}		
}

// other function

	// not needed in this class

