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
    Movie& operator=(const Movie& other);
    ~Movie();

    const char* getTitle() const;
    const Date& getPremiereDate() const;
    int getLengthMinutes() const;
    bool getIs3D() const;

    void setTitle(const char* newTitle);
    void setLengthMinutes(int minutes);
    void setIs3D(bool flag);

    friend std::ostream& operator<<(std::ostream& os, const Movie& m);
};

#endif
