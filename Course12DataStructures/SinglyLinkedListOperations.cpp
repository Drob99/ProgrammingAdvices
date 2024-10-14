#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node * next;
};

void InsertAtBeginning(Node * & head, int value)
{
    // Allocate new node to memory
    Node *new_node = new Node();

    // insert data
    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

Node * Find(Node * head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void InsertAfter(Node *&prev_node, int value)
{
    if (prev_node == NULL)
    {
        cout << "\nThe given previous node cannot be NULL.\n";
        return;
    }

    Node * new_node = new Node();
    new_node->next = prev_node->next;
    new_node->value = value;

    prev_node->next = new_node;

}

void InsertAtEnd (Node * &head, int value)
{
    Node * new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node * LastNode = head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }
    LastNode->next = new_node;
    return;
}

void DeleteNode (Node * &head, int value)
{
    Node * current_node = head, * prev_node = head;

    //empty LL
    if (head == NULL)
        return;

    // at beg
    if (head->value == value)
    {
        head = head->next;
        delete current_node;
        return;
    }

    while (current_node != NULL && current_node->value != value)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) return;

    prev_node->next = current_node->next;
    delete current_node;
}

void DeleteFirstNode (Node *&head)
{
    Node *FirstNode = head;

    if (FirstNode == NULL)
        return;
    
    head = FirstNode->next;
    delete FirstNode;
    return;
}

void DeleteLastNode (Node *&head)
{
    Node * current_node = head, * prev_node = head;
    if (head == NULL)
    {
        return;
    }

    if (current_node->next == NULL)
    {
        head = NULL;
        delete current_node;
        return;
    }

    while (current_node != NULL && current_node->next != NULL)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    prev_node->next = NULL;
    delete current_node;
    return;
}

// Since I am not passing by ref, the original 
// head is still the same.
void PrintList (Node* Head)
{
    cout << endl;
    while (Head != NULL)
    {
        cout << Head->value << " ";
        Head = Head->next;
    }
}


int main()
{
    Node * head = NULL;

    cout << "\n\nLinked List after inserting nodes 1, 2, 3, 4, & 5:";
    InsertAtBeginning(head, 1);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 5);
    PrintList(head);

    cout << "\n\nFinding Node 2:";
    Node * N1 = Find(head, 2);

    if (N1 != NULL)
        cout << "\nNode Found :-)\n";
    else
        cout << "\nNode is NOT found\n";

    cout << "\n\nLinked List after inserting node 500:";
    InsertAfter(N1, 500);
    PrintList(head);

    cout << "\n\nLinked List after inserting nodes 7, 8, 9, & 0:"; 
    InsertAtEnd(head, 7);
    InsertAtEnd(head, 8);
    InsertAtEnd(head, 9);
    InsertAtBeginning(head, 0);
    PrintList(head);

    cout << "\n\nLinked List after deleting node with value 4:";
    DeleteNode(head, 4);
    PrintList(head);

    cout << "\n\nLinked List after deleting first 3 nodes:";
    DeleteFirstNode(head);
    DeleteFirstNode(head);
    DeleteFirstNode(head);
    PrintList(head);

    cout << "\n\nLinked List after deleting last 3 nodes:";
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);
    PrintList(head);

    return 0;
}