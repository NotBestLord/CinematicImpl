#include "Ticket.h"

double Ticket::calcFinalPrice() const
{
    return BASE_PRICE + (is3D ? THREE_D_SURCHARGE : 0.);
}

bool Ticket::operator>(const Ticket& other) const
{
    return calcFinalPrice() > other.calcFinalPrice();
}