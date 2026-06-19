#ifndef VIPTICKET_H
#define VIPTICKET_H

#include "Ticket.h"

class VIPTicket : public Ticket {
private:
    bool includesMeal;

    static constexpr double VIP_SURCHARGE = 20;
    static constexpr double MEAL_PRICE = 30;

public:
    VIPTicket(const Movie& movie, bool is3D, bool includesMeal) :
            Ticket(movie, is3D), includesMeal(includesMeal) {}

    bool getIncludesMeal() const { return includesMeal; }
    void setIncludesMeal(bool m) { includesMeal = m; }

    double calcFinalPrice() const override;
};

#endif
