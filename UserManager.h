#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);


public:
    UserManager(string fileNameOfUsers) : fileWithUsers(fileNameOfUsers)
    {
        loggedUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    }
    void userRegistration();
    void userLogging();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    void userLogout();
    void changeLoggedUserPassword();

};


#endif
