// Number To Text
#include "../Libraries/MyInput.h"
#include "../Libraries/MyFunctions.h"
#include <string>

using namespace std;

string NumberToText(int Number)
{
    // Base Cases
    if (Number == 0)
        return "";

    else if (Number >= 1 && Number <= 19)
    {
        string BelowTwenty[] =
            {
                "One", "Two", "Three", "Four", "Five",
                "Six", "Seven", "Eight", "Nine", "Ten",
                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        return BelowTwenty[Number - 1];
    }

    else if (Number >= 20 && Number <= 99)
    {
        string Tens[] =
            {
                "Twenty", "Thirty", "Fourty", "Fifty",
                "Sixty", "Seventy", "Eighty", "Ninety"};

        return Tens[Number / 10 - 2] + " " + NumberToText(Number % 10);
    }

    else if (Number >= 100 && Number <= 999)
    {
        return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
    }

    else if (Number >= 1000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
    }

    else if (Number >= 1000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
    }

    else
    {
        return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
    }
}

int main()
{
    int Number = MyInput::ReadNumber("\nEnter a Number? ");

    cout << NumberToText(Number);

    return 0;
}