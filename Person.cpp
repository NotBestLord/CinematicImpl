#include "Person.h"

Person::Person(const string& name, int id, const Date& birthDate) : 
    name(name), id(id), birthDate(birthDate) {}

void Person::setName(const string& newName)
{
    name = newName;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "[" << p.name << ", " << p.id << ", " << p.birthDate;
    p.toOs(os);
    os << "]";
    return os;
}