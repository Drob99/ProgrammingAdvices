#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsCurrency.h"
#include "../Libraries/clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n____________________________";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate (1$) : " << Currency.GetRate();
        cout << "\n____________________________\n";
    }

public:
    static void ShowFindCurrencyScreen()
    {
        clsScreen::_DrawScreenHeader("\tFind Currency Screen");

        short Choice;
        cout << "\nFind By: [1] Code or [2] Country ? ";
        Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter 1 or 2: ");

        clsCurrency Currency1 = clsCurrency::FindByCode("");

        if (Choice == 1)
        {
            string Code = clsInputValidate::ReadString("\nPlease Enter Code: ");
            Currency1 = clsCurrency::FindByCode(Code);
        }

        if (Choice == 2)
        {
            string Country = clsInputValidate::ReadString("\nPlease Enter Country Name: ");
            Currency1 = clsCurrency::FindByCountry(Country);
        }

        if (!Currency1.IsEmpty())
        {
            cout << "\nCurrency Found :-)\n";
        }

        else
        {
            cout << "\nCurrency was NOT found :-(\n";
        }

        clsFindCurrencyScreen::_PrintCurrency(Currency1);
    }
};