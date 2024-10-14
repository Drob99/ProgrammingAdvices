#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node * next;
    Node * prev;
};

void InsertAtBeginning(Node * & head, int value)
{
    /*
    1- Create new node with desired value.
    2- Set next pointer of new node to current head of the list.
    3- Set the previous pointer of current head to new node.
    4- Set new node as new head.
    */
    // Allocate new node to memory
    Node *new_node = new Node();

    // insert data
    new_node->value = value;
    new_node->next = head;
    new_node->prev = NULL;

    if (head != NULL)
        head->prev = new_node;
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
    /*
        1- Create new node with desired value.
        2- Set Next pointer of new node to next node
        3- Set prev pointer of new node to prev node
        4- Set the next pointer of prev node to new node.
        5- Set prev pointer of next node to new node (if exists) 
    */
    if (prev_node == NULL)
    {
        cout << "\nThe given previous node cannot be NULL.\n";
        return;
    }

    Node * new_node = new Node();
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    new_node->value = value;

    if (prev_node->next != NULL)
        prev_node->next->prev = new_node;

    prev_node->next = new_node;

}

void InsertAtEnd (Node * &head, int value)
{
    /*
        1- Create a new node with desired value.
        2- Traverse the list to find the last node.
        3- Set next pointer of last node to new node.
        4- Set prev pointer of new node to last node.
    */
    Node * new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
        return;
    }

    Node * LastNode = head;
    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }

    LastNode->next = new_node;
    new_node->prev = LastNode;
    return;
}

void DeleteNode (Node * &head, int value)
{
    Node * current_node = head, * prev_node = NULL;

    //empty LL
    if (head == NULL)
        return;

    // at beg
    if (head->value == value)
    {
        Node *next_node = head->next;
        delete current_node;
        head = next_node;

        if (head != NULL)
        {
            head->prev = NULL;
        }
        return;
    }

    while (current_node != NULL && current_node->value != value)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) return;

    
    prev_node->next = current_node->next;

    if (current_node->next != NULL)
        current_node->next->prev = prev_node;
    
    delete current_node;
}

void DeleteNode (Node * &head, Node *&NodeToDelete)
{
    /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
    */

    if (head == NULL || NodeToDelete == NULL) return;

    if (head == NodeToDelete)
        head = NodeToDelete->next;
    
    if (NodeToDelete->next != NULL)
    {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }

    if (NodeToDelete->prev != NULL)
    {
        NodeToDelete->prev->next = NodeToDelete->next;
    }

    delete NodeToDelete;
}

void DeleteFirstNode (Node *&head)
{
    /*
        1-Store a reference to the head node in a temporary variable.
        2-Update the head pointer to point to the next node in the list.
        3-Set the previous pointer of the new head to NULL.
        4-Delete the temporary reference to the old head node.
    */

    Node *FirstNode = head;

    if (head == NULL)
        return;
    
    head = FirstNode->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete FirstNode;
    return;
}

void DeleteLastNode (Node *&head)
{
    /*
        1- Traverse the list to find the last node.
        2- Set the next pointer of the second-to-last node to NULL.
        3- Delete the last node.
    */

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *current_node = head;

    // find the node before last node
    while (current_node->next->next != NULL)
    {
        current_node = current_node->next;
    }

    Node *temp = current_node->next;
    current_node->next = NULL;
    delete temp;
    return;
}

void PrintNodeDetails (Node *head)
{
    if (head->prev != NULL)
    {
        cout << head->prev->value;
    }
    else 
        cout << "NULL";
    
    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";
}

void PrintListDetails(Node* head)
{
    cout << "\n\n";
    while (head != NULL) {
        PrintNodeDetails(head);
        head = head->next;
    }
}

void PrintList (Node* head)
{
    cout << "\nNULL <--> ";
    while (head != NULL)
    {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    Node * head = NULL;

    cout << "\n\nDoubly Linked List after inserting nodes 5, 4, 3, 2, & 1:";
    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);
    PrintListDetails(head);

    cout << "\n\nFinding Node 2:";
    Node * N1 = Find(head, 2);

    if (N1 != NULL)
        cout << "\nNode Found :-)\n";
    else
        cout << "\nNode is NOT found\n";

    cout << "\n\nDoubly Linked List after inserting node 500:";
    InsertAfter(N1, 500);
    PrintListDetails(head);

    cout << "\n\nDoubly Linked List after inserting nodes 7, 8, 9, & 0:"; 
    InsertAtEnd(head, 7);
    InsertAtEnd(head, 8);
    InsertAtEnd(head, 9);
    InsertAtBeginning(head, 0);
    PrintListDetails(head);

    cout << "\n\nDoubly Linked List after deleting node with value 4:";
    DeleteNode(head, 4);
    
    PrintList(head);
    PrintListDetails(head);

    cout << "\n\nDoubly Linked List after deleting first 3 nodes:";
    DeleteFirstNode(head);
    DeleteFirstNode(head);
    DeleteFirstNode(head);
    PrintList(head);
    PrintListDetails(head);

    cout << "\n\nDoubly Linked List after deleting last 3 nodes:";
    DeleteLastNode(head);
    DeleteLastNode(head);
    DeleteLastNode(head);
    PrintList(head);
    PrintListDetails(head);

    return 0;
}