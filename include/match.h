#ifndef MATCH_H
#define MATCH_H

#include "donor.h"

class Match
{
private:
    Donor donor;
    double distance;

public:
    Match(const Donor& donor, double distance);

    Donor getDonor() const;
    double getDistance() const;
};

#endif