#pragma once
#include <iostream>
#include "clsMyStack.h"

using namespace std;

class clsMyString
{
private:
    clsMyStack <string> _Undo;
    clsMyStack <string> _Redo;
    string _value;

public:

    clsMyString()
    {
        _Undo.push("");
        _value = "";
    }

    void SetValue(string value)
    {
        _Undo.push(value);
        _value = value;
        if (!_Redo.IsEmpty())
        {
            _Redo.Clear();
        }
    }

    string GetValue()
    {
        return _value;
    }

    void Undo()
    {
        if (!_Undo.IsEmpty())
        {
            _Redo.push(_value);
            _Undo.pop();
            _value = _Undo.top();
        }
    }

    void Redo()
    {
        if (!_Redo.IsEmpty())
        {
            _Undo.push(_value);
            _value = _Redo.top();
            _Redo.pop();
        }
    }


};