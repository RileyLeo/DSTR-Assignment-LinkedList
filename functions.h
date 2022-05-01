
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
    if (id < 0 || id > getListSize(head) || head == NULL)
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
    std::cout << "Object with ID: " << objectID << " deleted successfully!" << std::endl;
}

#endif // PCH_H