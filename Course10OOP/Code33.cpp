# include <iostream>
using namespace std;

class clsPerson {
  
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    string FullName;
    stAddress Address; // It could be private, but in this case it's public

    clsPerson()
    {
        FullName = "Omar Bahaeldin Abdalla";
        Address.AddressLine1 = "Building 834";
        Address.AddressLine2 = "KFUPM";
        Address.City = "Al-Khobar";
        Address.Country = "Saudi Arabia";
    }
    
    void PrintAddress()
    {
        cout << "\nAddress:\n";
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }

};

int main() 

{

    clsPerson Person1;
    Person1.PrintAddress();

    return 0;
}