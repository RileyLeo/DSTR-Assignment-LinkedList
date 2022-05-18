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
// void displayArchiveList()
// {
//     system("cls");
//     // if tutor list is empty
//     if (archiveHead == NULL)
//     {
//         std::cout << "Archive list is empty" << std::endl
//                   << std::endl;
//         return;
//     }

//     Archive *current = archiveHead;
//     while (current != NULL)
//     {
//         std::cout << "Tutor ID: " << current->id << std::endl;
//         std::cout << "Tutor Name: " << current->tutorName << std::endl;
//         std::cout << "Tutor Address: " << current->tutorAddress << std::endl;
//         std::cout << "Tutor Phone Number: " << current->tutorPhoneNumber << std::endl;
//         std::cout << "Date Joined: " << current->dateJoined << std::endl;
//         std::cout << "Date Terminated: " << current->dateTerminated << std::endl;
//         std::cout << "Total Ratings: " << current->totalRatings << std::endl;
//         std::cout << "Rating Count: " << current->ratingCount << std::endl;
//         std::cout << "Centre ID: " << current->centreId << std::endl;
//         std::cout << "Subject ID: " << current->subjectId << std::endl;
//         std::cout << std::endl
//                   << std::endl;
//         current = current->nextAddress;
//     }
//     delete current;
// }

void displayArchiveList()
{
    system("cls");
    Archive *current = archiveHead;
    Archive *oneBeforeCurrent = NULL;
    int count = 0;
    int index;
    int skips = 0;
    int page = 1;
    float ratings;
    while (true)
    {
        while (current != NULL)
        {
            if (current->ratingCount == 0)
            {
                ratings = 0;
            }
            else
            {
                ratings = float(current->totalRatings) / float(current->ratingCount);
            }
            if (count == 0)
            {
                std::cout << "Tutor archive list - Page " << page << std::endl;
                std::cout << std::setw(237) << std::setfill('=') << "" << std::endl;
                std::cout << std::setw(6) << std::setfill(' ') << "No.";
                std::cout << std::setw(11) << std::setfill(' ') << "Tutor ID";
                std::cout << std::setw(21) << std::setfill(' ') << "Tutor Name";
                std::cout << std::setw(31) << std::setfill(' ') << "Tutor Address";
                std::cout << std::setw(16) << std::setfill(' ') << "Phone Number";
                std::cout << std::setw(13) << std::setfill(' ') << "Dated Joined";
                std::cout << std::setw(17) << std::setfill(' ') << "Dated Terminated";
                std::cout << std::setw(11) << std::setfill(' ') << "Ratings";
                std::cout << std::setw(11) << std::setfill(' ') << "Centre ID";
                std::cout << std::setw(26) << std::setfill(' ') << "Centre Name";
                std::cout << std::setw(11) << std::setfill(' ') << "Subject ID";
                std::cout << std::setw(16) << std::setfill(' ') << "Subject Name";
                std::cout << std::setw(17) << std::setfill(' ') << "Hourly Pay Rate" << std::endl;
                std::cout << std::setw(237) << std::setfill('=') << "" << std::endl;
            }
            count++;
            index = ((page * 10) - 10 + count);
            std::cout << std::setw(5) << std::setfill(' ') << index << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->id << " ";
            std::cout << std::setw(20) << std::setfill(' ') << current->tutorName << " ";
            std::cout << std::setw(30) << std::setfill(' ') << current->tutorAddress << " ";
            std::cout << std::setw(15) << std::setfill(' ') << current->tutorPhoneNumber << " ";
            std::cout << std::setw(12) << std::setfill(' ') << current->dateJoined << " ";
            std::cout << std::setw(16) << std::setfill(' ') << current->dateTerminated;
            std::cout << std::setw(10) << std::setfill(' ') << std::fixed << std::setprecision(2) << ratings << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->centreId << " ";
            std::cout << std::setw(25) << std::setfill(' ') << linearSearch(centreHead, centreTail, current->centreId)->centreName << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->subjectId << " ";
            std::cout << std::setw(15) << std::setfill(' ') << linearSearch(subjectHead, subjectTail, current->subjectId)->subjectName << " ";
            std::cout << std::setw(16) << std::setfill(' ') << linearSearch(subjectHead, subjectTail, current->subjectId)->hourlyPayRate << std::endl;

            oneBeforeCurrent = current;
            current = current->nextAddress;
            while (count == 10 || current == NULL)
            {
                if (count == 0)
                {
                    std::cout << "No records found!" << std::endl
                              << std::endl;
                    return;
                }
                std::cout << "Press 1 to continue or press 0 to exit or 2 to the previous page" << std::endl;
                int choice;
                std::cin >> choice;
                if (choice == 0)
                {
                    system("cls");
                    return;
                }
                else if (choice == 2)
                {
                    if (page == 1)
                    {
                        std::cout << "You are on the first page" << std::endl;
                    }
                    else
                    {
                        current = oneBeforeCurrent;
                        for (int i = 0; i < count + 9 + skips; i++)
                        {
                            current = current->previousAddress;
                        }
                        system("cls");
                        count = 0;
                        skips = 0;
                        page--;
                    }
                }
                else if (choice == 1)
                {
                    if (current == NULL)
                    {
                        std::cout << "You are on the Last page" << std::endl;
                    }
                    else
                    {
                        system("cls");
                        count = 0;
                        page++;
                    }
                }
                else
                {
                    std::cout << "Invalid input" << std::endl;
                }
            }
        }
    }
}
