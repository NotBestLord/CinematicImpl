#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include "Date.h"

using namespace std;

class Movie {
private:
    string title;
    Date premiereDate;
    int lengthMinutes;
    bool is3D;

public:
    Movie(const string& title, const Date& premiereDate, int lengthMinutes, bool is3D);

    const string& getTitle() const { return title; };
    const Date& getPremiereDate() const { return premiereDate; };
    int getLengthMinutes() const { return lengthMinutes; };
    bool getIs3D() const { return is3D; };

    void setTitle(const string& newTitle);
    void setLengthMinutes(int minutes) { lengthMinutes = minutes; };
    void setIs3D(bool flag) { is3D = flag; };

    friend ostream& operator<<(ostream& os, const Movie& m);
};

#endif
