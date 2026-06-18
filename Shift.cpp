#include "Shift.h"

using namespace std;

ostream& operator<<(ostream& os, const Shift& p)
{
    os << "[" << p.shiftDate << ", " << p.shiftLength << ", " << p.workerRef << "]";
    return os;
}