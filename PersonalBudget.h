#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "FinancesManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;
    FinancesManager *financesManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;


public:
    PersonalBudget(string fileNameOfUsers, string fileNameOfIncomes, string fileNameOfExpenses)
     : userManager(fileNameOfUsers), FILE_NAME_WITH_INCOMES(fileNameOfIncomes), FILE_NAME_WITH_EXPENSES(fileNameOfExpenses)
    {
        financesManager = NULL;
    };
    ~PersonalBudget()
    {
        delete financesManager;
        financesManager = NULL;
    }

    void userRegistration();
    void userLogging();
    void addIncome();
    void addExpense();
    //void balanceFromCurrentMonth();
    //void balanceFromPreviousMonth();
    //void balanceFromSelectedPeriod();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    bool isUserLogged();
    //void changeLoggedUserPassword();
    void userLogout();
};

#endif
