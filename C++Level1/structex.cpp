#include <iostream>
using namespace std;

enum enColor { Red, Green, Yellow, Blue};
enum enGender {Male, Female};
enum enMaritalStatus {Single, Married};

struct stAddress
{
    string StreetName;
    string BuildingNo;
    string POBox;
    string ZipCode;
};

struct stContactInfo
{
    string Phone;
    string Email;
    stAddress Address;
};

struct stPerson
{
    string FirstName;
    string LastName;

    stContactInfo ConatactInfo;

    enMaritalStatus MaritalStatus;
    enGender Gender;
    enColor FavoriteColor;
};

int main()
{
    stPerson Person1;

    Person1.FirstName = "Omar";
    Person1.LastName = "Abdalla";

    Person1.ConatactInfo.Email = "s202259760@kfupm.edu.sa";
    Person1.ConatactInfo.Phone = "+966570281148";
    Person1.ConatactInfo.Address.POBox = "7777";
    Person1.ConatactInfo.Address.StreetName = "King Fahd Road";
    Person1.ConatactInfo.Address.BuildingNo = "816";
    Person1.ConatactInfo.Address.ZipCode = "31952";

    Person1.Gender = enGender::Male;
    Person1.MaritalStatus = enMaritalStatus::Single;
    Person1.FavoriteColor = enColor::Red;

    return 0;
}

