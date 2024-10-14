// Print all words from AAA to ZZZ
# include <iostream>

using namespace std;

void PrintWordsFromAAAtoZZZ()
{
    for (char i = 'A'; i <= 'Z'; i++)
        for (char j = 'A'; j <= 'Z'; j++)
            for (char k = 'A'; k <= 'Z'; k++)
                cout << i << j << k << "\n"; 
}

int main()
{
    PrintWordsFromAAAtoZZZ();

    return 0;
}