#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <iostream>
#include <vector>
#include <cstdlib>
//#include "Markup.h"

#include "User.h"
#include "AuxiliaryMethods.h"
//#include "MetodyPomocnicze.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{

CMarkup xml;
    //bool czyPlikJestPusty();
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User uzytkownik);
    //User pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string fileNameOfUsers) : XmlFile(fileNameOfUsers) {};
    void addUserToFile(User user);
    vector <User>  loadUsersFromFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <User> &uzytkownicy);
};



#endif
