// String and char format

# include <iostream>
# include <cstdio>

using namespace std;

int main()
{
    char Name[] = "Omar Bahaeldin Abdalla"; // string = char[]
    char SchoolName[] = "KFUPM";

    // print string and String
    printf("Dear %s, How are you?\n\n", Name);
    printf("Welcome to %s School!\n\n", SchoolName);

    char c = 'S';

    printf("Setting the width of c :%*c \n", 1, c);
    printf("Setting the width of c :%*c \n", 2, c);
    printf("Setting the width of c :%*c \n", 3, c);
    printf("Setting the width of c :%*c \n", 4, c);
    printf("Setting the width of c :%*c \n", 5, c);

    return 0;
}