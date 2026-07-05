#ifndef HALL_BUILDER_H
#define HALL_BUILDER_H

#include "BasicHall.h"
#include "ThreeDDecorator.h"
#include "VIPDecorator.h"

class HallBuilderAbstract
{
public:
    virtual ~HallBuilderAbstract() = default;
    virtual IHall* build() = 0;
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
    IHall* build() override { return new BasicHall(hallNumber, currentMovie); }
};

class VIPHallBuilder : virtual public HallBuilder
{
protected:
    int waitersCount;
public:
    VIPHallBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), waitersCount(0) {}
    ~VIPHallBuilder() override = default;
    void setWaitersCount(int waitersCount) { this->waitersCount = waitersCount; }
    IHall* build() override
    {
	    return new VIPDecorator(new BasicHall(hallNumber, currentMovie), waitersCount);
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
    IHall* build() override
    {
	    return new ThreeDDecorator(new BasicHall(hallNumber, currentMovie), glassesCount);
    }
};

class Hall3DVIPBuilder : public VIPHallBuilder, public Hall3DBuilder
{
public:
    Hall3DVIPBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), 
        VIPHallBuilder(currentMovie), Hall3DBuilder(currentMovie) {}
    ~Hall3DVIPBuilder() override = default;
    IHall* build() override
	{
    	return new VIPDecorator(new ThreeDDecorator(new BasicHall(hallNumber, currentMovie), glassesCount), waitersCount);
	}
};

#endif