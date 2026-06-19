#include "Hall3DVIP.h"

Hall3DVIP::Hall3DVIP(int hallNumber, const Movie& currentMovie, int waitersCount, int glassesCount) :
	Hall(hallNumber, currentMovie),
	VIPHall(hallNumber, currentMovie, waitersCount),
	Hall3D(hallNumber, currentMovie, glassesCount) {}

void Hall3DVIP::toOs(ostream& os) const
{
	Hall3D::toOs(os);
	VIPHall::toOs(os);
}
