#ifndef HALL_BUILDER_H
#define HALL_BUILDER_H

#include "BasicHall.h"
#include "ThreeDDecorator.h"
#include "VIPDecorator.h"

class HallBuilderAbstract
{
public:
    virtual ~HallBuilderAbstract() = default;
    virtual unique_ptr<IHall> build() = 0;
};

class HallBuilder : public HallBuilderAbstract
{
protected:
    int hallNumber;
    const Movie& currentMovie;
public:
    HallBuilder(const Movie& currentMovie) : hallNumber(0), currentMovie(currentMovie) {}
    ~HallBuilder() override = default;
    void setHallNumber(int hallNumber) { this->hallNumber = hallNumber; }
    unique_ptr<IHall> build() override { return make_unique<BasicHall>(hallNumber, currentMovie); }
};

class VIPHallBuilder : virtual public HallBuilder
{
protected:
    int waitersCount;
public:
    VIPHallBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), waitersCount(0) {}
    ~VIPHallBuilder() override = default;
    void setWaitersCount(int waitersCount) { this->waitersCount = waitersCount; }
    unique_ptr<IHall> build() override
    {
	    return make_unique<VIPDecorator>(make_unique<BasicHall>(hallNumber, currentMovie), waitersCount);
    }
};

class Hall3DBuilder : virtual public HallBuilder
{
protected:
    int glassesCount;
public:
    Hall3DBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), glassesCount(0) {}
    ~Hall3DBuilder() override = default;
    void setGlassesCount(int glassesCount) { this->glassesCount = glassesCount; }
    unique_ptr<IHall> build() override
    {
	    return make_unique<ThreeDDecorator>(make_unique<BasicHall>(hallNumber, currentMovie), glassesCount);
    }
};

class Hall3DVIPBuilder : public VIPHallBuilder, public Hall3DBuilder
{
public:
    Hall3DVIPBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), 
        VIPHallBuilder(currentMovie), Hall3DBuilder(currentMovie) {}
    ~Hall3DVIPBuilder() override = default;
    unique_ptr<IHall> build() override
	{
    	return make_unique<VIPDecorator>(
    		make_unique<ThreeDDecorator>(make_unique<BasicHall>(hallNumber, currentMovie), glassesCount),
    		waitersCount);
	}
};

#endif