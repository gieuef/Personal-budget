#include "FinancesManager.h"


void FinancesManager::addIncome()
{
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = enterDataOfNewIncome();

    incomes.push_back(income);

    if (fileWithIncomes.addIncomeToFile(income))
        cout << "New income added" << endl;
    else
        cout << "Error. Addind new income to file failed." << endl;

    system("pause");
}

void FinancesManager::addExpense()
{
    Expense expense;

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = enterDataOfNewExpense();

    expenses.push_back(expense);

    if (fileWithExpenses.addExpenseToFile(expense))
        cout << "New expense added" << endl;
    else
        cout << "Error. Addind new expense to file failed." << endl;

    system("pause");
}


Income FinancesManager::enterDataOfNewIncome()
{
    Income income;
    int incomeId, userId;
    string date, item;
    double amount;
    char choice;

    income.setIncomeId( fileWithIncomes.getLastIncomeId() +1 );
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Is income from today? (y/n)";
    choice = AuxiliaryMethods::loadChar();


    if (choice == 'y')
        date =AuxiliaryMethods::getTodaysDate();
    else if (choice == 'n')
    {
        cout << "Enter date in format yyyy-mm-dd. Date must be from 2000-01-01 to last day of current month" << endl;
        date = AuxiliaryMethods::loadDate();
    }
    else
    {
        cout << "Enter yes or no";
    }


    cout << "Enter kind of item:";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Enter amount of item:";
    amount =  AuxiliaryMethods::loadAmount();
    income.setAmount(amount);


    income.setDate(date);

    return income;

}


Expense FinancesManager::enterDataOfNewExpense()
{
    Expense expense;
    int expenseId, userId;
    string date, item;
    double amount;
    char choice;

    expense.setExpenseId( fileWithExpenses.getLastExpenseId() +1 );
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Is expense from today? (y/n)";
    choice = AuxiliaryMethods::loadChar();


    if (choice == 'y')
        date =AuxiliaryMethods::getTodaysDate();
    else if (choice == 'n')
    {
        cout << "Enter date in format yyyy-mm-dd. Date must be from 2000-01-01 to last day of current month" << endl;
        date = AuxiliaryMethods::loadDate();
    }
    else
    {
        cout << "Enter yes or no";
    }


    cout << "Enter kind of item:";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Enter amount of item:";
    amount =  AuxiliaryMethods::loadAmount();
    expense.setAmount(amount);


    expense.setDate(date);

    return expense;

}
