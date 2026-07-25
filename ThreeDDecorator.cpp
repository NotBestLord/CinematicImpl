#include "ThreeDDecorator.h"

void ThreeDDecorator::toOs(ostream& os) const
{
	wrappee->toOs(os);
	os << ", " << glassesCount << " glasses";
}