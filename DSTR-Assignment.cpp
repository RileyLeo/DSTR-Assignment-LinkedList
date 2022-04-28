#include "pch.h"
#include "functions.h"
#include "user.h"
#include "centre.h"
#include "subject.h"
#include "tutor.h"
#include "dashboard.h"

using namespace std;
// insert at end of the list

int main()
{
    // set all head and tails to null
    userHead = userTail = NULL;
    subjectHead = subjectTail = NULL;
    centreHead = centreTail = NULL;
    tutorHead = tutorTail = NULL;
    // create new user object
    User *user = new User(getListSize(userHead), "hr", "123", 0);
    insertAtEnd(user, userHead, userTail);

    User *user1 = new User(getListSize(userHead), "admin", "123", 1);
    insertAtEnd(user1, userHead, userTail);

    User *user2 = new User(getListSize(userHead), "tutor", "123", 2);
    insertAtEnd(user2, userHead, userTail);

    // function testing
    // cout << getDateToday() << endl;

    // User *user3 = linearSearch(userHead, userTail, 1);
    // cout << user3->id << endl;

    // deleteNode(userHead, userTail, 4);
    // displayUserList();
    // end of function testing

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
