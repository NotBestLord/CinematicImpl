#ifndef REVIEWER_H
#define REVIEWER_H

#include "Guest.h"

using namespace std;

class Reviewer : public Guest {
private:
    string publicationName;

public:
    Reviewer(const string& name, int id, const Date& birthDate, const string& publicationName, int visitCount = 0);
    ~Reviewer() override = default;

    const string& getPublicationName() const { return publicationName; }
    void setPublicationName(const string& name);

    void toOs(std::ostream& os) const override;
};

#endif
