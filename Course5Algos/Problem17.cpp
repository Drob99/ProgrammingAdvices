// Guess a 3 letter password
# include <iostream>

using namespace std;

string ReadPassword(string message)
{
    string password = "";
    cout << message;
    cin >> password;
    return password;
}

bool CheckPassword(string Password, string input)
{
    return Password == input;
}

void GuessPassword(string input) // could be of type bool
{
    string word = "";
    int trial = 1;
    for (char i = 'A'; i <= 'Z'; i++)
        for (char j = 'A'; j <= 'Z'; j++)
            for (char k = 'A'; k <= 'Z'; k++)
            {
                word += char(i); 
                word += char(j); 
                word += char(k);
                cout << "Trial [" << trial << "]: " << word << "\n";

                if (CheckPassword(word, input))
                {
                    cout << "\nPassword is " << word << endl;
                    cout << "Found after " << trial << " Trial(s)";
                    return;
                }

                word = "";
                trial++;
            }
                
}

int main()
{
    GuessPassword(ReadPassword("Please enter a 3-letter password all capitals: "));

    return 0;
}