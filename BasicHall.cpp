#include "BasicHall.h"

BasicHall::BasicHall(int hallNumber, const Movie& currentMovie)
	: hallNumber(hallNumber), seats(), currentMovie(currentMovie) {
}

int BasicHall::countTakenSeats() const
{
	int count = 0;
	for (bool seat : seats) if (seat) count++;
	return count;
}

void BasicHall::takeSeat(int seatIndex)
{
	if (seatIndex >= 0 && seatIndex <= NUM_SEATS)
	{
		if (!isSeatTaken(seatIndex)) seats[seatIndex] = true;
		else cout << "Chosen seat is already taken. Operation cancelled.";
	}
	else cout << "Seat number should be between 0 and " << NUM_SEATS << ". Operation cancelled.";
}

void BasicHall::freeSeat(int seatIndex)
{
	if (seatIndex >= 0 && seatIndex <= NUM_SEATS) seats[seatIndex] = false;
	else cout << "Seat number should be between 0 and " << NUM_SEATS << ". Operation cancelled.";
}

bool BasicHall::operator!() const
{
	for (bool seat : seats) if (seat) return false;
	return true;
}