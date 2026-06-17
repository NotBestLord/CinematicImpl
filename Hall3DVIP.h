#ifndef HALL3DVIP_H
#define HALL3DVIP_H

#include "VIPHall.h"
#include "Hall3D.h"

class Hall3DVIP : public VIPHall, public Hall3D {
public:
    Hall3DVIP(int hallNumber, Movie& currentMovie, int waitersCount, int glassesCount);
    Hall3DVIP(const Hall3DVIP& other);
    Hall3DVIP& operator=(const Hall3DVIP& other) = delete;

	void toOs(ostream& os) const override;
};

#endif
