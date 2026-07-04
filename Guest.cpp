#include "Guest.h"
#include "Date.h"
#include "Ticket.h"

using namespace std;

Guest::Guest(const char* name, int id, const Date& birthDate, int visitCount)
		: Person(name, id, birthDate), visitCount(visitCount), numTickets(0)
{
}

Guest::~Guest()
{
	for (int i = 0; i < numTickets; i++)
	{
		delete tickets[i];
	}
}

const Ticket* Guest::getTicket(int index) const
{
	return tickets[index];
}

void Guest::addTicket(Ticket* t)
{
	tickets += t;
	numTickets++;
}

void Guest::toOs(std::ostream& os) const
{
	os << ", " << "Visit Count: " << visitCount;
	os << numTickets << " owned tickets";
}