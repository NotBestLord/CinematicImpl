#include "Date.h"

bool Date::isValidDate(int d, int m, int y)
{
	return (y > 0) && (m >= 1 && m <= 12) && (d >= 1 && d <= 31);
}

Date::Date(int day, int month, int year)
{
	if (!isValidDate(day, month, year))
	{
		cout << "Invalid date provided. Setting to default (01/01/2000)." << endl;
		this->day = 1;
		this->month = 1;
		this->year = 2000;
	}
	else
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}

bool Date::operator==(const Date& other) const
{
	return (day == other.day) && (month == other.month) && (year == other.year);
}


ostream& operator<<(ostream& os, const Date& d)
{
	os << (d.day < 10 ? "0" : "") << d.day << "/"
		<< (d.month < 10 ? "0" : "") << d.month << "/"
		<< d.year;
	return os;
}
