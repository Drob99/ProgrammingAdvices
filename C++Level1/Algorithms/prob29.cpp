// Note because of our good code structure we only changed 1 word 

#include <iostream>

using namespace std;

enum enOddOrEven {Odd = 1, Even = 2};

int ReadNumber()
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    return num;
}

enOddOrEven checkOddOrEven(int num){
    if (num %2 == 0)
        return enOddOrEven::Even;
    else
        return enOddOrEven::Odd;
}

int for_sum_of_even_numbers(int num)
{

    cout << "\nUsing For Loop:\n";
    int sum = 0; // to avoid garbage data
    for (int i = 1; i <= num; i++)
    {
        if (checkOddOrEven(i) == enOddOrEven::Even)
        {
            sum += i;
        }
    }
    return sum;
}

int while_sum_of_even_numbers(int num)
{
    cout << "\nUsing While Loop:\n";
    int sum = 0;
    int i = 1;
    while (i <= num)
    {
        if (checkOddOrEven(i) == enOddOrEven::Even)
        {
            sum += i;
        }
        i++;
    }
    return sum;
}

int do_while_sum_of_even_numbers(int num){
    cout << "\nUsing Do While Loop:\n";
    int sum = 0;
    int i = 0;

    do
    {
        i++;  
        if (checkOddOrEven(i) == enOddOrEven::Even)
        {
            sum += i;
        }
              
    } while (i < num);
    
    return sum;
}
int main()
{
    int num = ReadNumber();
    cout << for_sum_of_even_numbers(num) << endl;
    cout << while_sum_of_even_numbers(num) << endl;
    cout << do_while_sum_of_even_numbers(num) << endl;
    return 0;
}