#ifndef THREE_D_DECORATOR_H
#define THREE_D_DECORATOR_H

#include "HallDecorator.h"

class ThreeDDecorator : public HallDecorator {
	int glassesCount;
public:
	ThreeDDecorator(unique_ptr<IHall> wrappee, int glassesCount)
		: HallDecorator(std::move(wrappee)), glassesCount(glassesCount) {
	}

	int getGlassesCount() const { return glassesCount; }
	void setGlassesCount(int c) { glassesCount = c; }

	void toOs(ostream& os) const override;
};

#endif