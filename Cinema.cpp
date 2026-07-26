#include "Cinema.h"
#include <iterator>

const Employee* Cinema::getEmployeeByIndex(size_t i) const
{
	if (i < employees.size())
	{
		auto it = employees.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Employee* Cinema::getEmployeeByIndex(size_t i)
{
	if (i < employees.size())
	{
		auto it = employees.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << employees.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Guest* Cinema::getGuestByIndex(size_t i) const
{
	if (i < guests.size())
	{
		auto it = guests.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

Guest* Cinema::getGuestByIndex(size_t i)
{
	if (i < guests.size())
	{
		auto it = guests.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << guests.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const IHall* Cinema::getHallByIndex(size_t i) const
{
	if (i < halls.size())
	{
		auto it = halls.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

IHall* Cinema::getHallByIndex(size_t i)
{
	if (i < halls.size())
	{
		auto it = halls.begin();
		std::advance(it, i);
		return it->get();
	}
	cout << "Index should be between 0 and " << halls.size() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Movie* Cinema::getMovieByIndex(size_t i) const
{
	if (i < movies.length())
	{
		return movies[i].get();
	}
	cout << "Index should be between 0 and " << movies.length() - 1 << ". Operation cancelled." << endl;
	return nullptr;
}

const Shift* Cinema::getShiftByIndex(size_t i) const
{
	if (i < shifts.size())
	{
		auto it = shifts.begin();
		std::advance(it, i);
		return it->get();
	}
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

const Cinema& Cinema::operator+=(shared_ptr<const Movie> m)
{
	movies += std::move(m);
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
	size_t i = 0;
	for (auto it = employees.begin(); it != employees.end(); ++it, ++i)
	{
		cout << i << ". " << **it << endl;
	}
}

void Cinema::printAllGuests() const
{
	size_t i = 0;
	for (auto it = guests.begin(); it != guests.end(); ++it, ++i)
	{
		cout << i << ". " << **it << endl;
	}
}

void Cinema::printAllHalls() const
{
	size_t i = 0;
	for (auto it = halls.begin(); it != halls.end(); ++it, ++i)
	{
		cout << i << ". " << **it << endl;
	}
}

void Cinema::printAllMovies() const
{
	for (int i = 0; i < movies.length(); i++)
	{
		cout << i << ". " << movies[i]->getTitle() << endl;
	}
}

void Cinema::printAllShifts() const
{
	size_t i = 0;
	for (auto it = shifts.begin(); it != shifts.end(); ++it, ++i)
	{
		cout << i << ". " << **it << endl;
	}
}