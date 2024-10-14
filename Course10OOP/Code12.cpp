// Constructors
#include <iostream>

using namespace std;

class clsAddress 
{
private:
    string _AddressLine1;
    string _AddressLine2;
    string _POBox;
    string _ZipCode;

public:
    // Constructor
    clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }


    void SetAddressLine1(string AddressLine1)
    {
        _AddressLine1 = AddressLine1;
    }

    string GetAddressLine1()
    {
        return _AddressLine1;
    }

    void SetAddressLine2(string AddressLine2)
    {
        _AddressLine2 = AddressLine2;
    }

    string GetAddressLine2()
    {
        return _AddressLine2;
    }

    void SetPOBox(string POBox)
    {
        _POBox = POBox;
    }

    string GetPOBox()
    {
        return _POBox;
    }

    void SetZipCode(string ZipCode)
    {
        _ZipCode = ZipCode;
    }

    string GetZipCode()
    {
        return _ZipCode;
    }

    void Print()
    {
        cout << "\nAddress Details:\n";
        cout << "-------------------------------";
        cout << "\nAddressLine1: " << _AddressLine1;
        cout << "\nAddressLine2: " << _AddressLine2;
        cout << "\nPOBox       : " << _POBox;
        cout << "\nZipCode     : " << _ZipCode;
    }
};

int main()
{
    clsAddress Address1("Al Jamal Street", "Building 17", "13127", "5555");

    Address1.Print();
    return 0;
}