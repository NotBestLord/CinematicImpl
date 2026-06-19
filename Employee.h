#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Date;

class Employee : public Person {
private:
    double salary;

    static constexpr double PROMOTION_PERCENTAGE = .1;

public:
    Employee(const char* name, int id, const Date& birthDate, double salary);

    double getSalary() const { return salary; }
    void setSalary(double newSalary) { salary = newSalary; }

	const Employee& operator++();

	void toOs(std::ostream& os) const override;
};

#endif
