#include "Movie.h"

using namespace std;

Movie::Movie(const string& title, const Date& premiereDate, int lengthMinutes, bool is3D) :
        title(title), premiereDate(premiereDate), lengthMinutes(lengthMinutes), is3D(is3D) {}

void Movie::setTitle(const string& newTitle)
{
    title = newTitle;
}

ostream& operator<<(ostream& os, const Movie& m)
{
    os << "[" << m.title << ", Premiere: " << m.premiereDate << ", " << m.lengthMinutes << " minutes";
    if (m.is3D)
    {
        os << ", 3D";
    }
    os << "]";
    return os;
}