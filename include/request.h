#ifndef REQUEST_H
#define REQUEST_H

#include <string>

class BloodRequest
{
private:
    int requestId;
    std::string patientName;
    std::string requiredBloodGroup;
    std::string hospitalName;
    double latitude;
    double longitude;
    std::string urgency;
    std::string status;

public:
    BloodRequest();

    BloodRequest(
        int requestId,
        const std::string& patientName,
        const std::string& requiredBloodGroup,
        const std::string& hospitalName,
        double latitude,
        double longitude,
        const std::string& urgency,
        const std::string& status
    );

    void display() const;

    int getRequestId() const;
    std::string getPatientName() const;
    std::string getRequiredBloodGroup() const;
    std::string getHospitalName() const;
    double getLatitude() const;
    double getLongitude() const;
    std::string getUrgency() const;
    std::string getStatus() const;

    bool operator<(const BloodRequest& other) const;
};

#endif