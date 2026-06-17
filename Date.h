#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    static bool isValidDate(int d, int m, int y)
    {
		return (y > 0) && (m >= 1 && m <= 12) && (d >= 1 && d <= 31);
    }

public:
    Date(int day = 1, int month = 1, int year = 2000)
    {
        if (!isValidDate(day, month, year))
        {
			cout << "Invalid date provided. Setting to default (01/01/2000)." << endl;
			day = 1;
			month = 1;
			year = 2000;
		}
        else
        {
			this->day = day;
			this->month = month;
			this->year = year;
		}
    }

    int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

    void setDay(int d)
    {
        if (isValidDate(d, month, year)) day = d;
        else cout << "Invalid day provided. Day not updated." << endl;
	}

    void setMonth(int m)
    {
        if (isValidDate(day, m, year)) month = m;
        else cout << "Invalid month provided. Month not updated." << endl;
    }

    void setYear(int y)
    {
        if (isValidDate(day, month, y)) year = y;
        else cout << "Invalid year provided. Year not updated." << endl;
    }

    bool operator==(const Date& other) const
    {
		return (day == other.day) && (month == other.month) && (year == other.year);
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& d)
    {
        os << (d.day < 10 ? "0" : "") << d.day << "/"
           << (d.month < 10 ? "0" : "") << d.month << "/"
           << d.year;
		return os;
    }
};

#endif
