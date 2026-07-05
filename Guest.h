#ifndef GUEST_H
#define GUEST_H

#include "Linkedlist.h"
#include "Person.h"

class Ticket;

class Guest : public Person {
private:
    int visitCount;
    LinkedList<Ticket*> tickets;
    int numTickets;

public:
    Guest(const string& name, int id, const Date& birthDate, int visitCount = 0);
    virtual ~Guest() override;

    int getVisitCount() const { return visitCount; }
    int getNumTickets() const { return numTickets; }
    const Ticket* getTicket(int index) const;

    void setVisitCount(int v) { visitCount = v; }
    void incrementVisitCount() { visitCount++; }

    void addTicket(Ticket* t);

	void toOs(std::ostream& os) const override;
};

#endif
