#pragma once
#include "includes.h"

// create user class doubly linked list with unsignedInt: userId, string: username, string: password, unsignedInt: userType
class User
{
public:
    int userId;
    std::string username;
    std::string password;
    unsigned int userType; // 0-HR, 1-Admin, 2- Tutor
    User *nextAddress;
    User *previousAddress;

    // constructor
    User(int userId, std::string username, std::string password, unsigned int userType)
    {
        this->userId = userId;
        this->username = username;
        this->password = password;
        this->userType = userType;
        this->nextAddress = nullptr;
        this->previousAddress = nullptr;
    }
} *userHead = NULL;
