#ifndef HALL_DECORATOR_H
#define HALL_DECORATOR_H

#include "IHall.h"

class HallDecorator : public IHall {
protected:
	unique_ptr<IHall> wrappee;

	explicit HallDecorator(unique_ptr<IHall> wrappee) : wrappee(std::move(wrappee)) {}

public:
	~HallDecorator() override = default;

	int getHallNumber() const override { return wrappee->getHallNumber(); }
	void setHallNumber(int num) override { wrappee->setHallNumber(num); }

	const Movie& getCurrentMovie() const override { return wrappee->getCurrentMovie(); }

	bool isSeatTaken(int seatIndex) const override { return wrappee->isSeatTaken(seatIndex); }
	int countTakenSeats() const override { return wrappee->countTakenSeats(); }
	void takeSeat(int seatIndex) override { wrappee->takeSeat(seatIndex); }
	void freeSeat(int seatIndex) override { wrappee->freeSeat(seatIndex); }

	bool operator!() const override { return !(*wrappee); }

	void toOs(ostream& os) const override { wrappee->toOs(os); }
};

#endif