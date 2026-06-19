#include "Guest.h"
#include "Date.h"
#include "Ticket.h"

using namespace std;

Guest::Guest(const char* name, int id, const Date& birthDate, int visitCount) : Person(name, id, birthDate), visitCount(visitCount)
{
	ticketsCapacity = INITIAL_TICKETS_CAPACITY;
	numTickets = 0;
	tickets = new Ticket*[ticketsCapacity];
}

Guest::~Guest()
{
	for (int i = 0; i < numTickets; i++)
	{
		delete tickets[i];
	}
	delete tickets;
}

const Ticket* Guest::getTicket(int index) const
{
	return tickets[index];
}

void Guest::addTicket(Ticket* t)
{
	if (numTickets == ticketsCapacity) resizeTickets();
	tickets[numTickets++] = t;
}


void Guest::resizeTickets()
{
	ticketsCapacity *= 2;
	Ticket** temp = new Ticket*[ticketsCapacity];
	for (int i = 0; i < numTickets; i++)
	{
		temp[i] = tickets[i];
	}
	delete[] tickets;
	tickets = temp;
}

void Guest::toOs(std::ostream& os) const
{
	os << ", " << "Visit Count: " << visitCount;
	os << numTickets << " owned tickets";
}