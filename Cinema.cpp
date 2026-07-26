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
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(employees.size() - 1) + "]");
}
Employee* Cinema::getEmployeeByIndex(size_t i)
{
	if (i < employees.size())
	{
		auto it = employees.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(employees.size() - 1) + "]");
}
const Guest* Cinema::getGuestByIndex(size_t i) const
{
	if (i < guests.size())
	{
		auto it = guests.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(guests.size() - 1) + "]");
}
Guest* Cinema::getGuestByIndex(size_t i)
{
	if (i < guests.size())
	{
		auto it = guests.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(guests.size() - 1) + "]");
}
const IHall* Cinema::getHallByIndex(size_t i) const
{
	if (i < halls.size())
	{
		auto it = halls.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(halls.size() - 1) + "]");
}
IHall* Cinema::getHallByIndex(size_t i)
{
	if (i < halls.size())
	{
		auto it = halls.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(halls.size() - 1) + "]");
}
const Movie* Cinema::getMovieByIndex(size_t i) const
{
	if (i < movies.length())
	{
		return movies[i].get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(movies.length() - 1) + "]");
}
const Shift* Cinema::getShiftByIndex(size_t i) const
{
	if (i < shifts.size())
	{
		auto it = shifts.begin();
		std::advance(it, i);
		return it->get();
	}
	throw out_of_range("Index " + to_string(i) + " out of range [0, " + to_string(shifts.size() - 1) + "]");
}
Guest* Cinema::findGuestById(int id) const
{
	for (const auto& guest : guests)
	{
		if (guest->getId() == id) return guest.get();
	}
	throw invalid_argument("Guest with given ID doesn't exist.");
}
Employee* Cinema::findEmployeeById(int id) const
{
	for (const auto& employee : employees)
	{
		if (employee->getId() == id) return employee.get();
	}
	throw invalid_argument("Employee with given ID doesn't exist.");
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
	throw invalid_argument("Guest with given ID doesn't exist.");
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