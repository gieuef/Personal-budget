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
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
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
