#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Guest.h"
#include <iostream>

using namespace std;

class Customer : public Guest {
private:
    int clubPoints;

public:
	Customer(const char* name, int id, const Date& birthDate, int clubPoints = 0, int visitCount = 0);

	int getClubPoints() const { return clubPoints; }
    void setClubPoints(int p) { clubPoints = p; }
	void addClubPoints(int p) { clubPoints += p; }

	virtual void toOs(ostream& os) const override;
};

#endif
