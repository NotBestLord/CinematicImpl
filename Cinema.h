#ifndef CINEMA_H
#define CINEMA_H

#include <vector>

#include "Employee.h"
#include "Guest.h"
#include "Hall.h"
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
    vector<Hall*> halls;
    vector<const Movie*> movies;
    vector<const Shift*> shifts;

	Cinema();
	Cinema(const Cinema& other);
	Cinema(Cinema&& other);
	const Cinema& operator=(const Cinema& other);
	const Cinema& operator=(Cinema&& other);

public:
    const Employee* getEmployeeByIndex(int i) const;
    Employee* getEmployeeByIndex(int i);
    const Guest* getGuestByIndex(int i) const;
    Guest* getGuestByIndex(int i);
    const Hall* getHallByIndex(int i) const;
    Hall* getHallByIndex(int i);
    const Movie* getMovieByIndex(int i) const;
    const Shift* getShiftByIndex(int i) const;

    Guest* findGuestById(int id) const;
    Employee* findEmployeeById(int id) const;

    const Cinema& operator+=(Employee* e);
	const Cinema& operator+=(Guest* g);
	const Cinema& operator+=(Hall* h);
	const Cinema& operator+=(Movie* m);
	const Cinema& operator+=(Shift* s);

	const Cinema& operator-=(int guestId);

    void printAllGuests() const;
    void printAllEmployees() const;
    void printAllHalls() const;
    void printAllMovies() const;
    void printAllShifts() const;
};

#endif
