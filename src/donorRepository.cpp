#include "../include/donorRepository.h"

#include <fstream>
#include <sstream>

using namespace std;

// =====================================
// Constructor
// =====================================

DonorRepository::DonorRepository()
{
    loadFromFile();
}

// =====================================
// Load Donors from File
// =====================================

void DonorRepository::loadFromFile()
{
    ifstream file("../data/donors.txt");

    if(!file.is_open())
    {
        return;
    }

    donors.clear();

    string line;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);

        string id;
        string name;
        string bloodGroup;
        string phone;
        string latitude;
        string longitude;
        string lastDonationDate;
        string available;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, bloodGroup, ',');
        getline(ss, phone, ',');
        getline(ss, latitude, ',');
        getline(ss, longitude, ',');
        getline(ss, lastDonationDate, ',');
        getline(ss, available, ',');

        donors.push_back(
            Donor(
                stoi(id),
                name,
                bloodGroup,
                phone,
                stod(latitude),
                stod(longitude),
                lastDonationDate,
                stoi(available)
            )
        );
    }

    file.close();
}

// =====================================
// Save Donors to File
// =====================================

void DonorRepository::saveToFile()
{
    ofstream file("../data/donors.txt");

    if(!file.is_open())
    {
        return;
    }

    for(const Donor& donor : donors)
    {
        file
            << donor.getDonorId() << ","
            << donor.getName() << ","
            << donor.getBloodGroup() << ","
            << donor.getPhone() << ","
            << donor.getLatitude() << ","
            << donor.getLongitude() << ","
            << donor.getLastDonationDate() << ","
            << donor.isAvailable()
            << endl;
    }

    file.close();
}

// =====================================
// Add Donor
// =====================================

void DonorRepository::addDonor(const Donor& donor)
{
    donors.push_back(donor);

    saveToFile();
}

// =====================================
// Get All Donors
// =====================================

vector<Donor>& DonorRepository::getAllDonors()
{
    return donors;
}