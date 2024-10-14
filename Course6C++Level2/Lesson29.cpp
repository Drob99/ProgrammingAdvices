# include <iostream>
# include <vector>
# include <D:\Career\C++\AbuHadhoud\Libraries\MyInput.h>
using namespace std;
using namespace MyInput;

void ReadVector(vector <int> &vNumbers)
{
    char input;
    do
    {
        int Number = ReadNumber("Enter number: ");
        vNumbers.push_back(Number);

        cout << "\nDo you want to add another number? [Y/N] ";
        cin >> input;
    } while (input == 'y' || input == 'Y');
    
}

void DeleteVector(vector <int> &vNumbers)
{
    char input;
    do
    {
        if (vNumbers.empty()) //vNumbers.size() == 0
        {
            cout << "\nThe vector is empty.\n";
            return;
        }
        cout << "\nOne element has been deleted.\n";
        vNumbers.pop_back();

        cout << "\nDo you want to delete another number? [Y/N] ";
        cin >> input;
    } while (input == 'y' || input == 'Y');
    
}

void PrintVector(vector <int> &vNumbers)
{
    cout << "\nNumbers Vector = ";

    for (int &Number: vNumbers)
    {
        cout << Number << " ";
    }

    cout << endl;
}



int main()
{
    vector <int> vNumbers;

    ReadVector(vNumbers);
    DeleteVector(vNumbers);
    PrintVector(vNumbers);
    
    // vNumbers.clear()    ---> removes all elements in vector
    return 0;
}