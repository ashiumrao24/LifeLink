#include "../include/dateUtils.h"

#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

bool DateUtils::isEligible(const string& lastDonationDate)
{
    tm donationDate = {};

    stringstream ss(lastDonationDate);

    ss >> get_time(&donationDate, "%Y-%m-%d");

    if(ss.fail())
        return false;

    time_t donationTime = mktime(&donationDate);

    time_t currentTime = time(nullptr);

    double seconds = difftime(currentTime, donationTime);

    double days = seconds / (60 * 60 * 24);

    return days >= 90;
}