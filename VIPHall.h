#ifndef VIPHALL_H
#define VIPHALL_H

#include "Hall.h"

class VIPHall : virtual public Hall {
private:
    int waitersCount;

public:
    VIPHall(int hallNumber, Movie& currentMovie, int waitersCount) : 
            Hall(hallNumber, currentMovie), waitersCount(waitersCount) {};
    VIPHall& operator=(const VIPHall& other) = delete;

    int getWaitersCount() const { return waitersCount; };
    void setWaitersCount(int c) { waitersCount = c; };

    void toOs(std::ostream& os) const override;
};

#endif
