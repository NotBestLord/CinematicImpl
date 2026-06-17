#include "Hall3DVIP.h"

Hall3DVIP::Hall3DVIP(int hallNumber, Movie& currentMovie, int waitersCount, int glassesCount) :
	Hall(hallNumber, currentMovie),
	VIPHall(hallNumber, currentMovie, waitersCount),
	Hall3D(hallNumber, currentMovie, glassesCount) {}

Hall3DVIP::Hall3DVIP(const Hall3DVIP& other) : Hall(other), VIPHall(other), Hall3D(other) {}

void Hall3DVIP::toOs(ostream& os) const
{
	Hall3D::toOs(os);
	VIPHall::toOs(os);
}
