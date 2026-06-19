#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include "Date.h"

class Movie {
private:
    char* title;
    Date premiereDate;
    int lengthMinutes;
    bool is3D;

public:
    Movie(const char* title, const Date& premiereDate, int lengthMinutes, bool is3D);
    Movie(const Movie& other);
    Movie(Movie&& other);
    Movie& operator=(const Movie& other);
    ~Movie();

    const char* getTitle() const { return title; };
    const Date& getPremiereDate() const { return premiereDate; };
    int getLengthMinutes() const { return lengthMinutes; };
    bool getIs3D() const { return is3D; };

    void setTitle(const char* newTitle);
    void setLengthMinutes(int minutes) { lengthMinutes = minutes; };
    void setIs3D(bool flag) { is3D = flag; };

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);
};

#endif
