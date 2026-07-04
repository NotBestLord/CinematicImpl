#include "Person.h"
#include <cstring>

using namespace std;

Person::Person(std::string name, int id, const Date& birthDate) : 
    name(name), id(id), birthDate(birthDate) {}

void Person::setName(std::string newName)
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