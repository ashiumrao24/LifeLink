#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <string>

class DateUtils
{
public:
    static bool isEligible(const std::string& lastDonationDate);
};

#endif