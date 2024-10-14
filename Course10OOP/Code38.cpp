#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsStudentsInfo
{
private:

	class clsStudent
	{
	private:
		string _FullName;
		float _Grade;

		void Print(short Iterator)
		{
			cout << "\n===========================\n";
			cout << "\tStudent Card";
			cout << "\n===========================\n";

			cout << "\nStudent " << Iterator + 1 << endl;
			cout << "Full Name : " << _FullName << endl;
			cout << "Grade : " << _Grade << endl;
			cout << "___________________________\n";
		}


	public:

		clsStudent(string FullName, float Grade)
		{
			_FullName = FullName;
			_Grade = Grade;
		}

		friend class clsStudentsInfo;
	};

	vector <clsStudent> Vstudents;

	clsStudent _Student = clsStudent (" ", 0);

	void PrintStudentCard()
	{
		for (short i = 0; i < _NumberOfStudents; i++)
		{
			Vstudents[i].Print(i);
			cout << endl;
		}

		cout << endl;
	}

	int ReadNumber()
	{
		short NumberOfStudents = 0;

		cout << "\nHow Many Students do you want to Add ? ";
		cin >> NumberOfStudents;

		return NumberOfStudents;
	}
	short _NumberOfStudents;


public:

	clsStudentsInfo(string FullName, float Grade)
	{
		_Student = clsStudent(FullName, Grade);
	}

	void StudentsInfo()
	{
		_NumberOfStudents = ReadNumber();

		string FullName = " ";
		float Grade = 0;

		for (short i = 0; i < _NumberOfStudents; i++)
		{
			cout << "\n\nEnter Student " << i + 1 << " Info : \n";

			cout << "Enter Full Name : ";
			getline(cin >> ws, FullName);

			cout << "Enter Grade : ";;
			cin >> Grade;

			clsStudent Student(FullName, Grade);
			Vstudents.push_back(Student);
		}

		PrintStudentCard();
	}
};

int main()
{
	clsStudentsInfo Student1("Omar Abdalla", 70);

	Student1.StudentsInfo();

	
	system("pause>0");
}