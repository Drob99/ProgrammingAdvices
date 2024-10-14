#pragma once
#include <iostream>

using namespace std;

template <class T> 
class clsDblLinkedList
{
public:
    class Node
    {
    public: 
        T value;
        Node *next;
        Node *prev;
    };

protected:
    Node *head = NULL;
    int _size = 0;

public:
    void InsertAtBeginning (T value)
    {
        Node *new_node = new Node();

        new_node->value = value;
        new_node->prev = NULL;
        new_node->next = this->head;

        if (this->head != NULL)
        {
            head->prev = new_node;
        }

        this->head = new_node;
        _size++;
    }

    void PrintNodeDetails (Node *tmp)
    {

        if (tmp->prev != NULL)
        {
            cout << tmp->prev->value;
        }
        else 
            cout << "NULL";
        
        cout << " <--> " << tmp->value << " <--> ";

        if (tmp->next != NULL)
            cout << tmp->next->value << "\n";
        else
            cout << "NULL";
    }

    void PrintListDetails()
    {
        cout << "\n\n";
        Node *tmp = head;
        while (tmp != NULL) {
            PrintNodeDetails(tmp);
            tmp = tmp->next;
        }
    }

    void PrintList ()
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
    
    Node *Find (T value)
    {
        Node *tmp = head;
        while (tmp != NULL)
        {
            if (tmp->value == value)
                return tmp;

            tmp = tmp->next;
        }
        return NULL;
    }

    void InsertAfter(Node *&prev_node, T value)
    {
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
        _size++;
    }

    void InsertAtEnd (T value)
    {
        Node * new_node = new Node();
        new_node->value = value;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            new_node->prev = NULL;
            _size++;
            return;
        }

        Node * LastNode = head;
        while (LastNode->next != NULL)
        {
            LastNode = LastNode->next;
        }

        LastNode->next = new_node;
        new_node->prev = LastNode;
        _size++;
        return;
    }

    void DeleteNode (T value)
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
            _size--;
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

    void DeleteNode (Node *&NodeToDelete)
    {
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

        _size--;

        delete NodeToDelete;
    }

    void DeleteFirstNode ()
    {
        Node *FirstNode = head;

        if (head == NULL)
            return;
        
        head = FirstNode->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete FirstNode;
        _size--;
        return;
    }

    void DeleteLastNode ()
    {

        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            _size = 0;
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
        _size--;
        return;
    }

    int Size()
    {
        return _size;
    }

    bool IsEmpty()
    {
        return _size == 0;
    }

    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }

    // void Reverse()
    // {
    //     if (IsEmpty() || _size == 1)
    //         return;
    //     Node *tmp = head;
    //     Node *tmp2 = head->next;
    //     while (tmp != NULL && tmp2 != NULL)
    //     {
    //         tmp->next = tmp->prev;
    //         tmp->prev = tmp2;
    //         tmp = tmp2;
    //         tmp2 = tmp2->next;
    //     }
    //     tmp->next = tmp->prev;
    //     tmp->prev = tmp2;
    //     head = tmp;
    // }

    void Reverse()
    {
        Node *current = head;
        Node *tmp = nullptr;

        if (_size == 1) return;

        while (current != nullptr)
        {
            tmp = current->prev;
            current->prev = current->next;
            current->next = tmp;
            current = current->prev;
        }

        if (tmp != nullptr)
        {
            head = tmp->prev;
        }
    }

    Node * GetNode(int index)
    {
        if (index > _size - 1 || index < 0)
            return NULL;

        Node * temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
            if (temp == NULL ) return NULL;
        }

        return temp;
    }

    // Node* GetNode(int Index)
    // {
    //     int Counter = 0;
    //     if (Index > _Size - 1 || Index < 0)
    //         return NULL;
    //     Node* Current = head;
    //     while (Current != NULL && (Current->next != NULL)) {
    //         if (Counter == Index)
    //             break;
    //         Current = Current->next;
    //         Counter++;
    //     }
    //     return Current;
    // }

    T GetItem (int index)
    {
        Node * ItemNode = GetNode(index);
        return (ItemNode == NULL ? NULL : ItemNode->value);
    }

    bool UpdateItem (int index, T NewValue)
    {
        Node * ItemNode = GetNode(index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        return false;
    }

    bool InsertAfter(int index, T value)
    {
        Node * prev_node = GetNode(index);
        if (prev_node != NULL)
        {
            InsertAfter(prev_node, value);
            return true;
        }

        return false;
    }


};