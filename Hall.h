#ifndef HALL_H
#define HALL_H

#include "Movie.h"

class Hall {
public:
    static const int NUM_SEATS = 100;

private:
    int hallNumber;
    bool seats[NUM_SEATS];
    Movie& currentMovie;

public:
    Hall(int hallNumber, Movie& currentMovie);
    Hall(const Hall& other);
    Hall& operator=(const Hall& other) = delete;
    virtual ~Hall();

    int getHallNumber() const;
    const Movie& getCurrentMovie() const;
    bool isSeatTaken(int seatIndex) const;
    int countTakenSeats() const;

    void setHallNumber(int num);

    void takeSeat(int seatIndex);
    void freeSeat(int seatIndex);

    bool operator!() const;

    virtual void printHall() const;
};

#endif
