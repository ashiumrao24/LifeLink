#include "../include/request.h"
#include <iostream>

using namespace std;

// Default Constructor
BloodRequest::BloodRequest()
{
    requestId = 0;
    patientName = "";
    requiredBloodGroup = "";
    hospitalName = "";
    latitude = 0.0;
    longitude = 0.0;
    urgency = "";
    status = "";
}

// Parameterized Constructor
BloodRequest::BloodRequest(
    int requestId,
    const string& patientName,
    const string& requiredBloodGroup,
    const string& hospitalName,
    double latitude,
    double longitude,
    const string& urgency,
    const string& status)
{
    this->requestId = requestId;
    this->patientName = patientName;
    this->requiredBloodGroup = requiredBloodGroup;
    this->hospitalName = hospitalName;
    this->latitude = latitude;
    this->longitude = longitude;
    this->urgency = urgency;
    this->status = status;
}

// Display Function
void BloodRequest::display() const
{
    cout << "Request ID: " << requestId << endl;
    cout << "Patient Name: " << patientName << endl;
    cout << "Required Blood Group: " << requiredBloodGroup << endl;
    cout << "Hospital: " << hospitalName << endl;
    cout << "Location: (" << latitude << ", " << longitude << ")" << endl;
    cout << "Urgency: " << urgency << endl;
    cout << "Status: " << status << endl;
}

int BloodRequest::getRequestId() const
{
    return requestId;
}

string BloodRequest::getPatientName() const
{
    return patientName;
}

string BloodRequest::getRequiredBloodGroup() const
{
    return requiredBloodGroup;
}

string BloodRequest::getHospitalName() const
{
    return hospitalName;
}

double BloodRequest::getLatitude() const
{
    return latitude;
}

double BloodRequest::getLongitude() const
{
    return longitude;
}

string BloodRequest::getUrgency() const
{
    return urgency;
}

string BloodRequest::getStatus() const
{
    return status;
}

bool BloodRequest::operator<(const BloodRequest& other) const
{
    auto priority = [](const std::string& urgency)
    {
        if(urgency == "Critical") return 3;
        if(urgency == "Urgent") return 2;
        return 1;
    };

    return priority(urgency) < priority(other.urgency);
}