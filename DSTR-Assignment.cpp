#include "pch.h"

using namespace std;

int main()
{
    // create all objects from header files
    User *user1 = new User(1, "woulin", "password1", 0);
    Tutor *tutor1 = new Tutor(1, "weo", "tutorAddress1", "tutorPhoneNumber1", "dateJoined1", "dateTerminated1", 1, 1, 1, 1);
    Subject *subject1 = new Subject(1, "wrogramming", 1);
    Centre *centre1 = new Centre(1, "wark hill", "centreLocation1", 1);

    // cout all objects
    cout << "username: " << user1->username << endl;
    cout << "tutor Name: " << tutor1->tutorName << endl;
    cout << "subject Name: " << subject1->subjectName << endl;
    cout << "centre Name: " << centre1->centreName << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
