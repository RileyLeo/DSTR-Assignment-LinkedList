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
        std::string centreName = linearSearch(centreHead, centreTail, current->centreId)->centreName;
        std::cout << "Centre ID: " << current->centreId << " - " << centreName << std::endl;
        std::string subjectName = linearSearch(subjectHead, subjectTail, current->subjectId)->subjectName;
        std::cout << "Subject ID: " << current->subjectId << " - " << subjectName << std::endl;
        std::cout << std::endl;
        current = current->nextAddress;
    }
    delete current;
}

void displayTutor(Tutor *tutor)
{
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

Tutor *addTutor()
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
    std::cin >> tutorName;
    std::cout << "Tutor Address: ";
    std::cin >> tutorAddress;
    std::cout << "Tutor Phone Number: ";
    std::cin >> tutorPhoneNumber;
    std::cout << "Centre ID: ";
    std::cin >> centreId;
    while (!std::cin.good() || centreId < 0 || centreId > getListSize(centreHead))
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
    while (!std::cin.good() || subjectId < 0 || subjectId > getListSize(subjectHead))
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
    std::cout << "New tutor profile created successfully" << std::endl;
    return newTutor;
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