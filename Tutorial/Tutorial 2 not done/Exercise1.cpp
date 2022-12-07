#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    int arr[5] = {1, 2, 3, 4, 5};
    // start inserting your c++ code after this line

    // (1) Declare a pointer variable named ptr that points to an integer datatype.
    int* ptr;

    // (2) Assign the address of the variable x to the pointer variable ptr.
    ptr = &x;

    // (3) Print the value of x using the pointer variable ptr.
    cout << *ptr << endl;

    // (4) Store the address of the second element of the array arr in the pointer variable ptr.
    ptr = &arr[1];

    // (5) Store the the location pointed at by ptr the value 99. -> what

    // (6) write a for loop to print the values stored in the array arr separated by comma on a single line.
    for (int i=0; i<sizeof(arr)/sizeof(int); i++)
    {
        cout << arr[i] << ",";
    } cout << endl;

    // (7) Make ptr points to the beginning of the array arr.
    ptr = &arr[0];

    // (8) write a for loop to print the values stored in the array arr (using ptr not arr) separated by comma on
    // a single line.
    for (int i=0; i<sizeof(arr)/sizeof(int); i++)
    {
        cout << *ptr << ",";
        (ptr++);
    } cout << endl;
 
    // (9) Explain the difference between ptr++, (ptr++), and (*ptr)++ using a copy of what you have done in
    // 7 and 8 earlier.
    // -> The difference is how you write them
    
    // (10) Can we use the name of the array as a pointer? If it is possible, show that using similar code to the
    // one in step 9.
    // array is constant pointer so no

    return 0;
}