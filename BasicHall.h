// BasicHall.h
#ifndef BASIC_HALL_H
#define BASIC_HALL_H

#include "IHall.h"
#include <array>

class BasicHall : public IHall {
private:
	int hallNumber;
	array<bool, NUM_SEATS> seats;
	const Movie& currentMovie;

public:
	BasicHall(int hallNumber, const Movie& currentMovie);

	int getHallNumber() const override { return hallNumber; }
	void setHallNumber(int num) override { hallNumber = num; }

	const Movie& getCurrentMovie() const override { return currentMovie; }

	bool isSeatTaken(int seatIndex) const override { return seats[seatIndex]; }
	int countTakenSeats() const override;
	void takeSeat(int seatIndex) override;
	void freeSeat(int seatIndex) override;

	bool operator!() const override;

	void toOs(ostream& os) const override {}   // nothing extra for a plain hall
};

#endif