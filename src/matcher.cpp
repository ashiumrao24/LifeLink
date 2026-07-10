#include "../include/matcher.h"

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool Matcher::isCompatible(const string& donorBlood,
                           const string& requiredBlood)
{
    unordered_map<string, vector<string>> compatibility = {

        {"O-", {"O-"}},

        {"O+", {"O+", "O-"}},

        {"A-", {"A-", "O-"}},

        {"A+", {"A+", "A-", "O+", "O-"}},

        {"B-", {"B-", "O-"}},

        {"B+", {"B+", "B-", "O+", "O-"}},

        {"AB-", {"AB-", "A-", "B-", "O-"}},

        {"AB+", {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"}}
    };

    auto it = compatibility.find(requiredBlood);

    if(it == compatibility.end())
        return false;

    return find(
            it->second.begin(),
            it->second.end(),
            donorBlood
        ) != it->second.end();
}