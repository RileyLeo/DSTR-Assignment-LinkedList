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

} * centreHead, *centreTail;

// displayCentreList
void displayCentreList()
{
    Centre *current = centreHead;
    while (current != NULL)
    {
        std::cout << "Centre ID: " << current->id << std::endl;
        std::cout << "Centre Name: " << current->centreName << std::endl;
        std::cout << "Centre Location: " << current->centreLocation << std::endl;
        std::cout << "Admin ID: " << current->adminId << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}