#ifndef VIP_DECORATOR_H
#define VIP_DECORATOR_H

#include "HallDecorator.h"

class VIPDecorator : public HallDecorator {
	int waitersCount;
public:
	VIPDecorator(unique_ptr<IHall> wrappee, int waitersCount)
		: HallDecorator(std::move(wrappee)), waitersCount(waitersCount) {
	}

	int getWaitersCount() const { return waitersCount; }
	void setWaitersCount(int c) { waitersCount = c; }

	void toOs(ostream& os) const override;
};

#endif