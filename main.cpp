#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{


    PersonalBudget personalBudget("users.xml","incomes.xml","expenses.xml");

    char choice;


    while (true)
    {
        if (personalBudget.isUserLogged() == 0)
        {
            choice = personalBudget.chooseOptionFromMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Option is not avaible in menu" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.chooseOptionFromUserMenu();


            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            /*
            case '3':
            personalBudget.balanceFromCurrentMonth();
            break;
            case '4':
            personalBudget.balanceFromPreviousMonth();
            break;
            case '5':
            personalBudget.balanceFromSelectedPeriod();
            break;
            case '6':
            personalBudget.changeLoggedUserPassword();
            break;
            */
            case '9':
                personalBudget.userLogout();
                break;
            }
        }
    }

    return 0;
}
