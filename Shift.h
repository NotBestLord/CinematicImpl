#ifndef SHIFT_H
#define SHIFT_H

#include "Employee.h"
#include "Date.h"

class Shift {
private:
    const Employee& workerRef;
    int shiftLength;
    Date shiftDate;

public:
    Shift(const Employee& worker, int shiftLength, const Date& shiftDate) :
            workerRef(worker), shiftLength(shiftLength), shiftDate(shiftDate) {};
    Shift& operator=(const Shift& other) = delete;

    const Employee& getWorker() const { return workerRef; };
    int getShiftLength() const { return shiftLength; };
    const Date& getShiftDate() const { return shiftDate; };

    void setShiftLength(int hours) { shiftLength = hours; };

    friend std::ostream& operator<<(std::ostream& os, const Shift& p);
};

#endif
