#include "Reviewer.h"
#include <cstring>

Reviewer::Reviewer(std::string name, int id, const Date& birthDate, std::string publicationName, int visitCount) :
    Guest(name, id, birthDate, visitCount), publicationName(publicationName) {}

void Reviewer::toOs(std::ostream& os) const
{
    os << ", " << publicationName << ", " << getVisitCount() << " | Reviewer";
}