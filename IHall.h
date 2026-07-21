#ifndef IHALL_H
#define IHALL_H

#include "Movie.h"
#include <iostream>

using namespace std;

class IHall {
public:
	static constexpr int NUM_SEATS = 100;

	virtual ~IHall() {}

	virtual int getHallNumber() const = 0;
	virtual void setHallNumber(int num) = 0;

	virtual const Movie& getCurrentMovie() const = 0;

	virtual bool isSeatTaken(int seatIndex) const = 0;
	virtual int countTakenSeats() const = 0;
	virtual void takeSeat(int seatIndex) = 0;
	virtual void freeSeat(int seatIndex) = 0;

	virtual bool operator!() const = 0;

	virtual void toOs(ostream& os) const = 0;
};

inline ostream& operator<<(ostream& os, const IHall& h)
{
	os << "[" << h.getHallNumber() << ", " << h.getCurrentMovie();
	h.toOs(os);
	os << "]";
	return os;
}

#endif