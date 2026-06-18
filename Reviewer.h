#ifndef REVIEWER_H
#define REVIEWER_H

#include "Guest.h"

class Reviewer : public Guest {
private:
    char* publicationName;

public:
    Reviewer(const char* name, int id, const Date& birthDate, const char* publicationName, int visitCount = 0);
    Reviewer(const Reviewer& other);
    const Reviewer& operator=(const Reviewer& other);
    ~Reviewer() override;

    const char* getPublicationName() const { return publicationName; };
    void setPublicationName(const char* name);

    void toOs(std::ostream& os) const override;
};

#endif
