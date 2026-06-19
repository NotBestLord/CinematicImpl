#ifndef GUEST_H
#define GUEST_H

#include "Person.h"

class Ticket;

class Guest : public Person {
public:
    static constexpr int INITIAL_TICKETS_CAPACITY = 4;

private:
    int visitCount;
    Ticket** tickets;
    int numTickets;
    int ticketsCapacity;

    void resizeTickets();

public:
    Guest(const char* name, int id, const Date& birthDate, int visitCount = 0);
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
