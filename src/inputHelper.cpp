#include "../include/inputHelper.h"

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

string InputHelper::getBloodGroup()
{
    vector<string> bloodGroups =
    {
        "O-","O+",
        "A-","A+",
        "B-","B+",
        "AB-","AB+"
    };

    int choice;

    while(true)
    {
        cout << "\nSelect Blood Group\n\n";

        for(int i = 0; i < bloodGroups.size(); i++)
        {
            cout << i + 1 << ". "
                 << bloodGroups[i]
                 << endl;
        }

        cout << "\nChoice: ";

        if(!(cin >> choice))
        {
            cout << "\nPlease enter a number between 1 and 8.\n";

            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        if(choice >= 1 && choice <= 8)
        {
            return bloodGroups[choice - 1];
        }

        cout << "\nInvalid choice. Try again.\n";
    }
}