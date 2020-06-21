#include "AuxiliaryMethods.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>


string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDobuleToString(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}


string AuxiliaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}


int AuxiliaryMethods::convertStringToInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

double AuxiliaryMethods::convertStringToFloat(string number)
{
    double dNum=0.0;

    dNum = atof(number.c_str());

    return dNum;
}


char AuxiliaryMethods::loadChar()
{
    string input = "";
    char character  = {0};


    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please try again" << endl;
    }
    return character;
}

string AuxiliaryMethods::getTodaysDate()
{
    time_t czas;
    struct tm * ptr;
    string year, month, day, date;

    time( & czas );
    ptr = localtime( & czas );

    year = convertIntToString( ptr->tm_year+1900);
    month = convertIntToString( ptr->tm_mon+1);
    if (month.length() == 1)
        month="0"+month;
    day = convertIntToString( ptr->tm_mday);
    if (day.length() == 1)
        day="0"+day;


    date = year + "-" + month + "-" + day;
    return date;


}

double AuxiliaryMethods::loadAmount()
{
    string input = "";
    getline(cin, input);

    int position = input.find(",");
    if(position!=string::npos)
        input.replace(position,1,1,'.');

    return convertStringToFloat(input);

}

string AuxiliaryMethods::loadDate()
{
    string input = "";
    string str;

    int numberOfdaysInMonthTab[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int numberOfdaysInMonth;
    int currentMonth, currentYear;

    time_t czas;
    struct tm * ptr;

    time( & czas );
    ptr = localtime( & czas );

    currentMonth=ptr->tm_mon+1;
    currentYear=ptr->tm_year+1900;

    while (true)
    {
        getline(cin, input);
        if (input.length()==10)
            if ((input[4]=='-') && (input[7]=='-') )
            {
                int inputYear = convertStringToInteger( str.assign(input,0,4) );
                int inputMonth = convertStringToInteger( str.assign(input,5,2));
                int inputDay = convertStringToInteger(str.assign(input,8,2));

                numberOfdaysInMonth=numberOfdaysInMonthTab[inputMonth-1];
                if (numberOfdaysInMonth == 28)
                    if (((inputYear % 4 == 0) && (inputYear % 100 != 0)) || (inputYear % 400 == 0))
                        numberOfdaysInMonth++;


                if ((inputYear == currentYear) && (inputMonth <= currentMonth) && (inputDay <= numberOfdaysInMonth))
                    return input;

                if ((inputYear>=2000) && (inputYear<currentYear) )
                    if  (inputDay <= numberOfdaysInMonth )
                        return input;

            }
        cout<<" Inccorect input format. Enter correct date again " << endl;
    }

    return input;
}



string AuxiliaryMethods::getPreviousMonthBeginDate()
{
    string previousMonthBeginDate = "";
    string str;

    int previousMonth, previousYear;

    time_t czas;
    struct tm * ptr;

    time( & czas );
    ptr = localtime( & czas );

    previousMonth=ptr->tm_mon;
    previousYear=ptr->tm_year+1900;


                        string month = AuxiliaryMethods::convertIntToString(previousMonth);
                        if (month.length() == 1)
        month="0"+month;

           previousMonthBeginDate = AuxiliaryMethods::convertIntToString(previousYear) + "-" + month + "-01";

           return previousMonthBeginDate;
}

string AuxiliaryMethods::getPreviousMonthEndDate()
{
    string previousMonthEndDate = "";
    string str;

    int numberOfdaysInMonthTab[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int numberOfdaysInMonth;
    int previousMonth, previousYear;

    time_t czas;
    struct tm * ptr;

    time( & czas );
    ptr = localtime( & czas );

    previousMonth=ptr->tm_mon;
    previousYear=ptr->tm_year+1900;



                numberOfdaysInMonth=numberOfdaysInMonthTab[previousMonth-1];
                if (numberOfdaysInMonth == 28)
                    if (((previousYear % 4 == 0) && (previousYear % 100 != 0)) || (previousYear % 400 == 0))
                        numberOfdaysInMonth++;

                        string month = AuxiliaryMethods::convertIntToString(previousMonth);
                        if (month.length() == 1)
        month="0"+month;

           previousMonthEndDate = AuxiliaryMethods::convertIntToString(previousYear) + "-" + month + "-" + AuxiliaryMethods::convertIntToString(numberOfdaysInMonth);

           return previousMonthEndDate;
}


bool AuxiliaryMethods::compareIncomeByDate(Income i1, Income i2)
{
    return compareTwoDates(i1.getDate(), i2.getDate());
}


bool AuxiliaryMethods::compareExpenseByDate(Expense e1, Expense e2)
{
    return compareTwoDates(e1.getDate(), e2.getDate());
}

bool AuxiliaryMethods::compareTwoDates(string d1, string d2)
{
    string str;
    int day1,month1,year1;
    int day2,month2,year2;
    time_t t;
    struct tm * date1;
    struct tm * date2;

    year1 = convertStringToInteger( str.assign(d1,0,4) );
    month1 = convertStringToInteger( str.assign(d1,5,2));
    day1 = convertStringToInteger(str.assign(d1,8,2));

    year2 = convertStringToInteger( str.assign(d2,0,4) );
    month2 = convertStringToInteger( str.assign(d2,5,2));
    day2 = convertStringToInteger(str.assign(d2,8,2));

    time( & t );
    date1 = localtime( & t );

    date1->tm_year = year1 - 1900;
    date1->tm_mon = month1 - 1;
    date1->tm_mday = day1;

    time_t tDate1 = mktime(date1);

    date2 = localtime(& t);
    date2->tm_year = year2 - 1900;
    date2->tm_mon = month2 - 1;
    date2->tm_mday = day2;

    time_t tDate2 = mktime(date1);

    if (difftime(tDate2,tDate1) > 0.0 ) return true; else return false;
}





