#include "pch.h"

using namespace std;

int main()
{
    // create user object
    User *user1 = new User(1, "user1", "password1", 0);
    // cout user object
    cout << user1->userId << " " << user1->username << " " << user1->password << " " << user1->userType << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
