#ifndef HALL3DVIP_H
#define HALL3DVIP_H

#include "VIPHall.h"
#include "Hall3D.h"

class Hall3DVIP : public VIPHall, public Hall3D {
public:
    Hall3DVIP(int hallNumber, const Movie& currentMovie, int waitersCount, int glassesCount);

	void toOs(ostream& os) const override;
};

#endif
