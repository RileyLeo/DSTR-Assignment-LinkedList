#pragma once

#include "functions.h"

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
    if (choice == 4)
    {
        // terminate tutor
        std::cout << "6 - Terminate Tutor" << std::endl;
        // exit
        std::cout << "7 - Back" << std::endl;
    }
    else
    {
        // exit
        std::cout << "6 - Back" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (choice == 4)
    {
        while (!std::cin.good() || input < 1 || input > 7)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    else
    {
        while (!std::cin.good() || input < 1 || input > 6)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> input;
        }
    }
    return input;
}

int manageViews()
{
    system("cls");
    std::cout << "1 - No Sorting" << std::endl;
    std::cout << "2 - Sorting 1" << std::endl;
    std::cout << "3 - Sorting 2" << std::endl;
    std::cout << "4 - Sorting 3" << std::endl;

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
        // ---------------------------------------------------------------------------------- Manage Users ----------------------------------------------------------------------------------
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
            searchUser();
            displayHrMenu();
        }
        // add user
        else if (choice == 3)
        {
            addUser();
            displayHrMenu();
        }
        // edit user
        else if (choice == 4)
        {
            updateUser();
            displayHrMenu();
        }
        // delete user
        else if (choice == 5)
        {
            deleteUser();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
        // ---------------------------------------------------------------------------------- Manage Centres ----------------------------------------------------------------------------------
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
            searchCentre();
            displayHrMenu();
        }
        // add Centre
        else if (choice == 3)
        {
            addCentre();
            displayHrMenu();
        }
        // edit centre
        else if (choice == 4)
        {
            updateCentre();
            displayHrMenu();
        }
        // delete centre
        else if (choice == 5)
        {
            deleteCentre();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
    case 3:
        // ---------------------------------------------------------------------------------- Manage Subjects ----------------------------------------------------------------------------------
        choice = manageObject(3);
        // view all subjects
        if (choice == 1)
        {
            std::cout << std::endl;
            displaySubjectList();
            displayHrMenu();
        }
        // search subject
        else if (choice == 2)
        {
            searchSubject();
            displayHrMenu();
        }
        // add Subject
        else if (choice == 3)
        {
            addSubject();
            displayHrMenu();
        }
        // edit subject
        else if (choice == 4)
        {
            updateSubject();
            displayHrMenu();
        }
        // delete subject
        else if (choice == 5)
        {
            deleteSubject();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            system("cls");
            displayHrMenu();
        }
    case 4:
        // ---------------------------------------------------------------------------------- Manage Tutors ----------------------------------------------------------------------------------
        choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            std::cout << std::endl;
            displayTutorList();
            displayHrMenu();
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutor();
            displayHrMenu();
        }
        // add Tutor
        else if (choice == 3)
        {
            addTutor();
            displayHrMenu();
        }
        // edit tutor
        else if (choice == 4)
        {
            updateTutor();
            displayHrMenu();
        }
        // delete tutor
        else if (choice == 5)
        {
            deleteTutor();
            displayHrMenu();
        }
        else if (choice == 6)
        {
            terminateTutor();
            displayHrMenu();
        }
        else if (choice == 7)
        {
            system("cls");
            displayHrMenu();
        }
    case 5:
        // ---------------------------------------------------------------------------------- Add Ratings ----------------------------------------------------------------------------------
        addRating();
        displayHrMenu();
    case 6:
        displayArchiveList();
        displayHrMenu();
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
        exit(0);
        break;
        return;
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
        exit(0);
        break;
        return;
    }
}
