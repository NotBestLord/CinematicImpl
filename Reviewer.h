#ifndef REVIEWER_H
#define REVIEWER_H

#include "Guest.h"

class Reviewer : public Guest {
private:
    std::string publicationName;

public:
    Reviewer(std::string name, int id, const Date& birthDate, std::string publicationName, int visitCount = 0);
    ~Reviewer() override = default;

    std::string getPublicationName() const { return publicationName; }
    void setPublicationName(std::string name);

    void toOs(std::ostream& os) const override;
};

#endif
