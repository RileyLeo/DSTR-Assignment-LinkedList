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

void displaySubject(Subject *subject)
{
    // cout all the attributes
    std::cout << "Subject ID: " << subject->id << std::endl;
    std::cout << "Subject Name: " << subject->subjectName << std::endl;
    std::cout << "Hourly Pay Rate: " << subject->hourlyPayRate << std::endl;
    std::cout << std::endl;
}

Subject *addSubject()
{
    std::string subjectName;
    double hourlyPayRate;

    std::cout << "Please enter the following to add a subject: " << std::endl;
    std::cout << "Subject Name: ";
    std::cin >> subjectName;
    std::cout << "Hourly Pay Rate: ";
    std::cin >> hourlyPayRate;
    while (!std::cin.good() || hourlyPayRate < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Hourly Pay Rate: ";
        std::cin >> hourlyPayRate;
    }

    // create new subject
    Subject *newSubject = new Subject((subjectTail != NULL) ? subjectTail->id + 1 : getListSize(subjectHead), subjectName, hourlyPayRate);
    std::cout << "New Subject has been added" << std::endl;
    return newSubject;
}