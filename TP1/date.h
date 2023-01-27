#pragma once 
#include <iostream>
class Date {
public:
	Date(int day, int month, int year);
	Date(int month, int year);
	int day();
	int month();
	int year();
	void displayDate();
private:
	int _day;
	int _month;
	int _year;
	bool isDate(int day, int month, int year);
	bool isDate(int month, int year);


};

