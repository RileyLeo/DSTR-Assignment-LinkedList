#pragma once
#include "includes.h"

// create subject class doubly linked list with int:subjectId, string:subjectName, double:hourlyPayRate
class Subject
{
public:
    int subjectId;
    std::string subjectName;
    double hourlyPayRate;
    Subject *nextAddress;
    Subject *previousAddress;

    // constructor
    Subject(int subjectId, std::string subjectName, double hourlyPayRate)
    {
        this->subjectId = subjectId;
        this->subjectName = subjectName;
        this->hourlyPayRate = hourlyPayRate;
        this->nextAddress = nullptr;
        this->previousAddress = nullptr;
    }
} *subjectHead = NULL;