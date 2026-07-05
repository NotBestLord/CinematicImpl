#ifndef CINEMA_H
#define CINEMA_H

#include <vector>

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
	~Cinema();

private:
    vector<Employee*> employees;
    vector<Guest*> guests;
    vector<IHall*> halls;
    vector<const Movie*> movies;
    vector<const Shift*> shifts;

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

    const Cinema& operator+=(Employee* e);
	const Cinema& operator+=(Guest* g);
	const Cinema& operator+=(IHall* h);
	const Cinema& operator+=(const Movie* m);
	const Cinema& operator+=(const Shift* s);

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
