#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char arr[] = "This is a null terminated string";
    cout << arr << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(char) << endl;
    cout << strlen(arr) << endl;

    // (1) Explain the difference between sizeof() and strlen() in the above program.

    // (2) Explain the relationship between strlen() and the formula sizeof(arr)/sizeof(char).

    // (3) Add the following 2 lines of code to the program then compile and run the program.
    // arr[2] = 'X';
    // cout << arr << endl;

    // (4) Replace the line then compile and run the program.
    //      char arr[]="This is a null terminated string";
    // with the line
    //      char *arr="This is a null terminated string";
    // Any changes in the output? Explain your answer.

    // (5) Define a C++ string variable str and assign arr to it. (you need to include <string>).

    // (6) Display the length of str.

    // (7) Declare a char array arr2 of 80 characters.

    // (8) Add the following line behind your declaration in the previous step. Explain what happens.
    // arr2 = str;

    // (9) Replace the lines in 7 and 8 with the following line.
    // const char *arr2 = str.c_str();

    return 0;
}