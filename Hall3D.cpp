#include "Hall3D.h"

Hall3D::Hall3D(int hallNumber, const Movie& currentMovie, int glassesCount) : Hall(hallNumber, currentMovie), glassesCount(glassesCount) {}

Hall3D::Hall3D(const Hall3D& other) : Hall(other), glassesCount(other.glassesCount) {}

void Hall3D::toOs(ostream& os) const
{
	os << ", " << "Glasses Count: " << glassesCount;
}
