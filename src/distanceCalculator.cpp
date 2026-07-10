#include "../include/distanceCalculator.h"

#include <cmath>

using namespace std;

double DistanceCalculator::calculateDistance(
    double lat1,
    double lon1,
    double lat2,
    double lon2)
{
    const double PI = 3.14159265358979323846;
    const double EARTH_RADIUS = 6371.0;

    double dLat = (lat2 - lat1) * PI / 180.0;
    double dLon = (lon2 - lon1) * PI / 180.0;

    lat1 = lat1 * PI / 180.0;
    lat2 = lat2 * PI / 180.0;

    double a =
        sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1) * cos(lat2) *
        sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return EARTH_RADIUS * c;
}