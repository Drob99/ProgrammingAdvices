// Invert Character Case

# include "D:\Career\C++\AbuHadhoud\Libraries\MyInput.h"
# include "D:\Career\C++\AbuHadhoud\Libraries\MyFunctions.h"
# include <string>
# include <cctype>

using namespace std;

char InvertCharCase(char Character)
{
    return isupper(Character) ? tolower(Character) : toupper(Character);
}

int main()
{
    char Character = MyInput::ReadChar("Please Enter Your Character?");
    
    cout << "\nChar after inverting case:\n";
    cout << InvertCharCase(Character);
    

}