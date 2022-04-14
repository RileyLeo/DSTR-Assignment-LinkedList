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