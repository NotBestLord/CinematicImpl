#ifndef CINEMA_H
#define CINEMA_H

#include <vector>
#include <memory>
#include "Employee.h"
#include "Guest.h"
#include "IHall.h"
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
    vector<unique_ptr<Employee>> employees;
    vector<unique_ptr<Guest>> guests;
    vector<unique_ptr<IHall>> halls;
    vector<unique_ptr<const Movie>> movies;
    vector<unique_ptr<const Shift>> shifts;

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
	const Cinema& operator+=(unique_ptr<const Movie> m);
	const Cinema& operator+=(unique_ptr<const Shift> s);

	const Cinema& operator-=(int guestId);

	size_t getNumEmployees() const { return employees.size(); }
	size_t getNumGuests() const { return guests.size(); }
	size_t getNumHalls() const { return halls.size(); }
	size_t getNumMovies() const { return movies.size(); }
	size_t getNumShifts() const { return shifts.size(); }

    void printAllGuests() const;
    void printAllEmployees() const;
    void printAllHalls() const;
    void printAllMovies() const;
    void printAllShifts() const;
};

#endif
