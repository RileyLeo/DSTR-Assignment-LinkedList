#pragma once
#include "includes.h"

// create centre class doubly linked list with int:centreId, string:centreName, string:centreLocation, int:adminId
class Centre
{
public:
    int centreId;
    std::string centreName;
    std::string centreLocation;
    int adminId;
    Centre *nextAddress;
    Centre *previousAddress;

    // constructor
    Centre(int centreId, std::string centreName, std::string centreLocation, int adminId)
    {
        this->centreId = centreId;
        this->centreName = centreName;
        this->centreLocation = centreLocation;
        this->adminId = adminId;
        this->nextAddress = nullptr;
        this->previousAddress = nullptr;
    }
} *centreHead = NULL;
