#include "Hall.h"

Hall::Hall(int hallNumber, Movie& currentMovie) : hallNumber(hallNumber), currentMovie(currentMovie) {}

Hall::Hall(const Hall& other) : hallNumber(other.hallNumber), currentMovie(other.currentMovie) {}

int Hall::countTakenSeats() const
{
	int count = 0;
	for (bool seat : seats)
	{
		if (seat) count++;
	}
	return count;
}

void Hall::takeSeat(int seatIndex)
{
	if (seatIndex >= 0 && seatIndex <= NUM_SEATS)
	{
		if (!seatIndex) seats[seatIndex] = true;
		else cout << "Chosen seat is already taken. Operation cancelled.";
	}
	else cout << "Seat number should be between 0 and " << NUM_SEATS << ". Operation cancelled.";
}

void Hall::freeSeat(int seatIndex)
{
	if (seatIndex >= 0 && seatIndex <= NUM_SEATS)
	{
		seats[seatIndex] = false;
	}
	else cout << "Seat number should be between 0 and " << NUM_SEATS << ". Operation cancelled.";
}

bool Hall::operator!() const
{
	for (bool seat : seats)
	{
		if (seat) return false;
	}
	return true;
}

ostream& operator<<(ostream& os, const Hall& h)
{
	os << "[" << h.hallNumber << ", " << h.currentMovie;
	h.toOs(os);
	os << "]";
	return os;
}
