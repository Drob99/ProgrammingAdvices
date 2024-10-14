# include <iostream>
using namespace std;

class clsCalculator
{
private:
    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation = "Clear";
    float _PreviousResult = 0;

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }


public:
    void Add(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result += Number;
        _LastOperation = "Adding";
    }

    void Subtract(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result -= Number;
        _LastOperation = "Subtracting";
    }

    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _Result *= Number;
        _LastOperation = "Multiplying";
    }

    void Divide(float Number)
    {
        _PreviousResult = _Result;
        _LastNumber = Number;
        if (_IsZero(Number))
            Number = 1;

        _Result /= Number;
        _LastOperation = "Dividing";
    }

    void Clear()
    {
        _LastNumber = 0;
        _PreviousResult = 0;
        _Result = 0;
        _LastOperation = "Clear";
    }

    float GetFinalResult()
    {
        return _Result;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "Cancelling Last Operation (" + _LastOperation + ")";
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        cout << "\nResult After " << _LastOperation << " "  <<  _LastNumber << " is: " << GetFinalResult();
    }
};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Subtract(20);
    Calculator1.PrintResult();

    Calculator1.Divide(0);
    Calculator1.PrintResult();

    Calculator1.Divide(2);
    Calculator1.PrintResult();

    Calculator1.Multiply(2);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();


    Calculator1.Clear();
    Calculator1.PrintResult();

    return 0;
}