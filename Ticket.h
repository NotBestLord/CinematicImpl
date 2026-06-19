#ifndef TICKET_H
#define TICKET_H

#include "Movie.h"

class Ticket {
private:
    const Movie& movieRef;
    bool is3D;

    static constexpr double BASE_PRICE = 42;
    static constexpr double THREE_D_SURCHARGE = 20;

public:
    virtual ~Ticket() = default;
    Ticket(const Movie& movie, bool is3D) : movieRef(movie), is3D(is3D) {}

    const Movie& getMovie() const { return movieRef; }
    bool getIs3D() const { return is3D; }

    void setIs3D(bool flag) { is3D = flag; }

    virtual double calcFinalPrice() const;

    bool operator>(const Ticket& other) const;
};

#endif
