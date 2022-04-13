#pragma once
#pragma warning(disable : 4996)
#include "includes.h"

// create tutor class doubly linked list with int:tutorId, string:tutorName, string:tutorAddress, string:tutorPhoneNumber,
// string:dateJoined, string:dateTerminated, int:totalRatings, int:ratingCount, int:centreId, int:subjectId
class Tutor
{
public:
    int id;
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    std::string dateJoined;
    std::string dateTerminated;
    int totalRatings;
    int ratingCount;
    int centreId;
    int subjectId;
    Tutor *nextAddress = NULL;
    Tutor *previousAddress = NULL;

    // constructor with parameters
    Tutor(int id, std::string tutorName, std::string tutorAddress, std::string tutorPhoneNumber,
          std::string dateJoined, std::string dateTerminated, int totalRatings, int ratingCount, int centreId,
          int subjectId)
    {
        this->id = id;
        this->tutorName = tutorName;
        this->tutorAddress = tutorAddress;
        this->tutorPhoneNumber = tutorPhoneNumber;
        this->dateJoined = dateJoined;
        this->dateTerminated = dateTerminated;
        this->totalRatings = totalRatings;
        this->ratingCount = ratingCount;
        this->centreId = centreId;
        this->subjectId = subjectId;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

    // displayTutorList
    void displayTutorList()
    {
        while (tutorHead != NULL)
        {
            std::cout << "Tutor ID: " << tutorHead->id << std::endl;
            std::cout << "Tutor Name: " << tutorHead->tutorName << std::endl;
            std::cout << "Tutor Address: " << tutorHead->tutorAddress << std::endl;
            std::cout << "Tutor Phone Number: " << tutorHead->tutorPhoneNumber << std::endl;
            std::cout << "Date Joined: " << tutorHead->dateJoined << std::endl;
            std::cout << "Date Terminated: " << tutorHead->dateTerminated << std::endl;
            std::cout << "Total Ratings: " << tutorHead->totalRatings << std::endl;
            std::cout << "Rating Count: " << tutorHead->ratingCount << std::endl;
            std::cout << "Centre ID: " << tutorHead->centreId << std::endl;
            std::cout << "Subject ID: " << tutorHead->subjectId << std::endl
                      << std::endl;
            tutorHead = tutorHead->nextAddress;
        }
    }

} *tutorHead = NULL, *tutorTail = NULL;
