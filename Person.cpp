#include "Person.h"
#include <cstring>

using namespace std;

Person::Person(const char* name, int id, const Date& birthDate) : id(id), birthDate(birthDate)
{
    this->name = strdup(name);
}

Person::Person(Person&& other) : id(other.id), birthDate(std::move(other.birthDate))
{
    name = nullptr;
	std::swap(name, other.name);
}

Person::~Person()
{
    delete []this->name;
}

void Person::setName(const char* newName)
{
    delete []this->name;
    this->name = strdup(newName);
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << "[" << p.name << ", " << p.id << ", " << p.birthDate;
    p.toOs(os);
    os << "]";
    return os;
}