#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Date;

class Employee : public Person {
private:
    double salary;

    static const double PROMOTION_PERCENTAGE;

public:
    Employee(const char* name, int id, const Date& birthDate, double salary);
    Employee(const Employee& other);
    const Employee& operator=(const Employee& other);

    double getSalary() const { return salary; }
    void setSalary(double newSalary) { salary = newSalary; }

	const Employee& operator++();
    Employee operator++(int);

	void toOs(std::ostream& os) const override;
};

#endif
