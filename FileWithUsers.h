#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{

CMarkup xml;

public:
    FileWithUsers(string fileNameOfUsers) : XmlFile(fileNameOfUsers) {};
    void addUserToFile(User user);
    vector <User>  loadUsersFromFile();
};



#endif
