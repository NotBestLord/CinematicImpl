#ifndef CINEMA_H
#define CINEMA_H

#include <list>
#include <memory>
#include "Employee.h"
#include "Guest.h"
#include "IHall.h"
#include "linkedlist.h"
#include "Movie.h"
#include "Shift.h"

using namespace std;

class Cinema {
public:
    static constexpr int INITIAL_CAPACITY = 10;
	static Cinema& getInstance()
	{
		static Cinema theCinema;
		return theCinema;
	}
	~Cinema() = default;

private:
    list<unique_ptr<Employee>> employees;
    list<unique_ptr<Guest>> guests;
    list<unique_ptr<IHall>> halls;
    LinkedList<shared_ptr<const Movie>> movies;
    list<unique_ptr<const Shift>> shifts;

	Cinema() = default;

public:
    const Employee* getEmployeeByIndex(size_t i) const;
    Employee* getEmployeeByIndex(size_t i);
    const Guest* getGuestByIndex(size_t i) const;
    Guest* getGuestByIndex(size_t i);
    const IHall* getHallByIndex(size_t i) const;
    IHall* getHallByIndex(size_t i);
    const Movie* getMovieByIndex(size_t i) const;
    const Shift* getShiftByIndex(size_t i) const;

    Guest* findGuestById(int id) const;
    Employee* findEmployeeById(int id) const;

    const Cinema& operator+=(unique_ptr<Employee> e);
	const Cinema& operator+=(unique_ptr<Guest> g);
	const Cinema& operator+=(unique_ptr<IHall> h);
	const Cinema& operator+=(shared_ptr<const Movie> m);
	const Cinema& operator+=(unique_ptr<const Shift> s);

	const Cinema& operator-=(int guestId);

	size_t getNumEmployees() const { return employees.size(); }
	size_t getNumGuests() const { return guests.size(); }
	size_t getNumHalls() const { return halls.size(); }
	size_t getNumMovies() const { return movies.length(); }
	size_t getNumShifts() const { return shifts.size(); }

    void printAllGuests() const;
    void printAllEmployees() const;
    void printAllHalls() const;
    void printAllMovies() const;
    void printAllShifts() const;
};

#endif
