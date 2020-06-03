#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
    PersonalBudget(string fileNameOfUsers)
     : userManager(fileNameOfUsers)
    {
    };

    void userRegistration();
    //void userLogging();
    //void addIncome();
    //void addExpense();
    //void balanceFromCurrentMonth();
    //void balanceFromPreviousMonth();
    //void balanceFromSelectedPeriod();
    char chooseOptionFromMainMenu();
    //char chooseOptionFromUserMenu();
    bool isUserLogged();
    //void changeLoggedUserPassword();
    //void userLogout();
};

#endif
