#include "../include/requestRepository.h"

#include <fstream>
#include <sstream>

using namespace std;

// =====================================
// Constructor
// =====================================

RequestRepository::RequestRepository()
{
    loadFromFile();
}

// =====================================
// Load Requests
// =====================================

void RequestRepository::loadFromFile()
{
    ifstream file("../data/requests.txt");

    if(!file.is_open())
    {
        return;
    }

    requests.clear();

    string line;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);

        string requestId;
        string patientName;
        string bloodGroup;
        string hospitalName;
        string latitude;
        string longitude;
        string urgency;
        string status;

        getline(ss, requestId, ',');
        getline(ss, patientName, ',');
        getline(ss, bloodGroup, ',');
        getline(ss, hospitalName, ',');
        getline(ss, latitude, ',');
        getline(ss, longitude, ',');
        getline(ss, urgency, ',');
        getline(ss, status, ',');

        BloodRequest request(
            stoi(requestId),
            patientName,
            bloodGroup,
            hospitalName,
            stod(latitude),
            stod(longitude),
            urgency,
            status
        );

        requests.push_back(request);
        requestQueue.push(request);
    }

    file.close();
}

// =====================================
// Save Requests
// =====================================

void RequestRepository::saveToFile()
{
    ofstream file("../data/requests.txt");

    if(!file.is_open())
    {
        return;
    }

    for(const BloodRequest& request : requests)
    {
        file
            << request.getRequestId() << ","
            << request.getPatientName() << ","
            << request.getRequiredBloodGroup() << ","
            << request.getHospitalName() << ","
            << request.getLatitude() << ","
            << request.getLongitude() << ","
            << request.getUrgency() << ","
            << request.getStatus()
            << endl;
    }

    file.close();
}

// =====================================
// Add Request
// =====================================

void RequestRepository::addRequest(const BloodRequest& request)
{
    requests.push_back(request);
    requestQueue.push(request);

    saveToFile();
}

// =====================================
// Get All Requests
// =====================================

vector<BloodRequest>& RequestRepository::getAllRequests()
{
    return requests;
}

BloodRequest RequestRepository::getHighestPriorityRequest()
{
    BloodRequest request = requestQueue.top();

    requestQueue.pop();

    return request;
}

bool RequestRepository::hasPendingRequests() const
{
    return !requestQueue.empty();
}