#ifndef XMLFILE_H
#define XMLFILE_H


#include <iostream>
#include "Markup.h"

using namespace std;

class XmlFile {

    const string FILE_NAME;


public:

    XmlFile(string fileName) : FILE_NAME(fileName) {
    }

    string getFileName()
    {
        return FILE_NAME;
    }

     bool isFileEmpty()
    {
        CMarkup xml;
        bool empty = true;

        bool fileExists = xml.Load( getFileName() );

        if (fileExists) empty = false;

        return empty;
    }


};

#endif
