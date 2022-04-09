#pragma once
#include "includes.h"

// create tutor class doubly linked list with int:tutorId, string:tutorName, string:ICNo, string:tutorAddress, string:tutorPhoneNumber,
// string:dateJoined, string:dateTerminated, int:totalRatings, int:ratingCount, int:centreId, int:subjectId
class Tutor
{
public:
    int tutorId;
    std::string tutorName;
    std::string ICNo;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    std::string dateJoined;
    std::string dateTerminated;
    int totalRatings;
    int ratingCount;
    int centreId;
    int subjectId;
    Tutor *nextAddress;
    Tutor *previousAddress;

    // constructor
    Tutor(int tutorId, std::string tutorName, std::string ICNo, std::string tutorAddress, std::string tutorPhoneNumber, std::string dateJoined, std::string dateTerminated, int totalRatings, int ratingCount, int centreId, int subjectId)
    {
        this->tutorId = tutorId;
        this->tutorName = tutorName;
        this->ICNo = ICNo;
        this->tutorAddress = tutorAddress;
        this->tutorPhoneNumber = tutorPhoneNumber;
        this->dateJoined = dateJoined;
        this->dateTerminated = dateTerminated;
        this->totalRatings = totalRatings;
        this->ratingCount = ratingCount;
        this->centreId = centreId;
        this->subjectId = subjectId;
        this->nextAddress = nullptr;
        this->previousAddress = nullptr;
    }
} *tutorHead = NULL;