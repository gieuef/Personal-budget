#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <time.h>
#include <conio.h>
#include <algorithm>
#include <iomanip>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;

class FinancesManager
{
    const int LOGGED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Income enterDataOfNewIncome();
    Expense enterDataOfNewExpense();

public:
    FinancesManager(string fileNameOfIncomes, string fileNameOfExpenses, int loggedInUserId)
    : fileWithIncomes(fileNameOfIncomes), fileWithExpenses(fileNameOfExpenses), LOGGED_IN_USER_ID(loggedInUserId  )
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUser(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesOfLoggedInUser(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();
    void balanceFromCurrentMonth();
    void balanceFromPreviousMonth();
    void balanceFromSelectedPeriod();



};

#endif
