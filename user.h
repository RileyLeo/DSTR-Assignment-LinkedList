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
    system("cls");

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
    system("cls");

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

void searchUser()
{
    std::cout << std::endl
              << "Enter the id of the user to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the user to search: ";
        std::cin >> id;
    }
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
}

void addUser()
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
    insertAtEnd(newUser, userHead, userTail);
    std::cout << "User created successfully" << std::endl
              << std::endl;
}

void updateUser()
{
    // prompt for input to fill in constructor
    std::string username;
    std::string password;

    std::cout << "Enter id of user to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the user to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    User *user = linearSearch(userHead, userTail, id);
    if (user != NULL)
    {
        std::cout << "Updating user: " << user->username << std::endl;
        std::cout << "Enter new username: ";
        std::cin >> username;
        std::cout << "Enter new password: ";
        std::cin >> password;
        user->username = username;
        user->password = password;
        std::cout << "User updated successfully" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "User not found." << std::endl;
    }
    std::cout << std::endl;
}

void deleteUser()
{
    std::cout << std::endl
              << "Enter the id of the user to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the user to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    deleteNode(userHead, userTail, id);
    std::cout << std::endl;
}