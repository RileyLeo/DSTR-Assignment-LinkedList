
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

// get date difference of 2 dates in DD/MM/YYYY format in days
int getDateDifference(std::string date1, std::string date2)
{
    // get date1 in DD/MM/YYYY format
    std::string day1 = date1.substr(0, 2);
    std::string month1 = date1.substr(3, 2);
    std::string year1 = date1.substr(6, 4);
    int day1Int = std::stoi(day1);
    int month1Int = std::stoi(month1);
    int year1Int = std::stoi(year1);

    // get date2 in DD/MM/YYYY format
    std::string day2 = date2.substr(0, 2);
    std::string month2 = date2.substr(3, 2);
    std::string year2 = date2.substr(6, 4);
    int day2Int = std::stoi(day2);
    int month2Int = std::stoi(month2);
    int year2Int = std::stoi(year2);

    // get date1 in seconds
    time_t t1 = time(0);
    struct tm now1;
    localtime_s(&now1, &t1);
    now1.tm_mday = day1Int;
    now1.tm_mon = month1Int - 1;
    now1.tm_year = year1Int - 1900;
    time_t t1Seconds = mktime(&now1);

    // get date2 in seconds
    time_t t2 = time(0);
    struct tm now2;
    localtime_s(&now2, &t2);
    now2.tm_mday = day2Int;
    now2.tm_mon = month2Int - 1;
    now2.tm_year = year2Int - 1900;
    time_t t2Seconds = mktime(&now2);

    // get difference in seconds
    int difference = t2Seconds - t1Seconds;

    // get difference in days
    int differenceDays = difference / 86400;

    return differenceDays;
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
    if (id < 0 || id > tail->id || head == NULL)
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
            if (current->previousAddress == NULL)
            {
                return NULL;
            }
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
            if (current->nextAddress == NULL)
            {
                return NULL;
            }
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

template <class T>
void updateNode(T *&head, T *&tail, T *newObject, int objectID)
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
        head = newObject;
    }

    if (tail == current)
    {
        tail = newObject;
    }

    if (current->nextAddress != NULL)
    {
        current->nextAddress->previousAddress = newObject;
    }

    if (current->previousAddress != NULL)
    {
        current->previousAddress->nextAddress = newObject;
    }

    newObject->nextAddress = current->nextAddress;
    newObject->previousAddress = current->previousAddress;

    delete current;
    std::cout << "Object with ID: " << objectID << " updated successfully!" << std::endl;
}

#endif // PCH_H