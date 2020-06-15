#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>

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
};



#endif
