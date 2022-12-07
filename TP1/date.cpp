#include <iostream>
#include <cassert>
#include "date.h"

int Date::month(){
	return _month;
}

int Date::year(){
	return _year;
}

void Date::displayDate(){
	std::cout<<_month<<"/"<<_year<<std::endl;
}

bool Date::isDate(int month, int year){
	if(year<0) return false;
	if((month<1)||(month>12)) return false; 
	return true;
}

void Date::next(){
	if(_month < 12) 
		_month = _month + 1;
	else{
		_month = 1;
		_year = _year + 1;}
}

Date::Date(int month, int year) : _month(month), _year(year)
{
	bool status = isDate(month, year);
	assert(status && "Date is not valid");
}


Date::Date(){
	std::cout<<"Donner le mois"<<std::endl;
	std::cin>> _month;
	std::cout<<"Donner l'année"<<std::endl;
	std::cin>> _year;
}
