#ifndef HALL_FACTORY_H
#define HALL_FACTORY_H

#include "Hall.h"
#include "VIPHall.h"
#include "Hall3D.h"
#include "Hall3DVIP.h"

class HallBuilderAbstract
{
public:
    virtual ~HallBuilderAbstract() = default;
    virtual Hall* build() = 0;
};

class HallBuilder : public HallBuilderAbstract
{
protected:
    int hallNumber;
    Movie& currentMovie;
public:
    HallBuilder(Movie& currentMovie) : currentMovie(currentMovie) {}
    void setHallNumber(int hallNumber) { this->hallNumber = hallNumber; }
    Hall* build() override { return new Hall(hallNumber, currentMovie); }
};

class VIPHallBuilder : virtual public HallBuilder
{
protected:
    int waitersCount;
public:
    VIPHallBuilder(Movie& currentMovie) : HallBuilder(currentMovie) {}
    void setWaitersCount(int waitersCount) { this->waitersCount = waitersCount; }
    Hall* build() override { return new VIPHall(hallNumber, currentMovie, waitersCount); }
};

class Hall3DBuilder : virtual public HallBuilder
{
protected:
    int glassesCount;
public:
    Hall3DBuilder(Movie& currentMovie) : HallBuilder(currentMovie) {}
    void setGlassesCount(int glassesCount) { this->glassesCount = glassesCount; }
    Hall* build() override { return new Hall3D(hallNumber, currentMovie, glassesCount); }
};

class Hall3DVIPBuilder : public VIPHallBuilder, public Hall3DBuilder
{
public:
    Hall3DVIPBuilder(Movie& currentMovie) : HallBuilder(currentMovie), 
        VIPHallBuilder(currentMovie), Hall3DBuilder(currentMovie) {}
    Hall* build() override { return new Hall3DVIP(hallNumber, currentMovie, glassesCount, glassesCount); }
};

#endif