#include "Customer.h"
#include "Date.h"

Customer::Customer(const char* name, int id, const Date& birthDate, int clubPoints, int visitCount) : Guest(name, id, birthDate, visitCount), clubPoints(clubPoints) {}

void Customer::toOs(ostream& os) const
{
	os << ", " << "Club Points: " << clubPoints;
}
