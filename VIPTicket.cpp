#include "VIPTicket.h"

double VIPTicket::calcFinalPrice() const
{
    return Ticket::calcFinalPrice() + VIP_SURCHARGE + (includesMeal ? MEAL_PRICE : 0.);
}