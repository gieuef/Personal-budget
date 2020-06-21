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

void FinancesManager::balanceFromCurrentMonth()
{
    vector <Income> incomesToBalance;
    vector <Expense> expensesToBalnace;

    string balanceBeginDate ,balanceEndDate;
    double sumOfIncomes=0.0, sumOfExpenses=0.0;


    system("cls");
    cout << " >>> BALANCE FROM CURRENT MONTH <<<" << endl << endl;
    cout << "INCOMES:" << endl;


    balanceEndDate = AuxiliaryMethods::getTodaysDate();



    time_t czas;
    struct tm * ptr;
    string year, month, day, date;

    time( & czas );
    ptr = localtime( & czas );

    year = AuxiliaryMethods::convertIntToString( ptr->tm_year+1900);
    month = AuxiliaryMethods::convertIntToString( ptr->tm_mon+1);
    if (month.length() == 1)
        month="0"+month;

   balanceBeginDate = year + "-" + month + "-01";


   for (int i=0; i<incomes.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(incomes[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,incomes[i].getDate()  )  ) )
        incomesToBalance.push_back(incomes[i]);

        sort(incomesToBalance.begin() , incomesToBalance.end() , AuxiliaryMethods::compareIncomeByDate );


        for (int i=0; i<expenses.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(expenses[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,expenses[i].getDate()  )  ) )
        expensesToBalnace.push_back(expenses[i]);

        sort(expensesToBalnace.begin() , expensesToBalnace.end() , AuxiliaryMethods::compareExpenseByDate );



for (int i=0; i<incomesToBalance.size(); i++)
{
    sumOfIncomes+=incomesToBalance[i].getAmount();
    cout << incomesToBalance[i].getDate() << "   ";
    cout << incomesToBalance[i].getItem() << "   ";
    cout << incomesToBalance[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;

 cout <<setprecision(2)<<fixed<< " Sum of incomes:      " << sumOfIncomes << endl << endl;
 cout << "EXPENSES:" << endl;

 for (int i=0; i<expensesToBalnace.size(); i++)
{
    sumOfExpenses+=expensesToBalnace[i].getAmount();
    cout << expensesToBalnace[i].getDate() << "   ";
    cout << expensesToBalnace[i].getItem() << "   ";
    cout << expensesToBalnace[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;


  cout <<setprecision(2)<<fixed<< " Sum of expenses:      " << sumOfExpenses << endl << endl;

 cout <<setprecision(2)<<fixed<< " BALANCE:           " << sumOfIncomes-sumOfExpenses << endl;


system("pause");
incomesToBalance.clear();
expensesToBalnace.clear();

}


void FinancesManager::balanceFromPreviousMonth()
{
    vector <Income> incomesToBalance;
    vector <Expense> expensesToBalnace;

    string balanceBeginDate ,balanceEndDate;
    double sumOfIncomes=0.0, sumOfExpenses=0.0;


    system("cls");
    cout << " >>> BALANCE FROM PREVIOUS MONTH <<<" << endl << endl;
    cout << "INCOMES:" << endl;


    balanceBeginDate = AuxiliaryMethods::getPreviousMonthBeginDate();

    balanceEndDate = AuxiliaryMethods::getPreviousMonthEndDate();


   for (int i=0; i<incomes.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(incomes[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,incomes[i].getDate()  )  ) )
        incomesToBalance.push_back(incomes[i]);

        sort(incomesToBalance.begin() , incomesToBalance.end() , AuxiliaryMethods::compareIncomeByDate );


        for (int i=0; i<expenses.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(expenses[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,expenses[i].getDate()  )  ) )
        expensesToBalnace.push_back(expenses[i]);

        sort(expensesToBalnace.begin() , expensesToBalnace.end() , AuxiliaryMethods::compareExpenseByDate );



for (int i=0; i<incomesToBalance.size(); i++)
{
    sumOfIncomes+=incomesToBalance[i].getAmount();
    cout << incomesToBalance[i].getDate() << "   ";
    cout << incomesToBalance[i].getItem() << "   ";
    cout << incomesToBalance[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;

 cout <<setprecision(2)<<fixed<< " Sum of incomes:      " << sumOfIncomes << endl << endl;
 cout << "EXPENSES:" << endl;

 for (int i=0; i<expensesToBalnace.size(); i++)
{
    sumOfExpenses+=expensesToBalnace[i].getAmount();
    cout << expensesToBalnace[i].getDate() << "   ";
    cout << expensesToBalnace[i].getItem() << "   ";
    cout << expensesToBalnace[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;


  cout <<setprecision(2)<<fixed<< " Sum of expenses:      " << sumOfExpenses << endl << endl;

 cout <<setprecision(2)<<fixed<< " BALANCE:           " << sumOfIncomes-sumOfExpenses << endl;


system("pause");

incomesToBalance.clear();
expensesToBalnace.clear();

}


void FinancesManager::balanceFromSelectedPeriod()
{
    vector <Income> incomesToBalance;
    vector <Expense> expensesToBalnace;

    string balanceBeginDate ,balanceEndDate;
    double sumOfIncomes=0.0, sumOfExpenses=0.0;


    system("cls");

    cout << "Enter begin date in format yyyy-mm-dd. Date must be from 2000-01-01 to last day of current month" << endl;
        balanceBeginDate = AuxiliaryMethods::loadDate();

        cout << "Enter end date in format yyyy-mm-dd. Date must be from 2000-01-01 to last day of current month" << endl;
        cout << "Important! Begin date must be earlier than end date " << endl;
        balanceEndDate = AuxiliaryMethods::loadDate();


    cout << endl << " >>> BALANCE FROM SELECTED PERIOD <<<" << endl << endl;
    cout << "INCOMES:" << endl;



   for (int i=0; i<incomes.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(incomes[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,incomes[i].getDate()  )  ) )
        incomesToBalance.push_back(incomes[i]);

        sort(incomesToBalance.begin() , incomesToBalance.end() , AuxiliaryMethods::compareIncomeByDate );


        for (int i=0; i<expenses.size(); i++)
    if (   !(AuxiliaryMethods::compareTwoDates(expenses[i].getDate(), balanceBeginDate)) && !(AuxiliaryMethods::compareTwoDates(balanceEndDate,expenses[i].getDate()  )  ) )
        expensesToBalnace.push_back(expenses[i]);

        sort(expensesToBalnace.begin() , expensesToBalnace.end() , AuxiliaryMethods::compareExpenseByDate );



for (int i=0; i<incomesToBalance.size(); i++)
{
    sumOfIncomes+=incomesToBalance[i].getAmount();
    cout << incomesToBalance[i].getDate() << "   ";
    cout << incomesToBalance[i].getItem() << "   ";
    cout << incomesToBalance[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;

 cout <<setprecision(2)<<fixed<< " Sum of incomes:      " << sumOfIncomes << endl << endl;
 cout << "EXPENSES:" << endl;

 for (int i=0; i<expensesToBalnace.size(); i++)
{
    sumOfExpenses+=expensesToBalnace[i].getAmount();
    cout << expensesToBalnace[i].getDate() << "   ";
    cout << expensesToBalnace[i].getItem() << "   ";
    cout << expensesToBalnace[i].getAmount() << endl;
}

 cout << "---------------------------" << endl << endl;


  cout <<setprecision(2)<<fixed<< " Sum of expenses:      " << sumOfExpenses << endl << endl;

 cout <<setprecision(2)<<fixed<< " BALANCE:           " << sumOfIncomes-sumOfExpenses << endl;


system("pause");

incomesToBalance.clear();
expensesToBalnace.clear();

}
