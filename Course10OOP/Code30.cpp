# include <iostream>
using namespace std;

// Abstract Class
class clsMobile
{
    virtual void Dial (string PhoneNumber) = 0; //equal zero makes it pure virtual

    virtual void SendSMS (string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;
};

class clsiPhone : public clsMobile
{
public:
    void Dial (string PhoneNumber)
    {

    };

    void SendSMS (string PhoneNumber, string Text)
    {

    };

    void TakePicture() 
    {

    };   
};

class clsSamsungNote10 : public clsMobile
{
public:
    void Dial (string PhoneNumber)
    {

    };

    void SendSMS (string PhoneNumber, string Text)
    {

    };

    void TakePicture() 
    {

    }; 
};

int main()
{
    // clsMobile M1; //! ERROR

    clsiPhone iPhone1;

}