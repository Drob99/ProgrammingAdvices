#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "../Libraries/clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.GetFirstName();
        cout << "\nLastName    : " << User.GetLastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.GetEmail();
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";
    }

public:
    static void ShowDeleteUserScreen()
    {
        clsScreen::_DrawScreenHeader("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter User Name: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExists(UserName))
        {
            cout << "\nUser Name is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        clsDeleteUserScreen::_PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (tolower(Answer) == 'y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                clsDeleteUserScreen::_PrintUser(User1);
            }

            else
            {
                cout << "\nError User Was Not Deleted\n";
            }
        }
    }
};