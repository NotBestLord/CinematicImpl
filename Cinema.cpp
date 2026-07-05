#include "Cinema.h"

Cinema::~Cinema()
{
	for (Employee* employee : employees) { delete employee;	}
	for (Guest* guest : guests) { delete guest;	}
	for (Hall* hall : halls) { delete hall;	}
	for (const Movie* movie : movies) { delete movie;	}
	for (const Shift* shift : shifts) { delete shift;	}
}

const Employee* Cinema::getEmployeeByIndex(size_t i) const
{
	if (i <= employees.size()) return employees[i];
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Employee* Cinema::getEmployeeByIndex(size_t i)
{
	if (i <= employees.size()) return employees[i];
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Guest* Cinema::getGuestByIndex(size_t i) const
{
	if (i <= guests.size()) return guests[i];
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::getGuestByIndex(size_t i)
{
	if (i <= guests.size()) return guests[i];
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Hall* Cinema::getHallByIndex(size_t i) const
{
	if (i <= halls.size()) return halls[i];
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Hall* Cinema::getHallByIndex(size_t i)
{
	if (i <= halls.size()) return halls[i];
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Movie* Cinema::getMovieByIndex(size_t i) const
{
	if (i <= movies.size()) return movies[i];
	cout << "Index should be between 0 and " << movies.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Shift* Cinema::getShiftByIndex(size_t i) const
{
	if (i <= shifts.size()) return shifts[i];
	cout << "Index should be between 0 and " << shifts.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::findGuestById(int id) const
{
	for (Guest* guest : guests)
	{
		if (guest->getId() == id) return guest;
	}
	cout << "Guest with given ID doesn't exist." << endl;
	return nullptr;
}

Employee* Cinema::findEmployeeById(int id) const
{
	for (Employee* employee : employees)
	{
		if (employee->getId() == id) return employee;
	}
	cout << "Employee with given ID doesn't exist." << endl;
	return nullptr;
}

const Cinema& Cinema::operator+=(Employee* e)
{
	employees.push_back(e);
	return *this;
}

const Cinema& Cinema::operator+=(Guest* g)
{
	guests.push_back(g);
	return *this;
}

const Cinema& Cinema::operator+=(Hall* h)
{
	halls.push_back(h);
	return *this;
}

const Cinema& Cinema::operator+=(const Movie* m)
{
	movies.push_back(m);
	return *this;
}

const Cinema& Cinema::operator+=(const Shift* s)
{
	shifts.push_back(s);
	return *this;
}

const Cinema& Cinema::operator-=(int guestId)
{
	for (auto it = guests.begin(); it != guests.end(); ++it)
	{
		if ((*it)->getId() == guestId)
		{
			delete* it;
			guests.erase(it);
			return *this;
		}
	}

	cout << "Guest with given ID doesn't exist. Operation cancelled." << endl;
	return *this;
}

void Cinema::printAllEmployees() const
{
	for (size_t i = 0; i < employees.size(); i++)
	{
		cout << i << ". " << *employees[i] << endl;
	}
}

void Cinema::printAllGuests() const
{
	for (size_t i = 0; i < guests.size(); i++)
	{
		cout << i << ". " << *guests[i] << endl;
	}
}

void Cinema::printAllHalls() const
{
	for (size_t i = 0; i < halls.size(); i++)
	{
		cout << i << ". " << *halls[i] << endl;
	}
}

void Cinema::printAllMovies() const
{
	for (size_t i = 0; i < movies.size(); i++)
	{
		cout << i << ". " << movies[i]->getTitle() << endl;
	}
}

void Cinema::printAllShifts() const
{
	for (size_t i = 0; i < shifts.size(); i++)
	{
		cout << i << ". " << *shifts[i] << endl;
	}
}