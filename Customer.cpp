#include "Customer.h"
#include "Date.h"

Customer::Customer(const char* name, int id, const Date& birthDate, int clubPoints, int visitCount) : Guest(name, id, visitCount), clubPoints(clubPoints) {}

Customer::Customer(const Customer& other) : Guest(other), clubPoints(other.clubPoints) {}

const Customer& Customer::operator=(const Customer& other)
{
	clubPoints = other.clubPoints;
	Guest::operator=(other);
	return *this;
}

void Customer::toOs(ostream& os) const
{
	os << ", " << "Club Points: " << clubPoints;
}
