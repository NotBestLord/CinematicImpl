#include "Cinema.h"

const Employee* Cinema::getEmployeeByIndex(size_t i) const
{
	if (i <= employees.size()) return employees[i].get();
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Employee* Cinema::getEmployeeByIndex(size_t i)
{
	if (i <= employees.size()) return employees[i].get();
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Guest* Cinema::getGuestByIndex(size_t i) const
{
	if (i <= guests.size()) return guests[i].get();
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::getGuestByIndex(size_t i)
{
	if (i <= guests.size()) return guests[i].get();
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const IHall* Cinema::getHallByIndex(size_t i) const
{
	if (i <= halls.size()) return halls[i].get();
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

IHall* Cinema::getHallByIndex(size_t i)
{
	if (i <= halls.size()) return halls[i].get();
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Movie* Cinema::getMovieByIndex(size_t i) const
{
	if (i <= movies.size()) return movies[i].get();
	cout << "Index should be between 0 and " << movies.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Shift* Cinema::getShiftByIndex(size_t i) const
{
	if (i <= shifts.size()) return shifts[i].get();
	cout << "Index should be between 0 and " << shifts.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::findGuestById(int id) const
{
	for (const auto& guest : guests)
	{
		if (guest->getId() == id) return guest.get();
	}
	cout << "Guest with given ID doesn't exist." << endl;
	return nullptr;
}

Employee* Cinema::findEmployeeById(int id) const
{
	for (const auto& employee : employees)
	{
		if (employee->getId() == id) return employee.get();
	}
	cout << "Employee with given ID doesn't exist." << endl;
	return nullptr;
}

const Cinema& Cinema::operator+=(unique_ptr<Employee> e)
{
	employees.push_back(std::move(e));
	return *this;
}

const Cinema& Cinema::operator+=(unique_ptr<Guest> g)
{
	guests.push_back(std::move(g));
	return *this;
}

const Cinema& Cinema::operator+=(unique_ptr<IHall> h)
{
	halls.push_back(std::move(h));
	return *this;
}

const Cinema& Cinema::operator+=(unique_ptr<const Movie> m)
{
	movies.push_back(std::move(m));
	return *this;
}

const Cinema& Cinema::operator+=(unique_ptr<const Shift> s)
{
	shifts.push_back(std::move(s));
	return *this;
}

const Cinema& Cinema::operator-=(int guestId)
{
	for (auto it = guests.begin(); it != guests.end(); ++it)
	{
		if ((*it)->getId() == guestId)
		{
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