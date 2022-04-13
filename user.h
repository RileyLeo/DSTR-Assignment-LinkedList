#pragma once
#include "includes.h"

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
    while (userHead != NULL)
    {
        std::cout << "User ID: " << userHead->id << std::endl;
        std::cout << "Username: " << userHead->username << std::endl;
        std::cout << "Password: " << userHead->password << std::endl;
        std::cout << "User Type: " << userHead->userType << std::endl
                  << std::endl;
        userHead = userHead->nextAddress;
    }
}