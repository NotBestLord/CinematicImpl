#include "VIPTicket.h"

double VIPTicket::calcFinalPrice() const
{
    return this->Ticket::calcFinalPrice() + VIP_SURCHARGE + (this->includesMeal ? MEAL_PRICE : 0.);
}