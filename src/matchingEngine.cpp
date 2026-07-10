#include "../include/matchingEngine.h"
#include "../include/matcher.h"
#include "../include/distanceCalculator.h"
#include "../include/dateUtils.h"

#include <algorithm>

using namespace std;

vector<Donor> MatchingEngine::getCompatibleDonors(
        const vector<Donor>& donors,
        const BloodRequest& request)
{
    vector<Donor> compatibleDonors;

    for(const Donor& donor : donors)
    {
        if(Matcher::isCompatible(
                donor.getBloodGroup(),
                request.getRequiredBloodGroup()))
        {
            compatibleDonors.push_back(donor);
        }
    }

    return compatibleDonors;
}

vector<Donor> MatchingEngine::getAvailableDonors(
        const vector<Donor>& donors)
{
    vector<Donor> availableDonors;

    for(const Donor& donor : donors)
    {
        if(donor.isAvailable() &&
           DateUtils::isEligible(donor.getLastDonationDate()))
        {
            availableDonors.push_back(donor);
        }
    }

    return availableDonors;
}

vector<Match> MatchingEngine::rankByDistance(
        const vector<Donor>& donors,
        const BloodRequest& request)
{
    vector<Match> rankedDonors;

    for(const Donor& donor : donors)
    {
        double distance =
            DistanceCalculator::calculateDistance(
                donor.getLatitude(),
                donor.getLongitude(),
                request.getLatitude(),
                request.getLongitude());

        rankedDonors.push_back(
            Match(donor, distance));
    }

    sort(
        rankedDonors.begin(),
        rankedDonors.end(),
        [](const Match& a, const Match& b)
        {
            return a.getDistance() < b.getDistance();
        });

    return rankedDonors;
}

vector<Match> MatchingEngine::findBestMatches(
        const vector<Donor>& donors,
        const BloodRequest& request)
{
    auto compatible =
        getCompatibleDonors(
            donors,
            request);

    auto available =
        getAvailableDonors(
            compatible);

    auto ranked =
        rankByDistance(
            available,
            request);

    return ranked;
}