#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

class DistanceCalculator
{
public:

    static double calculateDistance(
        double lat1,
        double lon1,
        double lat2,
        double lon2
    );
};

#endif