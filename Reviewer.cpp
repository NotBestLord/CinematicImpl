#include "Reviewer.h"
#include <cstring>

Reviewer::Reviewer(const char* name, int id, const char* publicationName, int visitCount = 0) :
    Guest(name, id, visitCount)
{
    this->publicationName = strdup(publicationName);
}

Reviewer::Reviewer(const Reviewer& other) : Guest(other), publicationName(nullptr)
{
    *this = other;
}

Reviewer& Reviewer::operator=(const Reviewer& other)
{
    if (this != &other)
    {
        delete[]this->publicationName;
        this->publicationName = strdup(other.publicationName);
    }
    return *this;
}

Reviewer::~Reviewer()
{
    delete []this->publicationName;
}

void Reviewer::setPublicationName(const char* name)
{
    delete[] this->publicationName;
    this->publicationName = strdup(name);
}

void Reviewer::toOs(std::ostream& os) const
{
    os << ", " << this->publicationName << ", " << this->getVisitCount() << " | Reviewer";
}