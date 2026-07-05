#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Date.h"

using namespace std;

class Person {
private:
    string name;
    int id;
    Date birthDate;

public:
    Person(const string& name, int id, const Date& birthDate);
    Person(const Person& other) = delete;
    virtual ~Person() = default;

    const string& getName() const { return name; }
    int getId() const { return id; }
	const Date& getBirthDate() const { return birthDate; }

    void setName(const string& newName);

    virtual void toOs(ostream& os) const = 0;

    friend ostream& operator<<(ostream& os, const Person& p);
};
#endif
