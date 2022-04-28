#pragma once

#include "functions.h"
#include "user.h"

// ---------------------------------------------- Dashboards ----------------------------------------------
void displayHrMenu()
{
    std::cout << "1 - Manage Users" << std::endl;
    std::cout << "2 - Manage Centres" << std::endl;
    std::cout << "3 - Manage Subjects" << std::endl;
    std::cout << "4 - Manage Tutors" << std::endl;
    std::cout << "5 - Add Ratings" << std::endl;
    std::cout << "6 - View Tutor Archive" << std::endl;
    std::cout << "7 - Logout" << std::endl;

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
    case 1:
        manageUsers();
        break;
    case 2:
        // manageCentres();
        break;
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
        // logout();
        break;
    }
}

void displayAdminMenu()
{
    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View All Subjects" << std::endl;
    std::cout << "3 - Add Ratings" << std::endl;
    std::cout << "4 - View Tutor Archive" << std::endl;
    std::cout << "5 - Logout" << std::endl;

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
        // logout();
        break;
    }
}

void displayTutorMenu()
{
    std::cout << "1 - View Centre Details" << std::endl;
    std::cout << "2 - View Subject Details" << std::endl;
    std::cout << "3 - View Tutor Details" << std::endl;
    std::cout << "4 - Logout" << std::endl;

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
        // logout();
        break;
    }
}
