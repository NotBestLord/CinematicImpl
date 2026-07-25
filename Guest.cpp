#include "Guest.h"
#include "Date.h"
#include "Ticket.h"

using namespace std;

Guest::Guest(const string& name, int id, const Date& birthDate, int visitCount) : 
	Person(name, id, birthDate), visitCount(visitCount), numTickets(0)
{
}

const Ticket* Guest::getTicket(int index) const
{
	return tickets[index].get();
}

void Guest::addTicket(unique_ptr<Ticket> t)
{
	tickets += std::move(t);
	numTickets++;
}

void Guest::toOs(ostream& os) const
{
	os << ", Visit Count: " << visitCount;
	os << numTickets << " owned tickets";
}