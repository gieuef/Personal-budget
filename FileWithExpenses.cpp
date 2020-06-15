#include "FileWithExpenses.h"


vector <Expense>  FileWithExpenses::loadExpensesOfLoggedInUser(int loggedUserId)
{
    Expense expense;
    vector <Expense> expenses;


    if (isFileEmpty())
        return expenses;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();


    while ( xml.FindElem("expense") )
    {
        xml.IntoElem();
        xml.FindElem( "expenseId" );
        string strExpenseId= xml.GetData();

        int intExpenseId= AuxiliaryMethods::convertStringToInteger(strExpenseId) ;
        expense.setExpenseId(intExpenseId );
        lastExpenseId = intExpenseId;

        //xml.IntoElem();
        xml.FindElem( "userId" );
        string strUserId = xml.GetData();
        int intUserId = AuxiliaryMethods::convertStringToInteger(strUserId);
        expense.setUserId(intUserId);

        //xml.IntoElem();
        xml.FindElem( "date" );
        string strDate = xml.GetData();
        expense.setDate(strDate);

        //xml.IntoElem();
        xml.FindElem( "item" );
        string strItem = xml.GetData();

        expense.setItem(strItem);

        //xml.IntoElem();
        xml.FindElem( "amount" );
        string strAmount = xml.GetData();
        expense.setAmount(AuxiliaryMethods::convertStringToFloat(strAmount));

        xml.OutOfElem();

        if (loggedUserId == intUserId)
            expenses.push_back(expense);
    }

    return expenses;
}


bool FileWithExpenses::addExpenseToFile(Expense expense)
{

    if (isFileEmpty())
        xml.AddElem("Expenses");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("expense");
    xml.IntoElem();
    xml.AddElem("expenseId",expense.getExpenseId());
    xml.AddElem("userId",expense.getUserId());
    xml.AddElem("date",expense.getDate());
    xml.AddElem("item",expense.getItem());
    xml.AddElem("amount", AuxiliaryMethods::convertDobuleToString( expense.getAmount() ));
    xml.OutOfElem();


    xml.Save(getFileName());

    lastExpenseId++;

    return true;
}

int FileWithExpenses::getLastExpenseId()
{
    return lastExpenseId;
}
