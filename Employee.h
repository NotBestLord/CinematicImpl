#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Date;

class Employee : public Person {
private:
    double salary;

    static constexpr double PROMOTION_PERCENTAGE = .1;

public:
    Employee(const string& name, int id, const Date& birthDate, double salary);
	~Employee() override = default;

    double getSalary() const { return salary; }
    void setSalary(double newSalary) { salary = newSalary; }

	const Employee& operator++();

	void toOs(ostream& os) const override;
};

#endif
