#include "VIPHall.h"

using namespace std;

void VIPHall::toOs(ostream& os) const
{
    os << ", " << waitersCount << "| VIP";
}
