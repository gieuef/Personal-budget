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
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Logging" << endl;
    cout << "9. End program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}


