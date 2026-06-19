#include "Movie.h"
#include <cstring>

using namespace std;

Movie::Movie(const char* title, const Date& premiereDate, int lengthMinutes, bool is3D) :
        premiereDate(premiereDate), lengthMinutes(lengthMinutes), is3D(is3D)
{
    this->title = strdup(title);
}

Movie::Movie(const Movie& other) : title(nullptr)
{
    *this = other;
}

Movie::Movie(Movie&& other) : 
    title(nullptr), premiereDate(std::move(other.premiereDate)), 
    lengthMinutes(other.lengthMinutes), is3D(other.is3D)
{
    std::swap(title, other.title);
}

Movie& Movie::operator=(const Movie& other)
{
    if (this != &other)
    {
        this->premiereDate = other.premiereDate;
        this->lengthMinutes = other.lengthMinutes;
        this->is3D = other.is3D;
        delete[]this->title;
        this->title = strdup(other.title);
    }
    return *this;
}

Movie::~Movie()
{
    delete []this->title;
}

void Movie::setTitle(const char* newTitle)
{
    delete []this->title;
    this->title = strdup(newTitle);
}

ostream& operator<<(ostream& os, const Movie& m)
{
    os << "[" << m.title << ", " << m.premiereDate << ", " << m.lengthMinutes << " minutes";
    if (m.is3D)
    {
        os << ", 3D";
    }
    os << "]";
    return os;
}