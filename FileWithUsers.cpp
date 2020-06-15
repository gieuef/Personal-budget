#include "FileWithUsers.h"


vector <User>  FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;


    if (isFileEmpty())
        return users;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();


    while ( xml.FindElem("user") )
    {
        xml.IntoElem();
        xml.FindElem( "userId" );
        string strUserID = xml.GetData();

        user.setUserId(AuxiliaryMethods::convertStringToInteger(strUserID) );

        //xml.IntoElem();
        xml.FindElem( "login" );
        string strLogin = xml.GetData();
        user.setLogin(strLogin);

        //xml.IntoElem();
        xml.FindElem( "password" );
        string strPassword = xml.GetData();
        user.setPassword(strPassword);

        //xml.IntoElem();
        xml.FindElem( "name" );
        string strName = xml.GetData();

        user.setName(strName);

        //xml.IntoElem();
        xml.FindElem( "surname" );
        string strSurname = xml.GetData();
        user.setSurname(strSurname);

        xml.OutOfElem();

        users.push_back(user);
    }

    return users;
}


void FileWithUsers::addUserToFile(User user)
{

    if (isFileEmpty())
        xml.AddElem("Users");

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("user");
    xml.IntoElem();
    xml.AddElem("userId",user.getUserId());
    xml.AddElem("login",user.getLogin());
    xml.AddElem("password",user.getPassword());
    xml.AddElem("name",user.getName());
    xml.AddElem("surname",user.getSurname());
    xml.OutOfElem();


    xml.Save(getFileName());


}
