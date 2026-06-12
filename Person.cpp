#include "Person.h"
#include <cstring>

Person::Person(const char* name, int id) : id(id)
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