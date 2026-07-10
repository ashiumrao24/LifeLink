#ifndef MATCHING_ENGINE_H
#define MATCHING_ENGINE_H

#include "donor.h"
#include "request.h"
#include "match.h"

#include <vector>

class MatchingEngine
{
public:

    std::vector<Donor> getCompatibleDonors(
        const std::vector<Donor>& donors,
        const BloodRequest& request
    );

    std::vector<Donor> getAvailableDonors(
        const std::vector<Donor>& donors
    );

    std::vector<Match> rankByDistance(
        const std::vector<Donor>& donors,
        const BloodRequest& request
    );

    std::vector<Match> findBestMatches(
        const std::vector<Donor>& donors,
        const BloodRequest& request
    );

};

#endif