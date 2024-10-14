#pragma once
#include <iostream>
#include "clsScreen.h"
#include "../Libraries/clsInputValidate.h"
#include <iomanip>
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen
{

private:
    enum enCurrencyExchangeMenuOptions
    {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateRate = 3,
        eCurrencyCalculator = 4,
        eShowMainMenu = 5
    };

    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 to 5? ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        //  cout << "\n List Currencies Screen will be here.\n";
        clsListCurrenciesScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen()
    {
        // cout << "\n Find Currency Screen will be here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _UpdateRateScreen()
    {
        // cout << "\n Update Rate Screen will be here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        // cout << "\nCurrency Calculator Screen will be here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menu...";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }

    static void _PerformCurrencyExchangeMenuOption(enCurrencyExchangeMenuOptions CurrencyExchangeMenuOption)
    {
        switch (CurrencyExchangeMenuOption)
        {
        case enCurrencyExchangeMenuOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOptions::eUpdateRate:
        {
            system("cls");
            _UpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;
        }

        case enCurrencyExchangeMenuOptions::eShowMainMenu:
        {
            // do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:
    static void ShowCurrencyExchangeMenu()
    {

        system("cls");
        _DrawScreenHeader("\tCurrency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
    }
};