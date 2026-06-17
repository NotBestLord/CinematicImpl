#include "Person.h"
#include <cstring>

using namespace std;

Person::Person(const char* name, int id, const Date& birthDate) : id(id), birthDate(birthDate)
{
    this->name = strdup(name);
}

Person::Person(const Person& other) : name(nullptr)
{
    *this = other;
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->birthDate = other.birthDate;
        delete[]this->name;
        this->name = strdup(other.name);
    }
    return *this;
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