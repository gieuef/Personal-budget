#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H


#include <iostream>
#include <vector>
#include <cstdlib>
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;


class FileWithExpenses : public XmlFile
{
    CMarkup xml;

    int lastExpenseId;

    public:
    FileWithExpenses(string fileNameOfExpenses) : XmlFile(fileNameOfExpenses) {
    lastExpenseId = 0;
    };
    bool addExpenseToFile(Expense expense);
    vector <Expense>  loadExpensesOfLoggedInUser(int loggedUserId);
    int getLastExpenseId();
};


#endif
