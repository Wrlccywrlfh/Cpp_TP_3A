#include <iostream>
#include <cassert>
#include "date.h"

int Date::day(){
	return _day;
}

int Date::month(){
	return _month;
}

int Date::year(){
	return _year;
}

void Date::displayDate(){
	std::cout<<_month<<"/"<<_year;
}

bool Date::isDate(int day, int month, int year){
	if(year<0) return false;
	if((day<1)||(day>31)) return false; 
	if((month<1)||(month>12)) return false; 
	if((month == 2)&&(day>28)) return false;
	if(((month == 4) || (month == 6) || (month == 9) ||
		(month==11)) && (day>30)) return false; 
	return true;
}

bool Date::isDate(int month, int year){
	if(year<0) return false;
	if((month<1)||(month>12)) return false; 
	return true;
}

Date::Date(int day, int month, int year): _day(day), _month(month), _year(year){
	bool status = isDate(day, month, year);
	assert(status && "Date is not valid");
}

Date::Date(int month, int year) : _month(month), _year(year){
	bool status = isDate(month, year);
	assert(status && "Date is not valid");

}
