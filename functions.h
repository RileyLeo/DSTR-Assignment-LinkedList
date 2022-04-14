
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "includes.h"
#include "pch.h"

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
            current = current->previousAddress;
        }
        else
        {
            current = current->nextAddress;
        }
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

#endif // PCH_H