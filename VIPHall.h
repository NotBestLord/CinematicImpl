#ifndef VIPHALL_H
#define VIPHALL_H

#include "Hall.h"

class VIPHall : virtual public Hall {
private:
    int waitersCount;

public:
    VIPHall(int hallNumber, Movie& currentMovie, int waitersCount);
    VIPHall(const VIPHall& other);
    VIPHall& operator=(const VIPHall& other) = delete;
    ~VIPHall() override;

    int getWaitersCount() const;
    void setWaitersCount(int c);

    void printHall() const override;
};

#endif
