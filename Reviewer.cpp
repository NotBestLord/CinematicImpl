#include "Reviewer.h"

Reviewer::Reviewer(const string& name, int id, const Date& birthDate, const string& publicationName, int visitCount) :
    Guest(name, id, birthDate, visitCount), publicationName(publicationName) {}

void Reviewer::toOs(std::ostream& os) const
{
    os << ", " << publicationName << ", " << getVisitCount() << " | Reviewer";
}