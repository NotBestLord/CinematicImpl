#ifndef HALL_H
#define HALL_H

#include "Movie.h"
#include <iostream>

using namespace std;

class Hall {
public:
    static constexpr int NUM_SEATS = 100;

private:
    int hallNumber;
    bool seats[NUM_SEATS];
    const Movie& currentMovie;

public:
    Hall(int hallNumber, const Movie& currentMovie);
    Hall(const Hall& other);
    Hall& operator=(const Hall& other) = delete;

    int getHallNumber() const { return hallNumber; }
    const Movie& getCurrentMovie() const { return currentMovie; }
    bool isSeatTaken(int seatIndex) const { return seats[seatIndex]; }
    int countTakenSeats() const;

    void setHallNumber(int num) { hallNumber = num; }

    void takeSeat(int seatIndex);
    void freeSeat(int seatIndex);

    bool operator!() const;

	virtual void toOs(ostream& os) const {}

	friend ostream& operator<<(ostream& os, const Hall& h);
};

#endif
