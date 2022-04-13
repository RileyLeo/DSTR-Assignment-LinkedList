#pragma once
#include "includes.h"

// create centre class doubly linked list with int:centreId, string:centreName, string:centreLocation, int:adminId
class Centre
{
public:
    int id;
    std::string centreName;
    std::string centreLocation;
    int adminId;
    Centre *nextAddress = NULL;
    Centre *previousAddress = NULL;

    // constructor with parameters
    Centre(int id, std::string centreName, std::string centreLocation, int adminId)
    {
        this->id = id;
        this->centreName = centreName;
        this->centreLocation = centreLocation;
        this->adminId = adminId;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

    // displayCentreList
    void displayCentreList()
    {
        while (centreHead != NULL)
        {
            std::cout << "Centre ID: " << centreHead->id << std::endl;
            std::cout << "Centre Name: " << centreHead->centreName << std::endl;
            std::cout << "Centre Location: " << centreHead->centreLocation << std::endl;
            std::cout << "Admin ID: " << centreHead->adminId << std::endl
                      << std::endl;
            centreHead = centreHead->nextAddress;
        }
    }

} *centreHead = NULL, *centreTail = NULL;
