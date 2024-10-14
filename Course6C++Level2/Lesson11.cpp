// Validate Number

#include "../Libraries/MyInput.h"

using namespace MyInput;

int main()
{
    int number = ReadPositiveNumber("Enter a positive number: ");
    cout << "This is a postive number: " << number;
}