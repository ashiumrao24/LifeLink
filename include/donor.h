#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor {
private:
    int donorId;
    std::string name;
    std::string bloodGroup;
    std::string phone;
    double latitude;
    double longitude;
    std::string lastDonationDate;
    bool available;

public:
    Donor();

    Donor(
        int donorId,
        const std::string& name,
        const std::string& bloodGroup,
        const std::string& phone,
        double latitude,
        double longitude,
        const std::string& lastDonationDate,
        bool available
    );

    void display() const;
    int getDonorId() const;
    std::string getName() const;
    std::string getBloodGroup() const;
    std::string getPhone() const;
    double getLatitude() const;
    double getLongitude() const;
    std::string getLastDonationDate() const;
    bool isAvailable() const;
};

#endif