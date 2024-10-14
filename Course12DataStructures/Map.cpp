#include <iostream>
#include <map>

using namespace std;

void FindGrade (string studentName, map <string, int> &studentGrades)
{
    cout << "\nFinding " << studentName << "'s Grade in the Map..\n";  
    if (studentGrades.find(studentName) != studentGrades.end())
    {
        cout << studentName << "'s Grade: " << studentGrades[studentName] << endl;
    } 
    else
        cout << "Grade not found for " << studentName << endl;
 
}

int main()
{
    map <string, int> studentGrades; // string keys & int values

    studentGrades["Ali"] = 77;
    studentGrades["Fadi"] = 85;
    studentGrades["Ahmed"] = 95;

    cout << "\nPrinting all map values..\n\n";

    for (const auto & pair: studentGrades)
    {
        cout << "Student: " << pair.first << ", Grade: " << pair.second << endl;
    }

    FindGrade("Fadi", studentGrades);
    FindGrade("Omar", studentGrades);

    return 0;
}