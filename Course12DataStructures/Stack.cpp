#include <iostream>
#include <stack>

using namespace std;

template <typename T> void PrintStack (stack <T> &stk, string message = "")
{
    cout << message;
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{
    // create a stack of ints
    stack <int> stkNumbers;

    // push into stack
    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);


    // access elements by popping until stack is empty
    cout << "count = " << stkNumbers.size() << endl;

    PrintStack(stkNumbers, "Numbers are:\n");

    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);


    stack <int> stkNumbers2;

    stkNumbers2.push(60);
    stkNumbers2.push(70);
    stkNumbers2.push(80);
    stkNumbers2.push(90);

    stkNumbers.swap(stkNumbers2);

    PrintStack(stkNumbers, "\nStack 1:\n");

    PrintStack(stkNumbers2, "\nStack2: \n");
    return 0;
}