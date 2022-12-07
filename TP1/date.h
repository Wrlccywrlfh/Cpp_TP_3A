#include <iostream>
class Date {
public:
	Date(int month, int year);
	Date();
	int month();
	int year();
	void displayDate();
	void next(); 
private:
	int _month;
	int _year;
	bool isDate(int month, int year);



};
