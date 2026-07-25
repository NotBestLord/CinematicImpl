#include "VIPDecorator.h"

void VIPDecorator::toOs(ostream& os) const
{
	wrappee->toOs(os);
	os << ", " << waitersCount << " waiters | VIP";
}