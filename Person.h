#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "Date.h"

class Person {
private:
    std::string name;
    int id;
    Date birthDate;

public:
    Person(std::string name, int id, const Date& birthDate);
    Person(const Person& other) = delete;
    virtual ~Person() = 0;

    std::string getName() const { return name; }
    int getId() const { return id; }
	const Date& getBirthDate() const { return birthDate; }

    void setName(std::string newName);

    virtual void toOs(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
#endif
