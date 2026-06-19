#ifndef HALL3D_H
#define HALL3D_H

#include "Hall.h"

class Hall3D : virtual public Hall {
private:
    int glassesCount;

public:
    Hall3D(int hallNumber, const Movie& currentMovie, int glassesCount);

    int getGlassesCount() const { return glassesCount; }
    void setGlassesCount(int c) { glassesCount = c; }

	void toOs(ostream& os) const override;
};

#endif
