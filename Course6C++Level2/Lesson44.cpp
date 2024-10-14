// Dynamic Arrays
# include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter total number of students: ";
    cin >> num;
    
    float* ptr = new float[num];

    cout << "Enter grades of students." << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Student" << i + 1 << ":  ";

        cin >> *(ptr + i);
    }

    cout << "\nDisplaying grades of students." << endl;
    for (int i = 0; i < num; i++)
    {
        cout << "Student " << i+1 << ":  " << *(ptr + i) << endl;
    }

    delete[] ptr;


    return 0;
}