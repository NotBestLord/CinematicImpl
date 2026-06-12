#ifndef VIPTICKET_H
#define VIPTICKET_H

#include "Ticket.h"

class VIPTicket : public Ticket {
private:
    bool includesMeal;

    static const double VIP_SURCHARGE;
    static const double MEAL_PRICE;

public:
    VIPTicket(const Movie& movie, bool is3D, bool includesMeal);
    VIPTicket(const VIPTicket& other);
    VIPTicket& operator=(const VIPTicket& other) = delete;
    ~VIPTicket() override;

    bool getIncludesMeal() const { return includesMeal; };
    void setIncludesMeal(bool m) { includesMeal = m; };

    double calcFinalPrice() const override;
};

#endif
