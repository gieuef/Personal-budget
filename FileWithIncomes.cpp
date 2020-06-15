#include "FileWithIncomes.h"


vector <Income>  FileWithIncomes::loadIncomesOfLoggedInUser(int loggedUserId)
{
    Income income;
    vector <Income> incomes;


    if (isFileEmpty())
        return incomes;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();


    while ( xml.FindElem("income") )
    {
        xml.IntoElem();
        xml.FindElem( "incomeId" );
        string strIncomeId= xml.GetData();

        int intIncomeId= AuxiliaryMethods::convertStringToInteger(strIncomeId) ;
        income.setIncomeId(intIncomeId );
        lastIncomeId = intIncomeId;

        //xml.IntoElem();
        xml.FindElem( "userId" );
        string strUserId = xml.GetData();
        int intUserId = AuxiliaryMethods::convertStringToInteger(strUserId);
        income.setUserId(intUserId);

        //xml.IntoElem();
        xml.FindElem( "date" );
        string strDate = xml.GetData();
        income.setDate(strDate);

        //xml.IntoElem();
        xml.FindElem( "item" );
        string strItem = xml.GetData();

        income.setItem(strItem);

        //xml.IntoElem();
        xml.FindElem( "amount" );
        string strAmount = xml.GetData();
        income.setAmount(AuxiliaryMethods::convertStringToFloat(strAmount));

        xml.OutOfElem();

        if (loggedUserId == intUserId)
            incomes.push_back(income);
    }

    return incomes;
}


bool FileWithIncomes::addIncomeToFile(Income income)
{

    if (isFileEmpty())
        xml.AddElem("Incomes");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("incomeId",income.getIncomeId());
    xml.AddElem("userId",income.getUserId());
    xml.AddElem("date",income.getDate());
    xml.AddElem("item",income.getItem());
    xml.AddElem("amount", AuxiliaryMethods::convertDobuleToString( income.getAmount() ));
    xml.OutOfElem();


    xml.Save(getFileName());

    lastIncomeId++;

    return true;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}

