#ifndef HALL_BUILDER_H
#define HALL_BUILDER_H

#include "Hall.h"
#include "VIPHall.h"
#include "Hall3D.h"
#include "Hall3DVIP.h"

class HallBuilderAbstract
{
public:
    virtual ~HallBuilderAbstract() = 0;
    virtual Hall* build() = 0;
};

class HallBuilder : public HallBuilderAbstract
{
protected:
    int hallNumber;
    const Movie& currentMovie;
public:
    HallBuilder(const Movie& currentMovie) : currentMovie(currentMovie) {}
    ~HallBuilder() override = default;
    void setHallNumber(int hallNumber) { this->hallNumber = hallNumber; }
    Hall* build() override { return new Hall(hallNumber, currentMovie); }
};

class VIPHallBuilder : virtual public HallBuilder
{
protected:
    int waitersCount;
public:
    VIPHallBuilder(const Movie& currentMovie) : HallBuilder(currentMovie) {}
    ~VIPHallBuilder() override = default;
    void setWaitersCount(int waitersCount) { this->waitersCount = waitersCount; }
    Hall* build() override { return new VIPHall(hallNumber, currentMovie, waitersCount); }
};

class Hall3DBuilder : virtual public HallBuilder
{
protected:
    int glassesCount;
public:
    Hall3DBuilder(const Movie& currentMovie) : HallBuilder(currentMovie) {}
    ~Hall3DBuilder() override = default;
    void setGlassesCount(int glassesCount) { this->glassesCount = glassesCount; }
    Hall* build() override { return new Hall3D(hallNumber, currentMovie, glassesCount); }
};

class Hall3DVIPBuilder : public VIPHallBuilder, public Hall3DBuilder
{
public:
    Hall3DVIPBuilder(const Movie& currentMovie) : HallBuilder(currentMovie), 
        VIPHallBuilder(currentMovie), Hall3DBuilder(currentMovie) {}
    ~Hall3DVIPBuilder() override = default;
    Hall* build() override { return new Hall3DVIP(hallNumber, currentMovie, glassesCount, glassesCount); }
};

#endif