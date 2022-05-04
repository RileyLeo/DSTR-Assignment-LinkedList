#pragma once
#pragma warning(disable : 4996)
#include "includes.h"

class Archive
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
    Archive *nextAddress = NULL;
    Archive *previousAddress = NULL;

    // constructor with parameters
    Archive(int id, std::string tutorName, std::string tutorAddress, std::string tutorPhoneNumber,
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

    // constructor with typecast from tutor class
    Archive(Tutor *tutor)
    {
        this->id = tutor->id;
        this->tutorName = tutor->tutorName;
        this->tutorAddress = tutor->tutorAddress;
        this->tutorPhoneNumber = tutor->tutorPhoneNumber;
        this->dateJoined = tutor->dateJoined;
        this->dateTerminated = tutor->dateTerminated;
        this->totalRatings = tutor->totalRatings;
        this->ratingCount = tutor->ratingCount;
        this->centreId = tutor->centreId;
        this->subjectId = tutor->subjectId;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

} * archiveHead, *archiveTail;

// displayTutorList
void displayArchiveList()
{
    system("cls");
    // if tutor list is empty
    if (archiveHead == NULL)
    {
        std::cout << "Archive list is empty" << std::endl
                  << std::endl;
        return;
    }

    Archive *current = archiveHead;
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
        std::cout << "Subject ID: " << current->subjectId << std::endl;
        std::cout << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}
