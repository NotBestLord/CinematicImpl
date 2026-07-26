#ifndef GUEST_H
#define GUEST_H

#include <memory>
#include <list>
#include "Person.h"
#include "Ticket.h"

class Guest : public Person {
private:
    int visitCount;
    list<std::unique_ptr<Ticket>> tickets;
    int numTickets;

public:
    Guest(const string& name, int id, const Date& birthDate, int visitCount = 0);
    ~Guest() override = default;

    int getVisitCount() const { return visitCount; }
    int getNumTickets() const { return numTickets; }
    const Ticket* getTicket(int index) const;

    void setVisitCount(int v) { visitCount = v; }
    void incrementVisitCount() { visitCount++; }

    void addTicket(const Ticket& t);

	void toOs(std::ostream& os) const override;
};

#endif
