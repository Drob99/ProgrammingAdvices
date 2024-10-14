// String Objects (Common Methods)

# include <iostream>
# include <string>

using namespace std;

int main()
{

    string S1 = "My name is Omar Bahaeldin Abdalla. I love Programming.";

    cout << S1.length() << endl;

    cout << S1.at(3) << endl;

    S1.append("@ProgrammingAdvices");
    cout << S1 << endl;

    S1.insert(25, " Ahmed");
    cout << S1 << endl;

    cout << S1.substr(11, 28) << endl;

    S1.push_back('X');
    cout << S1 << endl;

    S1.pop_back();
    cout << S1 << endl;

    cout << S1.find("Ahmed") << endl;

    cout << S1.find("ahmed") << endl;

    if (S1.find("ahmed") == S1.npos)
        cout << "ahmed is not found" << endl;

    S1.clear();
    cout << S1 << endl;


    return 0;
}