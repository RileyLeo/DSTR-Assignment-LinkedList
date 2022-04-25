
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "includes.h"
#include "pch.h"

// ---------------------------------------------- General Functions ----------------------------------------------
// get date today in DD/MM/YYYY
std::string getDateToday()
{
    struct tm now;
    time_t t = time(0);
    localtime_s(&now, &t);
    std::string day = (now.tm_mday < 10) ? "0" + std::to_string(now.tm_mday) : std::to_string(now.tm_mday);
    std::string month = (now.tm_mon + 1 < 10) ? "0" + std::to_string(now.tm_mon + 1) : std::to_string(now.tm_mon + 1);
    std::string dateToday = day + "/" + month + "/" + std::to_string(now.tm_year + 1900);
    return dateToday;
}

// get list size of different types of doubly linked lists
template <class T>
int getListSize(T *head)
{
    int size = 0;
    while (head != NULL)
    {
        size++;
        head = head->nextAddress;
    }
    return size;
}

// login function that searches with username and password
template <class User>
User *login(User *head)
{
    std::string username;
    std::string password;
    std::cout << "Welcome to eXcel Tuition Management System" << std::endl;
    std::cout << "Please login to proceed" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;
    std::cout << std::endl;
    User *user = loginLinearSearch(username, password, head);
    while (user == NULL)
    {
        std::cout << "Username or password is incorrect. Please try again." << std::endl;
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
        std::cout << std::endl;
        user = loginLinearSearch(username, password, head);
    }
    std::cout << "Login Successful!" << std::endl;
    std::cout << "Welcome User: " << user->username << "!" << std::endl;
    std::cout << std::endl;
    return user;
}

// ---------------------------------------------- Searching Alorithm ----------------------------------------------
// linear search for doubly linked list and return object reference
template <class T>
T *linearSearch(T *&head, T *&tail, int id)
{
    // check if id out of range, return NULL
    if (id < 0 || id > tail->id)
    {
        return NULL;
    }

    // if id is closer to the end of the list, start searching from the end and traverse backwards
    T *current = ((id - head->id) <= (tail->id - id)) ? head : tail;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        else if (current->id > id)
        {
            // if node is deleted and not found, return NULL
            if (current->previousAddress->id < id)
            {
                return NULL;
            }
            else
            {
                current = current->previousAddress;
            }
        }
        else
        {
            // if node is deleted and not found, return NULL
            if (current->nextAddress->id > id)
            {
                return NULL;
            }
            else
            {
                current = current->nextAddress;
            }
        }
    }
    return NULL;
}

// linear search specifically for login function
template <class User>
User *loginLinearSearch(std::string username, std::string password, User *head)
{
    User *current = head;
    while (current != NULL)
    {
        if (current->username == username && current->password == password)
        {
            return current;
        }
        current = current->nextAddress;
    }
    return NULL;
}

// ---------------------------------------------- CRUD Functions ----------------------------------------------
// insert object at end of different types of doubly linked lists
template <class T>
void insertAtEnd(T *newObject, T *&head, T *&tail)
{
    if (head == NULL)
    {
        head = newObject;
        tail = newObject;
    }
    else
    {
        tail->nextAddress = newObject;
        newObject->previousAddress = tail;
        tail = newObject;
    }
}

template <class T>
void deleteNode(T *&head, T *&tail, int objectID)
{
    T *current = linearSearch(head, tail, objectID);

    if (head == NULL || current == NULL)
    {
        std::cout << "No object found with ID: " << objectID << std::endl
                  << std::endl;
        return;
    }

    if (head == current)
    {
        head = current->nextAddress;
    }

    if (tail == current)
    {
        tail = current->previousAddress;
    }

    if (current->nextAddress != NULL)
    {
        current->nextAddress->previousAddress = current->previousAddress;
    }

    if (current->previousAddress != NULL)
    {
        current->previousAddress->nextAddress = current->nextAddress;
    }

    delete current;
}

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

    while (input != NULL && isdigit(input) == true)
    {
        switch (input)
        {
        case 1:
            // manageUsers();
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
        default:
            std::cout << "Invalid input. Please enter again" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            break;
        }
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

    while (input != NULL && isdigit(input) == true)
    {
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
        default:
            std::cout << "Invalid input. Please enter again" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            break;
        }
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

    while (input != NULL && isdigit(input) == true)
    {
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
        default:
            std::cout << "Invalid input. Please enter again" << std::endl;
            std::cin >> input;
            std::cout << std::endl;
            break;
        }
    }
}

// ---------------------------------------------- Manage Users ----------------------------------------------
// ---------------------------------------------- Manage Centres ----------------------------------------------
// ---------------------------------------------- Manage Subjects ----------------------------------------------
// ---------------------------------------------- Manage Tutors ----------------------------------------------
// ---------------------------------------------- Add Ratings ----------------------------------------------
// ---------------------------------------------- View Tutor Archive ----------------------------------------------

#endif // PCH_H