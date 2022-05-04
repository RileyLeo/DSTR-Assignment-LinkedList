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
    system("cls");

    // if centre list is empty
    if (centreHead == NULL)
    {
        std::cout << "Centre list is empty" << std::endl;
        return;
    }

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

void displayCentre(Centre *centre)
{
    system("cls");

    // cout all the attributes
    std::cout << "Centre ID: " << centre->id << std::endl;
    std::cout << "Centre Name: " << centre->centreName << std::endl;
    std::cout << "Centre Location: " << centre->centreLocation << std::endl;
    std::cout << "Admin ID: " << centre->adminId << std::endl;
    std::cout << std::endl;
}

void searchCentre()
{
    std::cout << std::endl
              << "Enter the id of the centre to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the centre to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Centre *centre = linearSearch(centreHead, centreTail, id);
    if (centre != NULL)
    {
        displayCentre(centre);
    }
    else
    {
        std::cout << "Centre not found." << std::endl;
    }
    std::cout << std::endl;
}

void addCentre()
{
    // prompt for input to fill in constructor
    std::string centreName;
    std::string centreLocation;
    int adminId;
    std::cout << "Please enter the following to create a new centre:" << std::endl;
    std::cout << "Enter the centre name: ";
    std::cin >> centreName;
    std::cout << "Enter the centre location: ";
    std::cin >> centreLocation;
    std::cout << "Enter the admin id: ";
    std::cin >> adminId;

    // adminId must be an existing admin
    while (!std::cin.good() || adminId < 0 || adminId > getListSize(userHead))
    {

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the admin id: ";
        std::cin >> adminId;
    }
    bool flag = true;
    while (flag)
    {
        User *admin = linearSearch(userHead, userTail, adminId);
        if (admin->userType != 1)
        {
            std::cout << "User is not an admin" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        else
        {
            flag = false;
        }
    }

    // create new centre
    Centre *newCentre = new Centre((centreTail != NULL) ? centreTail->id + 1 : getListSize(centreHead), centreName, centreLocation, adminId);
    insertAtEnd(newCentre, centreHead, centreTail);
    std::cout << "New Centre has been added" << std::endl
              << std::endl;
}

void updateCentre() {}

void deleteCentre()
{
    std::cout << std::endl
              << "Enter the id of the centre to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the centre to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    deleteNode(centreHead, centreTail, id);
    std::cout << std::endl;
}