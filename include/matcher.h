#ifndef MATCHER_H
#define MATCHER_H

#include "donor.h"
#include "request.h"

class Matcher
{
public:
    static bool isCompatible(
        const std::string& donorBlood,
        const std::string& requiredBlood
    );
};

#endif