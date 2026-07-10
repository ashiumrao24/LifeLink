#include "../include/donor.h"
#include <iostream>

using namespace std;

// Default Constructor
Donor::Donor()
{
    donorId = 0;
    name = "";
    bloodGroup = "";
    phone = "";
    latitude = 0.0;
    longitude = 0.0;
    lastDonationDate = "";
    available = true;
}

// Parameterized Constructor
Donor::Donor(
    int donorId,
    const string& name,
    const string& bloodGroup,
    const string& phone,
    double latitude,
    double longitude,
    const string& lastDonationDate,
    bool available
)
{
    this->donorId = donorId;
    this->name = name;
    this->bloodGroup = bloodGroup;
    this->phone = phone;
    this->latitude = latitude;
    this->longitude = longitude;
    this->lastDonationDate = lastDonationDate;
    this->available = available;
}

// Display Donor Information
void Donor::display() const
{
    cout << "Donor ID: " << donorId << endl;
    cout << "Name: " << name << endl;
    cout << "Blood Group: " << bloodGroup << endl;
    cout << "Phone: " << phone << endl;
    cout << "Location: (" << latitude << ", " << longitude << ")" << endl;
    cout << "Last Donation: " << lastDonationDate << endl;
    cout << "Available: " << (available ? "Yes" : "No") << endl;
}

int Donor::getDonorId() const
{
    return donorId;
}

string Donor::getName() const
{
    return name;
}

string Donor::getBloodGroup() const
{
    return bloodGroup;
}

string Donor::getPhone() const
{
    return phone;
}

double Donor::getLatitude() const
{
    return latitude;
}

double Donor::getLongitude() const
{
    return longitude;
}

string Donor::getLastDonationDate() const
{
    return lastDonationDate;
}

bool Donor::isAvailable() const
{
    return available;
}