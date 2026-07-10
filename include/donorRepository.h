#ifndef DONOR_REPOSITORY_H
#define DONOR_REPOSITORY_H

#include "donor.h"
#include <vector>

class DonorRepository
{
private:
    std::vector<Donor> donors;

public:
    DonorRepository();

    void loadFromFile();

    void saveToFile();

    void addDonor(const Donor& donor);

    std::vector<Donor>& getAllDonors();
};

#endif