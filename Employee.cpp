#include "Employee.h"
#include "Date.h"

Employee::Employee(const char* name, int id, const Date& birthDate, double salary) : Person(name, id, birthDate), salary(salary) {}

Employee::Employee(const Employee& other) : Person(other), salary(other.salary) {}

const Employee& Employee::operator=(const Employee& other)
{
	salary = other.salary;
	Person::operator=(other);
	return *this;
}

const Employee& Employee::operator++()
{
	salary += salary * PROMOTION_PERCENTAGE;
	return *this;
}

Employee Employee::operator++(int)
{
	Employee temp(*this);
	salary += salary * PROMOTION_PERCENTAGE;
	return temp;
}

void Employee::toOs(std::ostream& os) const
{
	os << ", " << "Salary: " << salary;
}
