#include "../include/match.h"

Match::Match(const Donor& donor, double distance)
{
    this->donor = donor;
    this->distance = distance;
}

Donor Match::getDonor() const
{
    return donor;
}

double Match::getDistance() const
{
    return distance;
}