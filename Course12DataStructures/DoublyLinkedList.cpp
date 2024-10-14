#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node * next;
    Node * prev;
};


int main()
{
    Node * head;

    // New() only works for pointers bcz it's heap
    Node *Node1 = NULL;
    Node *Node2 = NULL;
    Node *Node3 = NULL;

    // allocate 3 nodes in heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    // Assign values
    Node1->value = 1;
    Node2->value = 2;
    Node3->value = 3;

    // Connect Nodes
    Node1->next = Node2;
    Node1->prev = NULL;

    Node2->next = Node3;
    Node2->prev = Node1;

    Node3->next = NULL;
    Node3->prev = Node2;

    head = Node1;
    cout << "Linked List: ";
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}