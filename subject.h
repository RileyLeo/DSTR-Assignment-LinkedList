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
    Subject *current = subjectHead;
    Subject *oneBeforeCurrent = NULL;
    int count = 0;
    int index;
    int page = 1;
    while (true)
    {
        while (current != NULL)
        {
            if (count == 0)
            {
                std::cout << "Subject list - Page " << page << std::endl;
                std::cout << std::setw(75) << std::setfill('=') << "" << std::endl;
                std::cout << std::setw(6) << std::setfill(' ') << "No.";
                std::cout << std::setw(16) << std::setfill(' ') << "Subject ID";
                std::cout << std::setw(16) << std::setfill(' ') << "Subject Name";
                std::cout << std::setw(21) << std::setfill(' ') << "Hourly Pay Rate" << std::endl;
                std::cout << std::setw(75) << std::setfill('=') << "" << std::endl;
            }
            count++;
            index = ((page * 10) - 10 + count);
            std::cout << std::setw(5) << std::setfill(' ') << index << " ";
            std::cout << std::setw(15) << std::setfill(' ') << current->id << " ";
            std::cout << std::setw(15) << std::setfill(' ') << current->subjectName << " ";
            std::cout << std::setw(20) << std::setfill(' ') << current->hourlyPayRate << std::endl;

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
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, subjectName);
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

void updateSubject()
{
    std::string subjectName;
    double hourlyPayRate;
    int adminId;
    std::cout << "Enter id of subject to update: ";
    int id;
    std::cin >> id;
    // check for invalid input for id
    while (!std::cin.good() || id < 0)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please try again." << std::endl;
        std::cout << "Enter id of the subject to update: ";
        std::cin >> id;
    }
    std::cout << std::endl;
    Subject *subject = linearSearch(subjectHead, subjectTail, id);

    if (subject != NULL)
    {
        std::cout << "Updating subject: " << subject->subjectName << std::endl;
        std::cout << "Enter new Subject Name: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, subjectName);
        std::cout << "Enter New Hourly Pay Rate: ";
        std::cin >> hourlyPayRate;
        while (!std::cin.good() || hourlyPayRate < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
            std::cout << "Hourly Pay Rate: ";
            std::cin >> hourlyPayRate;
        }
        subject->subjectName = subjectName;
        subject->hourlyPayRate = hourlyPayRate;
        std::cout << "Subject has been updated" << std::endl
                  << std::endl;
    }
    else
    {
        std::cout << "Subject not found." << std::endl;
    }
    std::cout << std::endl;
}

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