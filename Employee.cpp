#include "Employee.h"
#include "Date.h"

Employee::Employee(const char* name, int id, const Date& birthDate, double salary) : Person(name, id, birthDate), salary(salary) {}

const Employee& Employee::operator++()
{
	salary += salary * PROMOTION_PERCENTAGE;
	return *this;
}

void Employee::toOs(std::ostream& os) const
{
	os << ", " << "Salary: " << salary;
}
