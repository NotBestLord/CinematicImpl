#include "Person.h"
#include <cstring>

using namespace std;

Person::Person(const char* name, int id, const Date& birthDate) : id(id), birthDate(birthDate)
{
    this->name = strdup(name);
}

Person::~Person()
{
    delete []name;
}

void Person::setName(const char* newName)
{
    delete []name;
    name = strdup(newName);
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "[" << p.name << ", " << p.id << ", " << p.birthDate;
    p.toOs(os);
    os << "]";
    return os;
}