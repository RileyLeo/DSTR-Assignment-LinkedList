#include "pch.h"
#include "functions.h"
#include "user.h"
#include "centre.h"
#include "subject.h"
#include "tutor.h"
#include "archive.h"
#include "dashboard.h"

using namespace std;

void generateMockData()
{
    // initialize system with new users, subjects, centres, and tutors

    // for (int i = 0; i < 8; i++)
    // {
    User *user = new User(getListSize(userHead), "hr", "123", 0);
    insertAtEnd(user, userHead, userTail);
    User *user1 = new User(getListSize(userHead), "admin1", "123", 1);
    insertAtEnd(user1, userHead, userTail);
    User *user2 = new User(getListSize(userHead), "tutor", "123", 2);
    insertAtEnd(user2, userHead, userTail);
    User *user3 = new User(getListSize(userHead), "admin2", "123", 1);
    insertAtEnd(user3, userHead, userTail);
    User *user4 = new User(getListSize(userHead), "admin3", "123", 1);
    insertAtEnd(user4, userHead, userTail);
    // }

    Subject *subject1 = new Subject(getListSize(subjectHead), "Maths", 20.00);
    insertAtEnd(subject1, subjectHead, subjectTail);
    Subject *subject2 = new Subject(getListSize(subjectHead), "Physics", 22.00);
    insertAtEnd(subject2, subjectHead, subjectTail);
    Subject *subject3 = new Subject(getListSize(subjectHead), "English", 17.00);
    insertAtEnd(subject3, subjectHead, subjectTail);
    Subject *subject4 = new Subject(getListSize(subjectHead), "Physics", 22.00);
    insertAtEnd(subject4, subjectHead, subjectTail);
    Subject *subject5 = new Subject(getListSize(subjectHead), "Chemistry", 22.00);
    insertAtEnd(subject5, subjectHead, subjectTail);

    Centre *centre1 = new Centre(getListSize(centreHead), "eXcel HQ", "Bukit Jalil", 1);
    insertAtEnd(centre1, centreHead, centreTail);
    Centre *centre2 = new Centre(getListSize(centreHead), "eXcel Sri Petaling", "Sri Petaling", 3);
    insertAtEnd(centre2, centreHead, centreTail);
    Centre *centre3 = new Centre(getListSize(centreHead), "eXcel Old Klang Road", "Kuchai Lama", 4);
    insertAtEnd(centre3, centreHead, centreTail);

    Tutor *tutor1 = new Tutor(getListSize(tutorHead), "Alan Doe", "ParkHill, Bukit Jalil", "+60123456789", "15/03/2020", "15/03/2021", 100, 20, 0, 0);
    insertAtEnd(tutor1, tutorHead, tutorTail);
    Tutor *tutor2 = new Tutor(getListSize(tutorHead), "Alfred Wyoming", "Pinnacle, Sri Petaling", "+60123456788", "03/08/2021", "", 80, 20, 0, 1);
    insertAtEnd(tutor2, tutorHead, tutorTail);
    Tutor *tutor3 = new Tutor(getListSize(tutorHead), "Alfonso Lee", "Old Klang Road, Kuchai Lama", "+60123456787", "15/03/2020", "", 95, 20, 0, 2);
    insertAtEnd(tutor3, tutorHead, tutorTail);
    Tutor *tutor4 = new Tutor(getListSize(tutorHead), "Altaria Lim", "SS15, Subang Jaya", "+60123456786", "15/03/2020", "15/03/2021", 75, 20, 0, 3);
    insertAtEnd(tutor4, tutorHead, tutorTail);
    Tutor *tutor5 = new Tutor(getListSize(tutorHead), "Anthony Tan", "Taman OUG, Kuala Lumpur", "+60123456785", "03/08/2021", "", 82, 20, 0, 4);
    insertAtEnd(tutor5, tutorHead, tutorTail);

    Tutor *tutor6 = new Tutor(getListSize(tutorHead), "Benjamin Lim", "ParkHill, Bukit Jalil", "+60123456709", "15/03/2020", "15/03/2021", 100, 20, 1, 0);
    insertAtEnd(tutor6, tutorHead, tutorTail);
    Tutor *tutor7 = new Tutor(getListSize(tutorHead), "Brother John", "Pinnacle, Sri Petaling", "+60123456708", "03/08/2021", "", 80, 20, 1, 1);
    insertAtEnd(tutor7, tutorHead, tutorTail);
    Tutor *tutor8 = new Tutor(getListSize(tutorHead), "Betty Yeet", "Old Klang Road, Kuchai Lama", "+60123456707", "15/03/2020", "", 95, 20, 1, 2);
    insertAtEnd(tutor8, tutorHead, tutorTail);
    Tutor *tutor9 = new Tutor(getListSize(tutorHead), "Brendan Kok", "SS15, Subang Jaya", "+60123456706", "15/03/2020", "15/03/2021", 75, 20, 1, 3);
    insertAtEnd(tutor9, tutorHead, tutorTail);
    Tutor *tutor10 = new Tutor(getListSize(tutorHead), "Bennette Tan", "Taman OUG, Kuala Lumpur", "+60123456705", "03/08/2021", "", 82, 20, 1, 4);
    insertAtEnd(tutor10, tutorHead, tutorTail);

    Tutor *tutor11 = new Tutor(getListSize(tutorHead), "Clarence Tee", "ParkHill, Bukit Jalil", "+60123456719", "15/03/2020", "15/03/2021", 100, 20, 2, 0);
    insertAtEnd(tutor11, tutorHead, tutorTail);
    Tutor *tutor12 = new Tutor(getListSize(tutorHead), "Cassandrea Teo", "Pinnacle, Sri Petaling", "+60123456718", "03/08/2021", "", 80, 20, 2, 1);
    insertAtEnd(tutor12, tutorHead, tutorTail);
    Tutor *tutor13 = new Tutor(getListSize(tutorHead), "Christina Tan", "Old Klang Road, Kuchai Lama", "+60123456717", "15/03/2020", "", 95, 20, 2, 2);
    insertAtEnd(tutor13, tutorHead, tutorTail);
    Tutor *tutor14 = new Tutor(getListSize(tutorHead), "Chrysan Kok", "SS15, Subang Jaya", "+60123456716", "15/03/2020", "15/03/2021", 75, 20, 2, 3);
    insertAtEnd(tutor14, tutorHead, tutorTail);
    Tutor *tutor15 = new Tutor(getListSize(tutorHead), "Coconut Tree", "Taman OUG, Kuala Lumpur", "+60123456715", "03/08/2021", "", 82, 20, 2, 4);
    insertAtEnd(tutor15, tutorHead, tutorTail);
}

void archiveTerminated()
{
    // get the current date
    std::string currentDate = getDateToday();
    if (tutorHead == NULL)
    {
        return;
    }
    Tutor *tutor = tutorHead;
    // 2nd reference to continue loop when 1st reference has been deleted
    Tutor *next = tutor;
    // loop through the list of tutors
    while (next != NULL)
    {
        // synchronising both references
        tutor = next;
        if (next->dateTerminated == "")
        {
            next = tutor->nextAddress;
            continue;
        }
        else
        {
            int sixMonthsAgo = getDateDifference(tutor->dateTerminated, currentDate);
            // setup for next iteration of the loop
            next = tutor->nextAddress;
            if (sixMonthsAgo > 180)
            {
                // archive the tutor
                std::cout << "Archiving " << tutor->tutorName << "." << std::endl;
                Archive *archive = new Archive(tutor);
                insertAtEnd(archive, archiveHead, archiveTail);
                deleteNode(tutorHead, tutorTail, tutor->id);
            }
        }
    }
    std::cout << endl;
}

int main()
{
    // set all head and tails to null
    userHead = userTail = NULL;
    subjectHead = subjectTail = NULL;
    centreHead = centreTail = NULL;
    tutorHead = tutorTail = NULL;
    archiveHead = archiveTail = NULL;
    generateMockData();
    archiveTerminated();
    // ------------------------------------------------------LOGIN---------------------------------------------------------------
    User *userLogin = login(userHead);
    if (userLogin->id == 0)
    {
        displayHrMenu();
    }
    else if (userLogin->id == 1)
    {
        displayAdminMenu();
    }
    else
    {
        displayTutorMenu();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
