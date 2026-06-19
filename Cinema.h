#ifndef CINEMA_H
#define CINEMA_H

#include "Employee.h"
#include "Guest.h"
#include "Hall.h"
#include "Movie.h"
#include "Shift.h"

class Cinema {
public:
    static constexpr int INITIAL_CAPACITY = 10;

private:
    Employee** employees;
    int numEmployees;
    int employeesCapacity;

    Guest** guests;
    int numGuests;
    int guestsCapacity;

    Hall** halls;
    int numHalls;
    int hallsCapacity;

    const Movie** movies;
    int numMovies;
    int moviesCapacity;

    const Shift** shifts;
    int numShifts;
    int shiftsCapacity;

    void resizeEmployees();
    void resizeGuests();
    void resizeHalls();
    void resizeMovies();
    void resizeShifts();

public:
    Cinema();
    Cinema(const Cinema& other);
    Cinema(Cinema&& other);
    const Cinema& operator=(const Cinema& other);
    const Cinema& operator=(Cinema&& other);
    ~Cinema();
    
    int getNumEmployees() const { return numEmployees; }
    int getNumGuests() const { return numGuests; }
    int getNumHalls() const { return numHalls; }
    int getNumMovies() const { return numMovies; }
    int getNumShifts() const { return numShifts; }

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
