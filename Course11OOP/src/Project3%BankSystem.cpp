#include <iostream>
#include <ctype.h>
#include <iomanip>

#include "..\Course11OOP/Libraries/clsLoginScreen.h"

int main()
{
    // clsMainScreen::ShowMainMenu();
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
    }
    return 0;
}