#pragma once
#include "includes.h"

// create subject class doubly linked list with int:subjectId, string:subjectName, double:hourlyPayRate
class Subject
{
public:
    int id;
    std::string subjectName;
    double hourlyPayRate;
    Subject *nextAddress = NULL;
    Subject *previousAddress = NULL;

    // constructor with parameters
    Subject(int id, std::string subjectName, double hourlyPayRate)
    {
        this->id = id;
        this->subjectName = subjectName;
        this->hourlyPayRate = hourlyPayRate;
        this->nextAddress = NULL;
        this->previousAddress = NULL;
    };

} * subjectHead, *subjectTail;

// displaySubjectList
void displaySubjectList()
{
    // if subject list is empty
    if (subjectHead == NULL)
    {
        std::cout << "Subject list is empty" << std::endl;
        return;
    }

    Subject *current = subjectHead;
    while (current != NULL)
    {
        std::cout << "Subject ID: " << current->id << std::endl;
        std::cout << "Subject Name: " << current->subjectName << std::endl;
        std::cout << "Hourly Pay Rate: " << current->hourlyPayRate << std::endl
                  << std::endl;
        current = current->nextAddress;
    }
    delete current;
}