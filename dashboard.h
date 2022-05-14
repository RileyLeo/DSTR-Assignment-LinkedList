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

int viewTutorSorted()
{
    system("cls");
    std::cout << "1 - View Tutors sorted by ID" << std::endl;
    std::cout << "2 - View Tutors sorted by Hourly Pay Rate" << std::endl;
    std::cout << "3 - View Tutors sorted by Rating" << std::endl;

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    while (!std::cin.good() || input < 1 || input > 3)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> input;
    }
    return input;
}

int searchTutorDashboard(int userType)
{
    system("cls");
    std::cout << "1 - Search Tutor by ID" << std::endl;
    std::cout << "2 - Filter Tutors by Rating" << std::endl;
    std::cout << "3 - Filter Tutors by Subject ID" << std::endl;
    if (userType == 0)
    {
        std::cout << "4 - Filter Tutors by Centre ID" << std::endl;
    }

    int input;
    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (userType == 0)
    {
        while (!std::cin.good() || input < 1 || input > 4)
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
        while (!std::cin.good() || input < 1 || input > 3)
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

// ---------------------------------------------- Dashboards ----------------------------------------------
void displayHrMenu()
{
    int choice, tutorViewChoice, searchTutorChoice;
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
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                sortTutorById(-1);
                displayHrMenu();
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                // sortTutorByHourlyPayRate(-1);
                displayHrMenu();
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                // sortTutorByRating(-1);
                displayHrMenu();
            }
        }
        // search tutor
        else if (choice == 2)
        {
            searchTutorChoice = searchTutorDashboard(0);
            system("cls");
            // search tutor by ID
            if (searchTutorChoice == 1)
            {
                searchTutorById();
                displayHrMenu();
            }
            // filter by Rating
            else if (searchTutorChoice == 2)
            {
                // filterTutorByRating(-1);
                displayHrMenu();
            }
            // filter by Subject ID
            else if (searchTutorChoice == 3)
            {
                // filterTutorBySubjectId(-1);
                displayHrMenu();
            }
            // filter by Centre ID
            else if (searchTutorChoice == 4)
            {
                // filterTutorByCentreId(-1);
                displayHrMenu();
            }
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

void displayAdminMenu(User * login)
{
    int choice, tutorViewChoice, searchTutorChoice;
    Centre * centre = centreLinearSearch(login->id, centreHead);
    std::cout << "1 - Manage Tutors" << std::endl;
    std::cout << "2 - View Centre Details" << std::endl;
    std::cout << "3 - View All Subjects" << std::endl;
    std::cout << "4 - Add Ratings" << std::endl;
    std::cout << "5 - View Tutor Archive" << std::endl;
    std::cout << "6 - Exit Program" << std::endl;

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
         choice = manageObject(4);
        // view all tutors
        if (choice == 1)
        {
            tutorViewChoice = viewTutorSorted();
            system("cls");
            // view tutors sorted by ID
            if (tutorViewChoice == 1)
            {
                sortTutorById(centre->id);
                displayAdminMenu(login);
            }
            // view tutors sorted by hourly pay rate
            else if (tutorViewChoice == 2)
            {
                // sortTutorByHourlyPayRate(-1);
                displayAdminMenu(login);
            }
            // view tutors sorted by rating
            else if (tutorViewChoice == 3)
            {
                // sortTutorByRating(-1);
                displayAdminMenu(login);
            }
        }
        // // search tutor
        // else if (choice == 2)
        // {
        //     searchTutorChoice = searchTutorDashboard(0);
        //     system("cls");
        //     // search tutor by ID
        //     if (searchTutorChoice == 1)
        //     {
        //         searchTutorById();
        //         displayHrMenu();
        //     }
        //     // filter by Rating
        //     else if (searchTutorChoice == 2)
        //     {
        //         // filterTutorByRating(-1);
        //         displayHrMenu();
        //     }
        //     // filter by Subject ID
        //     else if (searchTutorChoice == 3)
        //     {
        //         // filterTutorBySubjectId(-1);
        //         displayHrMenu();
        //     }
        //     // filter by Centre ID
        //     else if (searchTutorChoice == 4)
        //     {
        //         // filterTutorByCentreId(-1);
        //         displayHrMenu();
        //     }
        // }
        // // add Tutor
        // else if (choice == 3)
        // {
        //     addTutor();
        //     displayHrMenu();
        // }
        // // edit tutor
        // else if (choice == 4)
        // {
        //     updateTutor();
        //     displayHrMenu();
        // }
        // // delete tutor
        // else if (choice == 5)
        // {
        //     deleteTutor();
        //     displayHrMenu();
        // }
        // else if (choice == 6)
        // {
        //     terminateTutor();
        //     displayHrMenu();
        // }
        // else if (choice == 7)
        // {
        //     system("cls");
        //     displayHrMenu();
        // }
    case 2:
        // viewCentreDetails();
        break;
    case 3:
        // viewAllSubjects();
        break;
    case 4:
        // addRatings();
        break;
    case 5:
        // viewTutorArchive();
        break;
    case 6:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}

void displayTutorMenu(User *login)
{
    int tutorId = std::stoi(login->username);
    Tutor *tutor = linearSearch(tutorHead, tutorTail, tutorId);
    Centre *centre = linearSearch(centreHead, centreTail, tutor->centreId);
    Subject *subject = linearSearch(subjectHead, subjectTail, tutor->subjectId);

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
        displayCentre(centre);
        displayTutorMenu(login);
    case 2:
        displaySubject(subject);
        displayTutorMenu(login);
    case 3:
        displayTutor(tutor);
        displayTutorMenu(login);
    case 4:
        std::cout << "Exiting program..." << std::endl;
        exit(0);
        break;
        return;
    }
}
