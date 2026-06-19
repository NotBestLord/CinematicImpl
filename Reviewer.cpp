#include "Reviewer.h"
#include <cstring>

Reviewer::Reviewer(const char* name, int id, const Date& birthDate, const char* publicationName, int visitCount) :
    Guest(name, id, birthDate, visitCount)
{
    this->publicationName = strdup(publicationName);
}

Reviewer::~Reviewer()
{
    delete []publicationName;
}

void Reviewer::setPublicationName(const char* name)
{
    delete[] publicationName;
    publicationName = strdup(name);
}

void Reviewer::toOs(std::ostream& os) const
{
    os << ", " << publicationName << ", " << getVisitCount() << " | Reviewer";
}