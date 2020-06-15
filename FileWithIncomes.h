#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H


#include <iostream>
#include <vector>
#include <cstdlib>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;


class FileWithIncomes : public XmlFile
{
    CMarkup xml;

    int lastIncomeId;

    public:
    FileWithIncomes(string fileNameOfIncomes) : XmlFile(fileNameOfIncomes) {
    lastIncomeId = 0;
    };
    bool addIncomeToFile(Income income);
    vector <Income>  loadIncomesOfLoggedInUser(int loggedUserId);
    int getLastIncomeId();
};


#endif
