#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
private:
    char* name;
    int id;

public:
    Person(const char* name, int id);
    Person(const Person& other);
    Person& operator=(const Person& other);
    virtual ~Person();

    const char* getName() const { return name; };
    int getId() const { return id; };

    void setName(const char* newName);

    virtual void printDetails() const = 0;
};

#endif
