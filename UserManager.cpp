#include "UserManager.h"

void UserManager::userRegistration()
{
    User user = getNewUserData();

    users.push_back(user);

    fileWithUsers.addUserToFile(user);

    cout << endl << "Account created" << endl << endl;
    system("pause");
    cin.ignore();
}

User UserManager::getNewUserData()
{
    User user;

    user.setUserId(getNewUserId());
    string login;

    do
    {
        cout << "Enter login: ";
        cin >> login ;
        user.setLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    cout << "Enter password: ";
    string password;
    cin >> password;
    user.setPassword(password);

    cout << "Enter name: ";
    string name;
    cin >> name;
    user.setName(name);

    cout << "Enter surname: ";
    string surname;
    cin >> surname;
    user.setSurname(surname);


    return user;
}


int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}



bool UserManager::loginExists(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Login exists. Enter another login" << endl;
            return true;
        }
    }
    return false;

}

bool UserManager::isUserLoggedIn()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;

}


void UserManager::userLogging()
{
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempts = 3; attempts > 0; attempts--)
            {
                cout << "Enter password. Attempts left " << attempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    loggedUserId = itr -> getUserId();
                    cout << endl << "You are logged in" << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "you entered incorrectly password 3 times" << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "User with such login doesn't exist" << endl << endl;
    system("pause");
    return;

}

int UserManager::getLoggedInUserId()
{
    return loggedUserId;
}


void UserManager::userLogout()
{
    loggedUserId = 0;
}
