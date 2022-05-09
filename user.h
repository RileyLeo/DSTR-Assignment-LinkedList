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
// void displayUserList()
// {
//     system("cls");

//     // if user list is empty
//     if (userHead == NULL)
//     {
//         std::cout << "User list is empty" << std::endl;
//         return;
//     }

//     User *current = userHead;

//     while (current != NULL)
//     {
//         std::cout << "User ID: " << current->id << std::endl;
//         std::cout << "Username: " << current->username << std::endl;
//         std::cout << "Password: " << current->password << std::endl;
//         std::cout << "User Type: " << current->userType << std::endl
//                   << std::endl;
//         current = current->nextAddress;
//     }
//     delete current;
// }

void displayUserList()
{
    system("cls");
    User *current = userHead;
    User *oneBeforeCurrent = NULL;
    int count = 0;
    int index;
    int page = 1;
    while (true)
    {
        while (current != NULL)
        {
            if (count == 0)
            {
                std::cout << "User list - Page " << page << std::endl;
                std::cout << std::setw(55) << std::setfill('=') << "" << std::endl;
                std::cout << std::setw(6) << std::setfill(' ') << "No.";
                std::cout << std::setw(11) << std::setfill(' ') << "User ID";
                std::cout << std::setw(11) << std::setfill(' ') << "Username";
                std::cout << std::setw(11) << std::setfill(' ') << "Password";
                std::cout << std::setw(14) << std::setfill(' ') << "User Type " << std::endl;
                std::cout << std::setw(55) << std::setfill('=') << "" << std::endl;
            }
            count++;
            index = ((page * 10) - 10 + count);
            std::cout << std::setw(5) << std::setfill(' ') << index << " ";
             std::cout << std::setw(10) << std::setfill(' ') << current->id << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->username << " ";
            std::cout << std::setw(10) << std::setfill(' ') << current->password << " ";
            if (current->userType == 0)
            {
                std::cout << std::setw(13) << std::setfill(' ') << "0 -  HR  " << std::endl;
            }
            else if (current->userType == 1)
            {
                std::cout << std::setw(13) << std::setfill(' ') << "1 - Admin" << std::endl;
            }
            else if (current->userType == 2)
            {
                std::cout << std::setw(13) << std::setfill(' ') << "2 - Tutor" << std::endl;
            }

            oneBeforeCurrent = current;
            current = current->nextAddress;
            while (count == 10 || current == NULL)
            {
                std::cout << "Press 1 to continue or press 0 to exit or 2 to the previous page" << std::endl;
                int choice;
                std::cin >> choice;
                if (choice == 0)
                {
                    system("cls");
                    return;
                }
                else if (choice == 2)
                {
                    if (page == 1)
                    {
                        std::cout << "You are on the first page" << std::endl;
                    }
                    else
                    {
                        current = oneBeforeCurrent;
                        for (int i = 0; i < count + 9; i++)
                        {
                            current = current->previousAddress;
                        }
                        system("cls");
                        count = 0;
                        page--;
                    }
                }
                else if (choice == 1)
                {
                    if (current == NULL)
                    {
                        std::cout << "You are on the Last page" << std::endl;
                    }
                    else
                    {
                        system("cls");
                        count = 0;
                        page++;
                    }
                }
                else
                {
                    std::cout << "Invalid input" << std::endl;
                }
            }
        }
    }
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