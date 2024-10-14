// Reusability
#pragma once
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>
class clsMyQueueArr
{
protected:
    clsDynamicArray <T> _MyList;

public:

    void push(T item) 
    {
        _MyList.InsertAtEnd(item);
    }

    void Print()
    {
        _MyList.PrintList();
    }

    T front()
    {
        return _MyList.GetItem(0);
    }

    int Size()
    {
        return _MyList.Size();
    }

    T back()
    {
        return _MyList.GetItem(Size() - 1);
    }

    void pop()
    {
        _MyList.DeleteFirstItem();
    }

    bool IsEmpty()
    {
        return _MyList.IsEmpty();
    }

    T GetItem (int index)
    {
        return _MyList.GetItem(index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    bool UpdateItem(int index, T value)
    {
        return _MyList.SetItem(index, value);
    }

    bool InsertAfter(int index, T value)
    {
        return _MyList.InsertAfter(index, value);
    }

    void InsertAtFront(T value)
    {
        _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void Clear()
    {
        _MyList.Clear();
    }

};