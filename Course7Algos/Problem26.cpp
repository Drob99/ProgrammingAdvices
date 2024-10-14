// Upper/Lower All Letters in String

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>


using namespace std;

string LowerAllString(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = tolower(Sentence[i]);
    }

    return Sentence;
}

string UpperAllString(string Sentence)
{

    for (short i = 0; i < Sentence.length(); i++)
    {
        Sentence[i] = toupper(Sentence[i]);
    }

    return Sentence;
}

int main()
{
    string Sentence = MyInput::ReadString("Please Enter Your String?");

    cout << "\nString after Upper:\n";
    cout << UpperAllString(Sentence);
    
    cout << "\n\nString after Lower:\n";
    cout << LowerAllString(Sentence);

}