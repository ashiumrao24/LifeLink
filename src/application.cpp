#include "../include/application.h"
#include "../include/matchingEngine.h"
#include "../include/match.h"
#include "../include/inputHelper.h"

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void Application::showMenu()
{
    cout << "\n=========================================\n";
    cout << "          LifeLink\n";
    cout << " Blood Donation Matching System\n";
    cout << "=========================================\n";

    cout << "1. Register Donor\n";
    cout << "2. View Donors\n";
    cout << "3. Create Blood Request\n";
    cout << "4. Find Best Matches\n";
    cout << "5. Exit\n";

    cout << "\nEnter Choice : ";
}
void Application::run()
{
    int choice;

    do
    {
        showMenu();

        cin >> choice;

        switch(choice)
        {
            case 1:
                registerDonor();
                break;

            case 2:
                viewDonors();
                break;

            case 3:
                createBloodRequest();
                break;

            case 4:
                findBestMatches();
                break;

            case 5:
                cout << "\nThank you for using LifeLink.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}
// ===============================
// Menu Option 1
// ===============================

void Application::registerDonor()
{
    int donorId;
    string name;
    string bloodGroup;
    string phone;
    double latitude;
    double longitude;
    string lastDonationDate;
    bool available;

    cout << "\n========== Register Donor ==========\n";

    cout << "Donor ID: ";
    cin >> donorId;

    cin.ignore();

    cout << "Name: ";
    getline(cin, name);

    bloodGroup = InputHelper::getBloodGroup();
    cin.ignore();

    cout << "Phone: ";
    getline(cin, phone);

    cout << "Latitude: ";
    cin >> latitude;

    cout << "Longitude: ";
    cin >> longitude;

    cin.ignore();

    cout << "Last Donation Date (YYYY-MM-DD): ";
    getline(cin, lastDonationDate);

    cout << "Available (1 = Yes, 0 = No): ";
    cin >> available;

    Donor donor(
        donorId,
        name,
        bloodGroup,
        phone,
        latitude,
        longitude,
        lastDonationDate,
        available
    );

    donorRepository.addDonor(donor);

    cout << "\n✅ Donor Registered Successfully!\n";
}

// ===============================
// Menu Option 2
// ===============================

void Application::viewDonors()
{
    auto& donors = donorRepository.getAllDonors();

    if(donors.empty())
    {
        cout << "\nNo donors registered.\n";
        return;
    }

    cout << "\n========== Donor List ==========\n\n";

    for(const Donor& donor : donors)
    {
        donor.display();
        cout << "-----------------------------\n";
    }
}

// ===============================
// Menu Option 3
// ===============================

void Application::createBloodRequest()
{
    int requestId;
    string patientName;
    string bloodGroup;
    string hospital;
    double latitude;
    double longitude;
    string urgency;
    string status;

    cout << "\n========== Create Blood Request ==========\n";

    cout << "Request ID: ";
    cin >> requestId;

    cin.ignore();

    cout << "Patient Name: ";
    getline(cin, patientName);

    bloodGroup = InputHelper::getBloodGroup();
    cin.ignore();

    cout << "Hospital Name: ";
    getline(cin, hospital);

    cout << "Hospital Latitude: ";
    cin >> latitude;

    cout << "Hospital Longitude: ";
    cin >> longitude;

    cin.ignore();

    cout << "Urgency (Routine/Urgent/Critical): ";
    getline(cin, urgency);

    status = "Pending";

    BloodRequest request(
        requestId,
        patientName,
        bloodGroup,
        hospital,
        latitude,
        longitude,
        urgency,
        status
    );

    requestRepository.addRequest(request);

    cout << "\n✅ Blood Request Created Successfully!\n";
}

// ===============================
// Menu Option 4
// ===============================

void Application::findBestMatches()
{
    auto& donors = donorRepository.getAllDonors();
    auto& requests = requestRepository.getAllRequests();

    if(donors.empty())
    {
        cout << "\nNo donors registered.\n";
        return;
    }

    if(requests.empty())
    {
        cout << "\nNo blood requests found.\n";
        return;
    }

    MatchingEngine engine;

    // Use the latest request
    if(!requestRepository.hasPendingRequests())
    {
        cout << "\nNo pending requests.\n";
        return;
    }

    BloodRequest request =
        requestRepository.getHighestPriorityRequest();

    cout << "\n====================================\n";
    cout << "Processing Request\n";
    cout << "====================================\n";

    request.display();

    cout << endl;

    vector<Match> matches =
        engine.findBestMatches(donors, request);

    if(matches.empty())
    {
        cout << "\nNo matching donors found.\n";
        return;
    }

    cout << "\n====================================\n";
    cout << "      MATCHING DONORS\n";
    cout << "====================================\n\n";

    int limit = std::min(5, (int)matches.size());

    for(int i = 0; i < limit; i++)
    {
        cout << "\nRank #" << i + 1 << "\n";

        matches[i].getDonor().display();

        cout << "Distance : "
            << matches[i].getDistance()
            << " km\n";

        cout << "-----------------------------------\n";
    }
}