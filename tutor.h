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
} * tutorHead, *tutorTail, *tutorHPRHead, *tutorHPRTail, *tutorRatingHead, *tutorRatingTail;

// displayTutorList
void filterTutors(int centreID, int subjectID, int tutorRatings, Tutor *head)
{
    system("cls");
    Tutor *current = head;
    Tutor *oneBeforeCurrent = NULL;
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
            if ( // View tutors belonging to all Centers
                (centreID == -1 && subjectID == -2 && tutorRatings == -2)
                // View tutors belonging to Specific Center
                || (current->centreId == centreID && subjectID == -2 && tutorRatings == -2)
                // View tutors belonging to Specific Subject in all centres
                || (centreID == -2 && current->subjectId == subjectID && tutorRatings == -2)
                // View tutors belonging to Specific Subject and Specific Center
                || (current->centreId == centreID && current->subjectId == subjectID && tutorRatings == -2)
                // View tutors belonging to Specific Ratings in all centres
                || (centreID == -2 && subjectID == -2 && std::round(ratings) == tutorRatings)
                // View tutors belonging to Specific Ratings and Specific Centre
                || (current->centreId == centreID && subjectID == -2 && std::round(ratings) == tutorRatings))
            {
                if (count == 0)
                {
                    std::cout << "Tutor list - Page " << page << std::endl;
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
            }
            else
            {
                skips++;
            }

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
    if (tutor->ratingCount == 0)
    {
        std::cout << "No ratings yet" << std::endl;
    }
    else
    {
        std::cout << "Tutor Rating: " << tutor->totalRatings / tutor->ratingCount << std::endl;
    }
    std::string centreName = linearSearch(centreHead, centreTail, tutor->centreId)->centreName;
    std::cout << "Centre ID: " << tutor->centreId << " - " << centreName << std::endl;
    std::string subjectName = linearSearch(subjectHead, subjectTail, tutor->subjectId)->subjectName;
    std::cout << "Subject ID: " << tutor->subjectId << " - " << subjectName << std::endl;
    std::cout << "Hourly Pay Rate: " << linearSearch(subjectHead, subjectTail, tutor->subjectId)->hourlyPayRate << std::endl;
    std::cout << std::endl;
}

void searchTutorById(int centreId)
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
        // for HR to view - no restrictions
        if (centreId == -1)
        {
            displayTutor(tutor);
        }
        // for admin to view - only show the tutor in the same centre
        else if (centreId != tutor->centreId)
        {
            std::cout << "Unable to view tutor info from another centre!" << std::endl
                      << std::endl;
            return;
        }
        else
        {
            displayTutor(tutor);
        }
    }
    else
    {
        std::cout << "Tutor not found." << std::endl;
    }
    std::cout << std::endl;
}

void addTutor(int adminCentreId)
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

    // Only prompt for centre ID if HR is trying to add a tutor
    if (adminCentreId == -1)
    {
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
    }
    else
    {
        centreId = adminCentreId;
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

void updateTutor(int adminCentreId)
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
        if (adminCentreId != -1 && adminCentreId != tutor->centreId)
        {
            std::cout << "Unable to update tutor info from another centre!" << std::endl
                      << std::endl;
            return;
        }
        std::cout << "Updating tutor: " << tutor->tutorName << std::endl;
        std::cout << "New Tutor Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, tutorName);
        std::cout << "New Tutor Address: ";
        std::getline(std::cin, tutorAddress);
        std::cout << "New Tutor Phone Number: ";
        std::getline(std::cin, tutorPhoneNumber);
        if (adminCentreId == -1)
        {
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
        }
        else
        {
            centreId = adminCentreId;
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
        std::cout << "Enter the id of the tutor to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    deleteNode(tutorHead, tutorTail, id);
    std::cout << std::endl;
}

void addRating(int adminCentreId)
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
        addRating(adminCentreId);
    }
    else
    {
        // if not HR and not in charge of the tutor's centre, cannot rate
        if (adminCentreId != -1 && adminCentreId != tutor->centreId)
        {
            std::cout << "Unable to rate tutor from another centre!" << std::endl
                      << std::endl;
            addRating(adminCentreId);
        }
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

void terminateTutor(int adminCentreId)
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
        // if not HR and not in charge of the tutor's centre, cannot terminate
        if (adminCentreId != -1 && adminCentreId != tutor->centreId)
        {
            std::cout << "Unable to terminate tutor from another centre!" << std::endl
                      << std::endl;
            return;
        }
        else
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
    }
    else
    {
        std::cout << "Tutor not found. Please try again." << std::endl;
    }
}

void duplicateTutorLinkedList(Tutor *&duplicatedhead, Tutor *&duplicatedTail, Tutor *originalHead)
{
    // traverse duplicated head linked list and delete every node
    while (duplicatedhead != NULL)
    {
        Tutor *temp = duplicatedhead;
        duplicatedhead = duplicatedhead->nextAddress;
        delete temp;
    }
    duplicatedhead = NULL;
    duplicatedTail = NULL;
    Tutor *current = originalHead;
    while (current != NULL)
    {
        Tutor *newObject = new Tutor(getListSize(duplicatedhead), current->tutorName, current->tutorAddress, current->tutorPhoneNumber, current->dateJoined, current->dateTerminated, current->totalRatings, current->ratingCount, current->centreId, current->subjectId);
        // *newObject = *current;
        insertAtEnd(newObject, duplicatedhead, duplicatedTail);
        current = current->nextAddress;
    }
}

// ---------------------------------------------- Sorting Algorithm ----------------------------------------------
// Split a doubly linked list (DLL) into 2 DLLs of
// half sizes
Tutor *split(Tutor *head)
{
    Tutor *fast = head, *slow = head;
    while (fast->nextAddress && fast->nextAddress->nextAddress)
    {
        fast = fast->nextAddress->nextAddress;
        slow = slow->nextAddress;
    }
    Tutor *temp = slow->nextAddress;
    slow->nextAddress = NULL;
    return temp;
}

// -----------------------------------------------------------------Merge Sort for Ratings-----------------------------------------------------------------
// merge linked list based on ratings
Tutor *mergeRatings(Tutor *first, Tutor *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    float firstRatings = float(first->totalRatings) / float(first->ratingCount);
    float secondRatings = float(second->totalRatings) / float(second->ratingCount);
    // Pick the smaller value
    if (firstRatings <= secondRatings)
    {
        first->nextAddress = mergeRatings(first->nextAddress, second);
        first->nextAddress->previousAddress = first;
        first->previousAddress = NULL;
        return first;
    }
    else
    {
        second->nextAddress = mergeRatings(first, second->nextAddress);
        second->nextAddress->previousAddress = second;
        second->previousAddress = NULL;
        return second;
    }
}

// merge sort for ratings
Tutor *mergeSortRatings(Tutor *head)
{
    if (!head || !head->nextAddress)
        return head;
    Tutor *second = split(head);

    // Recur for left and right halves
    head = mergeSortRatings(head);
    second = mergeSortRatings(second);

    // Merge the two sorted halves
    return mergeRatings(head, second);
}

// -----------------------------------------------------------------Merge Sort for Hourly Pay Rate-----------------------------------------------------------------
// linear search to search for subjects based on tutor's tutor id
double HPRLinearSearch(Tutor *tutor, Subject *subjectHead)
{
    Subject *current = subjectHead;
    while (current != NULL)
    {
        if (current->id == tutor->subjectId)
        {
            return current->hourlyPayRate;
        }
        current = current->nextAddress;
    }
    return NULL;
}

// merge linked list based on Hourly Pay Rate
Tutor *mergeHPR(Tutor *first, Tutor *second)
{
    // If first linked list is empty
    if (!first)
        return second;

    // If second linked list is empty
    if (!second)
        return first;

    // Pick the smaller value
    if (HPRLinearSearch(first, subjectHead) <= HPRLinearSearch(second, subjectHead))
    {
        first->nextAddress = mergeHPR(first->nextAddress, second);
        first->nextAddress->previousAddress = first;
        first->previousAddress = NULL;
        return first;
    }
    else
    {
        second->nextAddress = mergeHPR(first, second->nextAddress);
        second->nextAddress->previousAddress = second;
        second->previousAddress = NULL;
        return second;
    }
}

// merge sort for Hourly Pay Rate
Tutor *mergeSortHPR(Tutor *head)
{
    if (!head || !head->nextAddress)
        return head;
    Tutor *second = split(head);

    // Recur for left and right halves
    head = mergeSortHPR(head);
    second = mergeSortHPR(second);

    // Merge the two sorted halves
    return mergeHPR(head, second);
}
