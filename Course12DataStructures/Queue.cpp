#include <iostream>
#include <queue>

using namespace std;

template <typename T> void PrintQueue (queue <T> &myQueue, string message = "")
{
    cout << message;
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
}

int main()
{
    queue <int> MyQueue;

    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);
    MyQueue.push(50);

    cout << "\nCount : " << MyQueue.size();
    cout << "\nFront : " << MyQueue.front();
    cout << "\nBack  : " << MyQueue.back() << endl;

    PrintQueue(MyQueue, "\nMy Queue: ");

    queue<int> MyQueue2;

    // pushing elements into first queue
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);

    // pushing elements into 2nd queue
    MyQueue2.push(50);
    MyQueue2.push(60);
    MyQueue2.push(70);

    // using swap() function to swap elements of queues
    MyQueue.swap(MyQueue2);

    PrintQueue(MyQueue,  "\nMyQueue : ");
    PrintQueue(MyQueue2, "\nMyQueue2: ");

}