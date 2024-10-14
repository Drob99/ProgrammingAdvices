#pragma once
#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
protected:

    int _size = 0;

public:

    T* array;

    clsDynamicArray (int size = 0)
    {
        if (size < 0)
            size = 0;

        _size = size;
        array = new T[_size];
    }

    ~clsDynamicArray()
    {
        delete[] array;
    }

    bool SetItem(int index, T value)
    {
        if (index < 0 || index >= _size)
            return false;
        
        array[index] = value;
        return true;
    }

    bool IsEmpty()
    {
        return _size == 0;
    }

    int Size()
    {
        return _size;
    }

    void PrintList()
    {
        for (int i = 0; i < _size; i++)
        {
            cout << array[i] << " ";
        }
        cout << "\n";
    }

    void Resize(int new_size)
    {
        if (new_size < 0)
            new_size = 0;
        
        T* NewArray = new T[new_size];

        if (new_size < _size)
            _size = new_size;
        

        for (int i = 0; i < _size; i++)
        {
            NewArray[i] = array[i];
        }

        _size = new_size;
        delete[] array;
        array = NewArray;
    
    }

    T GetItem (int index)
    {
        return array[index];
    }

    void Reverse()
    {
        T* NewArray = new T[_size];

        for (int i = 0; i < _size; i++)
        {
            NewArray[i] = array[_size-i-1];
        }

        delete[] array;
        array = NewArray;
    }

    void Clear()
    {
        delete[] array;
        array = new T[0];
        _size = 0;
    }

    bool DeleteItemAt(int index)
    {
        if (index < 0 || index > _size-1)
            return false;


        for (int i = index; i < _size; i++)
        {
            array[i] = array[i+1];
        }

        _size--;
        Resize(_size);
        return true;
    }

    // bool DeleteItemAt(int index)
    // {
    //     if (index >= _Size || index <0)
    //     {
    //         return false;
    //     }
    //     _Size--;
    //     _TempArray = new T[_Size];
    //     //copy all before index
    //     for (int i = 0; i < index; i++)
    //     {
    //         _TempArray[i] = OriginalArray[i];
    //     }
    //     //copy all after index
    //     for (int i = index + 1; i < _Size + 1; i++)
    //     {
    //         _TempArray[i - 1] = OriginalArray[i];
    //     }
    //     delete[] OriginalArray;
    //     OriginalArray = _TempArray;
    //     return true;
    // }

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);
    }

    bool DeleteLastItem()
    {
        return DeleteItemAt(_size-1);
    }

    int Find (T value)
    {
        for (int i = 0; i < _size; i++)
        {
            if (array[i] == value) return i;
        }
        return -1;
    }

    bool DeleteItem (T value)
    {
        return DeleteItemAt(Find(value));
    }

    bool InsertAt (int index, T value)
    {
        if (index < 0 || index > _size)
        {
            return false;
        }

        _size++;
        T* new_array = new T[_size];

        bool added = false;
        for (int i = 0; i < _size; i++)
        {
            if (i == index)
            {
                added = true;
                new_array[i] = value;
                continue;
            }
            if (!added)
            {
                new_array[i] = array[i];
            }
            else
                new_array[i] = array[i-1];
        }

        delete[] array;
        array = new_array;
        return true;
    }

    // bool InsertAt(T index, T value) {

    //     if (index > _Size || index < 0)
    //     {
    //         return false;
    //     }

    //     _Size++;

    //     _TempArray = new T[_Size];

    //     //copy all before index
    //     for (int i = 0; i < index; i++)
    //     {
    //         _TempArray[i] = OriginalArray[i];
    //     }

    //     _TempArray[index] = value;

    //     //copy all after index
    //     for (int i = index; i < _Size - 1; i++)
    //     {
    //         _TempArray[i + 1] = OriginalArray[i];
    //     }

    //     delete[] OriginalArray;
    //     OriginalArray = _TempArray;
    //     return true;

    // }

    bool InsertAtBeginning(T value)
    {
        return InsertAt(0, value);
    }

    bool InsertBefore(int index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        
        return InsertAt(index-1, value);
    }

    bool InsertAfter(int index, T value)
    {
        if (index >= _size)
            return InsertAfter(_size - 1, value);
        return InsertAt(index+1, value);
    }

    bool InsertAtEnd (T value)
    {         
        return InsertAt(_size, value);
    }

    
};