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
    Centre *current = centreHead;
    Centre *oneBeforeCurrent = NULL;
    int count = 0;
    int index;
    int page = 1;
    while (true)
    {
        while (current != NULL)
        {
            if (count == 0)
            {
                std::cout << "Centre list - Page " << page << std::endl;
                std::cout << std::setw(90) << std::setfill('=') << "" << std::endl;
                std::cout << std::setw(6) << std::setfill(' ') << "No.";
                std::cout << std::setw(11) << std::setfill(' ') << "Centre ID";
                std::cout << std::setw(31) << std::setfill(' ') << "Centre Name";
                std::cout << std::setw(21) << std::setfill(' ') << "Centre Location";
                std::cout << std::setw(11) << std::setfill(' ') << "Admin ID" << std::endl;
                std::cout << std::setw(90) << std::setfill('=') << "" << std::endl;
            }
            count++;
            index = ((page * 10) - 10 + count);
            std::cout << std::setw(5) << std::setfill(' ') << index << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->id << " ";
            std::cout << std::setw(30) << std::setfill(' ') << current->centreName << " ";
            std::cout << std::setw(20) << std::setfill(' ') << current->centreLocation << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->adminId << " " << std::endl;

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
                        for (int i = 0; i < count + 9; i++)
                        {
                            current = current->previousAddress;
                        }
                        system("cls");
                        count = 0;
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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, centreName);
    std::cout << "Enter the centre location: ";
    std::getline(std::cin, centreLocation);
    std::cout << "Enter the admin id: ";
    std::cin >> adminId;

    // adminId must be an existing admin
    while (!std::cin.good() || adminId < 0 || adminId > userTail->id)
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
        Centre *centre = centreLinearSearch(adminId, centreHead);

        if (admin == NULL || centre == NULL)
        {
            std::cout << "User does not exist" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        else if (admin->userType != 1)
        {
            std::cout << "User is not an admin" << std::endl;
            std::cout << "Enter the admin id: ";
            std::cin >> adminId;
        }
        else if (centre != NULL)
        {
            std::cout << "Admin is already in charge of a centre" << std::endl;
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

void updateCentre()
{
    std::string centreName;
    std::string centreLocation;
    int adminId;
    std::cout << "Enter id of centre to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the centre to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Centre *centre = linearSearch(centreHead, centreTail, id);
    if (centre != NULL)
    {
        std::cout << "Updating Centre: " << centre->centreName << std::endl;
        std::cout << "Enter new centre name: ";
        std::cin.ignore();
        std::getline(std::cin, centreName);
        std::cout << "Enter new centre location: ";
        std::getline(std::cin, centreLocation);
        std::cout << "Enter new admin id: ";
        std::cin >> adminId;

        // adminId must be an existing admin
        while (!std::cin.good() || adminId < 0 || adminId > userTail->id)
        {

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter new admin id: ";
            std::cin >> adminId;
        }
        bool flag = true;
        while (flag)
        {
            User *admin = linearSearch(userHead, userTail, adminId);
            if (admin->userType != 1 || admin == NULL)
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

        centre->centreName = centreName;
        centre->centreLocation = centreLocation;
        centre->adminId = adminId;
        std::cout << "Centre updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Centre not found." << std::endl;
    }
    std::cout << std::endl;
}

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