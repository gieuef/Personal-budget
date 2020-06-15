#include "AuxiliaryMethods.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <locale>


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

/*
int AuxiliaryMethods::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

string AuxiliaryMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}
*/
