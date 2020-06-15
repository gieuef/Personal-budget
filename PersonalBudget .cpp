#include "PersonalBudget.h"

void PersonalBudget::userRegistration()
{
    userManager.userRegistration();
}

bool PersonalBudget::isUserLogged()
{
    return userManager.isUserLoggedIn();
}

char PersonalBudget::chooseOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Logging" << endl;
    cout << "9. End program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}


void PersonalBudget::userLogging()
{
    userManager.userLogging();

    if (userManager.isUserLoggedIn())
    {
        financesManager = new FinancesManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES,  userManager.getLoggedInUserId() );
    }


}

char PersonalBudget::chooseOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. BalanceFromCurrentMonth" << endl;
    cout << "4. BalanceFromPreviousMonth" << endl;
    cout << "5. balanceFromSelectedPeriod" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "9. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}


void PersonalBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        financesManager->addIncome();
    }
    else
    {
        cout << "To add income, please first log in " << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        financesManager->addExpense();
    }
    else
    {
        cout << "To add income, please first log in " << endl;
        system("pause");
    }
}

void PersonalBudget::userLogout()
{
    userManager.userLogout();
    delete financesManager;
    financesManager = NULL;
}

