#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include "Income.h"
#include "Expense.h"

using namespace std;

class AuxiliaryMethods
{
public:
   static string convertDobuleToString(double number);
   static string loadLine();
   static int convertStringToInteger(string liczba);
   static string convertIntToString(int number);
   static char loadChar();
   static double convertStringToFloat(string number);
   static double loadAmount();
   static string loadDate();
   static string getTodaysDate();
   static bool compareIncomeByDate(Income i1, Income i2);
   static bool compareExpenseByDate(Expense e1, Expense e2);
   static bool compareTwoDates(string d1, string d2);
   static string getPreviousMonthBeginDate();
   static string getPreviousMonthEndDate();
};



#endif
