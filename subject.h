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
    system("cls");

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
    system("cls");

    // cout all the attributes
    std::cout << "Subject ID: " << subject->id << std::endl;
    std::cout << "Subject Name: " << subject->subjectName << std::endl;
    std::cout << "Hourly Pay Rate: " << subject->hourlyPayRate << std::endl;
    std::cout << std::endl;
}

void searchSubject()
{
    std::cout << std::endl
              << "Enter the id of the subject to search: ";
    int id;
    std::cin >> id;
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the subject to search: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Subject *subject = linearSearch(subjectHead, subjectTail, id);
    if (subject != NULL)
    {
        displaySubject(subject);
    }
    else
    {
        std::cout << "Subject not found." << std::endl;
    }
    std::cout << std::endl;
}

void addSubject()
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
    insertAtEnd(newSubject, subjectHead, subjectTail);
    std::cout << "New Subject has been added" << std::endl
              << std::endl;
}

void updateSubject() {}

void deleteSubject()
{
    std::cout << std::endl
              << "Enter the id of the subject to be deleted: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter the id of the subject to be deleted: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    deleteNode(subjectHead, subjectTail, id);
    std::cout << std::endl;
}