#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    static bool isValidDate(int d, int m, int y);

public:
    Date(int day = 1, int month = 1, int year = 2000);

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

    bool operator==(const Date& other) const;

    friend void operator<<(ostream& os, const Date& d);
};

#endif
