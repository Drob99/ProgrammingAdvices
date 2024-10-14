#include <iostream>
#include <iomanip>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "../Libraries/clsInputValidate.h"
#include <string>

class clsCurrencyCalculatorScreen : protected clsScreen
{
private:
    static void _PrintCurrencyCard(clsCurrency Currency, string Title)
    {
        cout << "\n"
             << Title << "\n";
        cout << "____________________________\n";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate (1$) : " << Currency.GetRate();
        cout << "\n____________________________\n";
    }

    static clsCurrency _ReadCurrency(string message)
    {
        string Code;
        cout << message;
        Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExists(Code))
        {
            cout << "\nCurrency Not Found. Please enter another one:\n";
            Code = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(Code);
        return Currency;
    }

    static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
    {
        if (Currency1.CurrencyCode() != "USD")
        {
            _PrintCurrencyCard(Currency1, "Convert From:");

            float AmountInUSD = Currency1.ConvertToUSD(Amount);

            cout << "\n"
                 << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInUSD << " USD\n";
        }
        if (Currency2.CurrencyCode() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD:";

        _PrintCurrencyCard(Currency2, "To:");

        float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

        cout << "\n"
             << Amount << " " << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << "\n";
    }

public:
    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';
        while (tolower(Continue) == 'y')
        {
            system("cls");
            clsScreen::_DrawScreenHeader("\tCurrency Calculator Screen");

            clsCurrency CurrencyFrom = _ReadCurrency("\nPlease Enter Currency1 Code:\n");
            clsCurrency CurrencyTo = _ReadCurrency("\nPlease Enter Currency2 Code:\n");

            cout << "\nPlease Enter Amount: ";
            float Amount = clsInputValidate::ReadFloatNumberBetween(0, INT_MAX, "\nMoney cannot be negative. Enter another amount: ");

            _PrintCalculationResults(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation [y/n] ? ";
            cin >> Continue;
        }
    }
};