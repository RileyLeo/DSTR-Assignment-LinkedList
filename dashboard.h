#pragma once

#include "functions.h"
#include "user.h"

int manageObject(int choice)
{
    std::string object = "";
    if (choice == 1)
    {
        object = "User";
    }
    else if (choice == 2)
    {
        object = "Centre";
    }
    else if (choice == 3)
    {
        object = "Subject";
    }
    else if (choice == 4)
    {
        object = "Tutor";
    }
    system("cls");
    // view user
    std::cout << "1 - View All " << object << "s" << std::endl;
    // search user
    std::cout << "2 - Search " << object << std::endl;
    // add user
    std::cout << "3 - Add " << object << std::endl;
    // edit user
    std::cout << "4 - Edit " << object << std::endl;
    // delete user
    std::cout << "5 - Delete " << object << std::endl;
    // exit
    std::cout << "6 - Back" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 6)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }
    return input;
}

// ---------------------------------------------- Dashboards ----------------------------------------------
void displayHrMenu()
{
    int choice;
    std::cout << "1 - Manage Users" << std::endl;
    std::cout << "2 - Manage Centres" << std::endl;
    std::cout << "3 - Manage Subjects" << std::endl;
    std::cout << "4 - Manage Tutors" << std::endl;
    std::cout << "5 - Add Ratings" << std::endl;
    std::cout << "6 - View Tutor Archive" << std::endl;
    std::cout << "7 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 7)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
        // ----------------------------------------- Manage Users -----------------------------------------
    case 1:
        choice = manageObject(1);
        // view all users
        if (choice == 1)
        {
            std::cout << std::endl;
            displayUserList();
            displayHrMenu();
        }
        // search user
        else if (choice == 2)
        {
            std::cout << std::endl
                      << "Enter the id of the user to search: ";
            int id;
            std::cin >> id;
            std::cout << std::endl;
            User *user = linearSearch(userHead, userTail, id);
            if (user != NULL)
            {
                displayUser(user);
            }
            else
            {
                std::cout << "User not found." << std::endl;
            }
            std::cout << std::endl;
            displayHrMenu();
        }
        // add user
        else if (choice == 3)
        {
            User *newUser = addUser();
            insertAtEnd(newUser, userHead, userTail);
            std::cout << std::endl;
            displayHrMenu();
        }
        // edit user
        else if (choice == 4)
        {
        }
        // delete user
        else if (choice == 5)
        {
            std::cout << std::endl
                      << "Enter the id of the user to be deleted: ";
            int id;
            std::cin >> id;
            std::cout << std::endl;
            deleteNode(userHead, userTail, id);
            std::cout << std::endl;
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
        // ----------------------------------------- Manage Centres -----------------------------------------
    case 2:
        choice = manageObject(2);
        // view all centres
        if (choice == 1)
        {
            std::cout << std::endl;
            displayCentreList();
            displayHrMenu();
        }
        // search centre
        else if (choice == 2)
        {
            std::cout << std::endl
                      << "Enter the id of the centre to search: ";
            int id;
            std::cin >> id;
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
            displayHrMenu();
        }
        // add Centre
        else if (choice == 3)
        {
            Centre *newCentre = addCentre();
            insertAtEnd(newCentre, centreHead, centreTail);
            std::cout << std::endl;
            displayHrMenu();
        }
        // edit centre
        else if (choice == 4)
        {
            // editCentre();
        }
        // delete centre
        else if (choice == 5)
        {
            std::cout << std::endl
                      << "Enter the id of the centre to be deleted: ";
            int id;
            std::cin >> id;
            std::cout << std::endl;
            deleteNode(centreHead, centreTail, id);
            std::cout << std::endl;
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
    case 3:
        // manageSubjects();
        break;
    case 4:
        // manageTutors();
        break;
    case 5:
        // addRatings();
        break;
    case 6:
        // viewTutorArchive();
        break;
    case 7:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayAdminMenu()
{
    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View All Subjects" << std::endl;
    std::cout << "3 - Add Ratings" << std::endl;
    std::cout << "4 - View Tutor Archive" << std::endl;
    std::cout << "5 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 5)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
    case 1:
        // viewCentreDetails();
        break;
    case 2:
        // viewAllSubjects();
        break;
    case 3:
        // addRatings();
        break;
    case 4:
        // viewTutorArchive();
        break;
    case 5:
        std::cout << "Exiting program..." << std::endl;
        return;
        break;
    }
}

void displayTutorMenu()
{
    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View Subject Details" << std::endl;
    std::cout << "3 - View Tutor Details" << std::endl;
    std::cout << "4 - Exit Program" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 4)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }

    switch (input)
    {
    case 1:
        // viewCentreDetails();
        break;
    case 2:
        // viewSubjectDetails();
        break;
    case 3:
        // viewTutorDetails();
        break;
    case 4:
        std::cout << "Exiting program..." << std::endl;
        return;
        break;
    }
}
