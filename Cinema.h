#ifndef CINEMA_H
#define CINEMA_H

#include "Employee.h"
#include "Guest.h"
#include "Hall.h"
#include "Movie.h"
#include "Shift.h"

class Cinema {
public:
    static const int INITIAL_CAPACITY = 10;

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

    Movie** movies;
    int numMovies;
    int moviesCapacity;

    Shift** shifts;
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
    Cinema& operator=(const Cinema& other);
    ~Cinema();

    int getNumEmployees() const;
    int getNumGuests() const;
    int getNumHalls() const;
    int getNumMovies() const;
    int getNumShifts() const;

    const Employee* getEmployeeByIndex(int i) const;
    Employee* getEmployeeByIndex(int i);
    const Guest* getGuestByIndex(int i) const;
    Guest* getGuestByIndex(int i);
    const Hall* getHallByIndex(int i) const;
    Hall* getHallByIndex(int i);
    const Movie* getMovieByIndex(int i) const;
    Movie* getMovieByIndex(int i);
    const Shift* getShiftByIndex(int i) const;

    Guest* findGuestById(int id);
    Employee* findEmployeeById(int id);

    Cinema& operator+=(Employee* e);
    Cinema& operator+=(Guest* g);
    Cinema& operator+=(Hall* h);
    Cinema& operator+=(Movie* m);
    Cinema& operator+=(Shift* s);

    Cinema& operator-=(int guestId);

    void printAllGuests() const;
    void printAllEmployees() const;
    void printAllHalls() const;
    void printAllMovies() const;
    void printAllShifts() const;
};

#endif
