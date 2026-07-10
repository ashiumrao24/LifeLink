#ifndef REQUEST_REPOSITORY_H
#define REQUEST_REPOSITORY_H

#include "request.h"
#include <vector>
#include <queue>

class RequestRepository
{
private:
    std::vector<BloodRequest> requests;
    std::priority_queue<BloodRequest> requestQueue;

public:
    RequestRepository();

    void loadFromFile();

    void saveToFile();

    void addRequest(const BloodRequest& request);

    std::vector<BloodRequest>& getAllRequests();

    BloodRequest getHighestPriorityRequest();

    bool hasPendingRequests() const;
};

#endif