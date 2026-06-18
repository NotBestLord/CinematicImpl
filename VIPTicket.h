#ifndef VIPTICKET_H
#define VIPTICKET_H

#include "Ticket.h"

class VIPTicket : public Ticket {
private:
    bool includesMeal;

    static const double VIP_SURCHARGE;
    static const double MEAL_PRICE;

public:
    VIPTicket(const Movie& movie, bool is3D, bool includesMeal) :
            Ticket(movie, is3D), includesMeal(includesMeal) {};
    VIPTicket& operator=(const VIPTicket& other) = delete;

    bool getIncludesMeal() const { return includesMeal; };
    void setIncludesMeal(bool m) { includesMeal = m; };

    double calcFinalPrice() const override;
};

#endif
