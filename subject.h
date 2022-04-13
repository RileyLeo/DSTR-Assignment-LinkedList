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

    // displaySubjectList
    void displaySubjectList()
    {
        while (subjectHead != NULL)
        {
            std::cout << "Subject ID: " << subjectHead->id << std::endl;
            std::cout << "Subject Name: " << subjectHead->subjectName << std::endl;
            std::cout << "Hourly Pay Rate: " << subjectHead->hourlyPayRate << std::endl
                      << std::endl;
            subjectHead = subjectHead->nextAddress;
        }
    }

} *subjectHead = NULL, *subjectTail = NULL;
