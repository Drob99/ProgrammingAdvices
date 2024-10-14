# include <iostream>
using namespace std;

// enclosing class
class clsPerson { 
    string _FullName;

    class clsAddress // inner class
    {

    private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:

        clsAddress (string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }

        void setAddressLine1 (string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }

        string AddressLine1()
        {
            return _AddressLine1;
        }

        void setAddressLine2 (string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }

        string AddressLine2()
        {
            return _AddressLine2;
        }

        void setCity (string City)
        {
            _City = City;
        }

        string City()
        {
            return _City;
        }

        void setCountry (string Country)
        {
            _Country = Country;
        }

        string Country()
        {
            return _Country;
        }

        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:
    void setFullName (string FullName)
    {
        _FullName = FullName;
    }

    string FullName()
    {
        return _FullName;
    }

    // Note, there is no empty constructor for the inner class clsAddress.
    clsAddress Address = clsAddress("", "", "", ""); // Or     clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country) : Address(AddressLine1, AddressLine2, City, Country)

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
    

};

int main() 

{

    clsPerson Person1 ("Omar Bahaeldin Abdalla", "Building 834", "KFUPM", "Riyadh", "Saudi Arabia");
    Person1.Address.Print();
    return 0;
}