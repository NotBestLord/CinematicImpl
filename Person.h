#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Date.h"

class Person {
private:
    char* name;
    int id;
    Date birthDate;

public:
    Person(const char* name, int id, const Date& birthDate);
    Person(const Person& other);
    const Person& operator=(const Person& other);
    virtual ~Person();

    const char* getName() const { return name; };
    int getId() const { return id; };

    void setName(const char* newName);

    virtual void toOs(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
#endif
