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
} * tutorHead, *tutorTail;

// displayTutorList
void displayTutorList()
{
    // if tutor list is empty
    if (tutorHead == NULL)
    {
        std::cout << "Tutor list is empty" << std::endl;
        return;
    }

    Tutor *current = tutorHead;
    while (current != NULL)
    {
        std::cout << "Tutor ID: " << current->id << std::endl;
        std::cout << "Tutor Name: " << current->tutorName << std::endl;
        std::cout << "Tutor Address: " << current->tutorAddress << std::endl;
        std::cout << "Tutor Phone Number: " << current->tutorPhoneNumber << std::endl;
        std::cout << "Date Joined: " << current->dateJoined << std::endl;
        std::cout << "Date Terminated: " << current->dateTerminated << std::endl;
        std::cout << "Total Ratings: " << current->totalRatings << std::endl;
        std::cout << "Rating Count: " << current->ratingCount << std::endl;
        std::cout << "Centre ID: " << current->centreId << std::endl;
        std::cout << "Subject ID: " << current->subjectId << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}