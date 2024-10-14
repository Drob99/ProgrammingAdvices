#include <iostream>
using namespace std;

void print_pairs_of_letters()
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            cout << char('A' + i) << char('A' + j) << endl;
        }
    }
}

void print_pyramid_of_numbers(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_reverse_pyramid_of_numbers(int num)
{
    for (int i = 0; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print_letter_pyramids(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
}

void print_reverse_stars(int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void print_another_pyramid_of_numbers(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = i; j <= num; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    print_another_pyramid_of_numbers(10);
    return 0;
}