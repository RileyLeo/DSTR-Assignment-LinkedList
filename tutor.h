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
// void displayTutorList()
// {
//     system("cls");

//     // if tutor list is empty
//     if (tutorHead == NULL)
//     {
//         std::cout << "Tutor list is empty" << std::endl
//                   << std::endl;
//         return;
//     }

//     Tutor *current = tutorHead;
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
//         std::string centreName = linearSearch(centreHead, centreTail, current->centreId)->centreName;
//         std::cout << "Centre ID: " << current->centreId << " - " << centreName << std::endl;
//         std::string subjectName = linearSearch(subjectHead, subjectTail, current->subjectId)->subjectName;
//         std::cout << "Subject ID: " << current->subjectId << " - " << subjectName << std::endl;
//         std::cout << std::endl;
//         current = current->nextAddress;
//     }
//     delete current;
// }

// displayCentreList
void sortTutorById(int centreID)
{
    system("cls");
    Tutor *current = tutorHead;
    Tutor *oneBeforeCurrent = NULL;
    int count = 0;
    int index;
    int skips = 0;
    int page = 1;
    while (true)
    {
        while (current != NULL)
        {
            if (current->centreId == centreID || centreID == -1)
            {
                if (count == 0)
                {
                    std::cout << "Tutor list - Page " << page << std::endl;
                    std::cout << std::setw(170) << std::setfill('=') << "" << std::endl;
                    std::cout << std::setw(6) << std::setfill(' ') << "No.";
                    std::cout << std::setw(11) << std::setfill(' ') << "Tutor ID";
                    std::cout << std::setw(21) << std::setfill(' ') << "Tutor Name";
                    std::cout << std::setw(31) << std::setfill(' ') << "Tutor Address";
                    std::cout << std::setw(16) << std::setfill(' ') << "Phone Number";
                    std::cout << std::setw(21) << std::setfill(' ') << "Dated Joined";
                    std::cout << std::setw(21) << std::setfill(' ') << "Dated Terminated";
                    std::cout << std::setw(11) << std::setfill(' ') << "Ratings";
                    std::cout << std::setw(11) << std::setfill(' ') << "Centre ID";
                    std::cout << std::setw(11) << std::setfill(' ') << "Subject ID" << std::endl;
                    std::cout << std::setw(170) << std::setfill('=') << "" << std::endl;
                }
                count++;
                index = ((page * 10) - 10 + count);
                float ratings = (current->totalRatings / current->ratingCount);
                std::cout << std::setw(5) << std::setfill(' ') << index << " ";
                std::cout << std::setw(10) << std::setfill(' ') << current->id << " ";
                std::cout << std::setw(20) << std::setfill(' ') << current->tutorName << " ";
                std::cout << std::setw(30) << std::setfill(' ') << current->tutorAddress << " ";
                std::cout << std::setw(15) << std::setfill(' ') << current->tutorPhoneNumber << " ";
                std::cout << std::setw(20) << std::setfill(' ') << current->dateJoined << " ";
                std::cout << std::setw(20) << std::setfill(' ') << current->dateTerminated;
                std::cout << std::setw(10) << std::setfill(' ') << ratings << " ";
                std::cout << std::setw(10) << std::setfill(' ') << current->centreId << " ";
                std::cout << std::setw(10) << std::setfill(' ') << current->subjectId << " " << std::endl;
            } else
            {
                skips++;
            }

            oneBeforeCurrent = current;
            current = current->nextAddress;
            while (count == 10 || current == NULL)
            {
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

void displayTutor(Tutor *tutor)
{
    system("cls");

    // cout all the attributes
    std::cout << "Tutor ID: " << tutor->id << std::endl;
    std::cout << "Tutor Name: " << tutor->tutorName << std::endl;
    std::cout << "Tutor Address: " << tutor->tutorAddress << std::endl;
    std::cout << "Tutor Phone Number: " << tutor->tutorPhoneNumber << std::endl;
    std::cout << "Date Joined: " << tutor->dateJoined << std::endl;
    std::cout << "Date Terminated: " << tutor->dateTerminated << std::endl;
    std::cout << "Tutor Rating: " << tutor->totalRatings / tutor->ratingCount << std::endl;
    std::string centreName = linearSearch(centreHead, centreTail, tutor->centreId)->centreName;
    std::cout << "Centre ID: " << tutor->centreId << " - " << centreName << std::endl;
    std::string subjectName = linearSearch(subjectHead, subjectTail, tutor->subjectId)->subjectName;
    std::cout << "Subject ID: " << tutor->subjectId << " - " << subjectName << std::endl;
    std::cout << std::endl;
}

void searchTutorById()
{
    std::cout << std::endl
              << "Enter the id of the tutor to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Tutor *tutor = linearSearch(tutorHead, tutorTail, id);
    if (tutor != NULL)
    {
        displayTutor(tutor);
    }
    else
    {
        std::cout << "Tutor not found." << std::endl;
    }
    std::cout << std::endl;
}

void addTutor()
{
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    std::string dateJoined = getDateToday();
    std::string dateTerminated = "";
    int totalRatings = 0;
    int ratingCount = 0;
    int centreId;
    int subjectId;

    // get the input from the user
    std::cout << "Please enter the following to create a new tutor profile: " << std::endl;
    std::cout << "Tutor Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, tutorName);
    std::cout << "Tutor Address: ";
    std::getline(std::cin, tutorAddress);
    std::cout << "Tutor Phone Number: ";
    std::getline(std::cin, tutorPhoneNumber);
    std::cout << "Centre ID: ";
    std::cin >> centreId;

    while (!std::cin.good() || centreId < 0 || centreId > centreTail->id)
    {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Centre ID: ";
        std::cin >> centreId;
    }
    bool centreFlag = true;
    while (centreFlag)
    {
        Centre *centre = linearSearch(centreHead, centreTail, centreId);
        if (centre == NULL)
        {
            std::cout << "Centre not found. Please try again." << std::endl;
            std::cout << "Centre ID: ";
            std::cin >> centreId;
        }
        else
        {
            centreFlag = false;
        }
    }

    std::cout << "Subject ID: ";
    std::cin >> subjectId;
    while (!std::cin.good() || subjectId < 0 || subjectId > subjectTail->id)
    {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Subject ID: ";
        std::cin >> subjectId;
    }
    bool subjectFlag = true;
    while (subjectFlag)
    {
        Subject *subject = linearSearch(subjectHead, subjectTail, subjectId);
        if (subject == NULL)
        {
            std::cout << "Subject not found. Please try again." << std::endl;
            std::cout << "Subject ID: ";
            std::cin >> subjectId;
        }
        else
        {
            subjectFlag = false;
        }
    }

    // create a new tutor
    Tutor *newTutor = new Tutor((tutorTail != NULL) ? tutorTail->id + 1 : getListSize(tutorHead), tutorName, tutorAddress, tutorPhoneNumber, dateJoined, dateTerminated, totalRatings, ratingCount, centreId, subjectId);
    insertAtEnd(newTutor, tutorHead, tutorTail);
    std::cout << "New tutor profile created successfully" << std::endl
              << std::endl;
}

void updateTutor()
{
    std::string tutorName;
    std::string tutorAddress;
    std::string tutorPhoneNumber;
    int centreId;
    int subjectId;

    std::cout << "Enter id of tutor to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the tutor to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Tutor *tutor = linearSearch(tutorHead, tutorTail, id);

    if (tutor != NULL)
    {
        std::cout << "Updating subject: " << tutor->tutorName << std::endl;
        std::cout << "New Tutor Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, tutorName);
        std::cout << "New Tutor Address: ";
        std::getline(std::cin, tutorAddress);
        std::cout << "New Tutor Phone Number: ";
        std::getline(std::cin, tutorPhoneNumber);
        std::cout << "New Centre ID: ";
        std::cin >> centreId;

        while (!std::cin.good() || centreId < 0 || centreId > centreTail->id)
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "New Centre ID: ";
            std::cin >> centreId;
        }
        bool centreFlag = true;
        while (centreFlag)
        {
            Centre *centre = linearSearch(centreHead, centreTail, centreId);
            if (centre == NULL)
            {
                std::cout << "Centre not found. Please try again." << std::endl;
                std::cout << "New Centre ID: ";
                std::cin >> centreId;
            }
            else
            {
                centreFlag = false;
            }
        }

        std::cout << "New Subject ID: ";
        std::cin >> subjectId;
        while (!std::cin.good() || subjectId < 0 || subjectId > subjectTail->id)
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "New Subject ID: ";
            std::cin >> subjectId;
        }
        bool subjectFlag = true;
        while (subjectFlag)
        {
            Subject *subject = linearSearch(subjectHead, subjectTail, subjectId);
            if (subject == NULL)
            {
                std::cout << "Subject not found. Please try again." << std::endl;
                std::cout << "New Subject ID: ";
                std::cin >> subjectId;
            }
            else
            {
                subjectFlag = false;
            }
        }

        // update the tutor
        tutor->tutorName = tutorName;
        tutor->tutorAddress = tutorAddress;
        tutor->tutorPhoneNumber = tutorPhoneNumber;
        tutor->centreId = centreId;
        tutor->subjectId = subjectId;
        std::cout << "Tutor profile updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Tutor not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteTutor()
{
    std::cout << std::endl
              << "Enter the id of the tutor to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the subject to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    deleteNode(tutorHead, tutorTail, id);
    std::cout << std::endl;
}

void addRating()
{
    std::cout << "Enter the id of the tutor to rate: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to rate: ";
        std::cin >> id;
    }
    Tutor *tutor = linearSearch(tutorHead, tutorTail, id);
    if (tutor == NULL)
    {
        std::cout << "Tutor not found. Please try again." << std::endl;
        addRating();
    }
    else
    {
        std::cout << "Currently rating " << tutor->tutorName << "." << std::endl;
        std::cout << "Enter the rating: ";
        int rating;
        std::cin >> rating;
        // check for invalid input for rating
        while (!std::cin.good() || rating < 0 || rating > 5)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please make sure rating are values between 1 and 5." << std::endl;
            std::cout << "Enter the rating: ";
            std::cin >> rating;
        }
        std::cout << std::endl;
        tutor->totalRatings += rating;
        tutor->ratingCount += 1;
        std::cout << "New rating has been added." << std::endl;
    }
}

void terminateTutor()
{
    std::cout << std::endl
              << "Enter the id of the tutor to be terminated: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the tutor to be terminated: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Tutor *tutor = linearSearch(tutorHead, tutorTail, id);

    if (tutor != NULL)
    {
        if (tutor->dateTerminated == "")
        {
            tutor->dateTerminated = getDateToday();
            std::cout << "Tutor " << tutor->tutorName << " has been terminated on " << tutor->dateTerminated << std::endl;
        }
        else
        {
            std::cout << "Error Occured! Tutor " << tutor->tutorName << " has already been terminated on " << tutor->dateTerminated << std::endl;
        }
    }
    else
    {
        std::cout << "Tutor not found. Please try again." << std::endl;
    }
}