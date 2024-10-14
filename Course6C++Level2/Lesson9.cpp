// Ternary Operator - Shorthand If
# include "D:\Career\C++\AbuHadhoud\Libraries/MyInput.h"
using namespace MyInput;

int main()
{
    int number = ReadNumber("Enter the number: ");

    (number >= 0) ? ((number == 0) ? cout << "The number is zero." : cout << "The number is positive." ) : cout << "The number is negative.";
}