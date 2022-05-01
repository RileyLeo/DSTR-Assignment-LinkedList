#pragma once
#include "includes.h"
#include "functions.h"

// create user class doubly linked list with unsignedInt: userId, string: username, string: password, unsignedInt: userType
class User
{
public:
    int id;
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor
    User *nextAddress = NULL;
    User *previousAddress = NULL;

    // constructor
    User(int id, std::string username, std::string password, unsigned int userType)
    {
        this->id = id;
        this->username = username;
        this->password = password;
        this->userType = userType;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

} * userHead, *userTail;

// print user list
void displayUserList()
{
    // if user list is empty
    if (userHead == NULL)
    {
        std::cout << "User list is empty" << std::endl;
        return;
    }

    User *current = userHead;

    while (current != NULL)
    {
        std::cout << "User ID: " << current->id << std::endl;
        std::cout << "Username: " << current->username << std::endl;
        std::cout << "Password: " << current->password << std::endl;
        std::cout << "User Type: " << current->userType << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}

void displayUser(User *user)
{
    // cout all the attributes
    std::string userRole;
    if (user->userType == 0)
    {
        userRole = "HR";
    }
    else if (user->userType == 1)
    {
        userRole = "Admin";
    }
    else
    {
        userRole = "Tutor";
    }
    std::cout << "User ID: " << user->id << std::endl;
    std::cout << "Username: " << user->username << std::endl;
    std::cout << "Password: " << user->password << std::endl;
    std::cout << "User Type: " << user->userType << " - " << userRole << std::endl;
    std::cout << std::endl;
}

User *addUser()
{
    // prompt for input to fill in constructor
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor

    std::cout << "Please enter the following to create a new user account:" << std::endl;
    std::cout << "Enter Username: ";
    std::cin >> username;
    std::cout << "Enter Password: ";
    std::cin >> password;
    std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
    // check for invalid input for userType
    std::cin >> userType;
    while (!std::cin.good() || userType < 0 || userType > 2)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter User Type (0-HR, 1-Admin, 2- Tutor): ";
        std::cin >> userType;
    }

    // create new user
    User *newUser = new User((userTail != NULL) ? userTail->id + 1 : getListSize(userHead), username, password, userType);
    std::cout << "User created successfully" << std::endl;
    return newUser;
}
