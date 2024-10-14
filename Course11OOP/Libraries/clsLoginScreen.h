#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include <fstream>
#include "../Libraries/clsString.h"
#include <vector>

class clsLoginScreen : protected clsScreen
{

private:
    static bool _Login()
    {
        bool LoginFailed = false;
        short FailedLoginCount = 0;

        string UserName, Password;
        do
        {
            if (LoginFailed)
            {
                cout << "\nInvalid UserName/Password!";
                FailedLoginCount++;
                cout << "\nYou have " << 3 - FailedLoginCount << " Trials to login.\n\n";
            }

            if (FailedLoginCount == 3)
            {
                cout << "\nYou are Locked after " << FailedLoginCount << " failed Trial(s).";
                return false;
            }

            cout << "Enter UserName? ";
            cin >> UserName;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(UserName, Password);

            LoginFailed = CurrentUser.IsEmpty();
        } while (LoginFailed);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenu();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("\t  Login Screen");
        return clsLoginScreen::_Login();
    }
};