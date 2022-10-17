#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    float y = 3.14f;
    double z = 3.14;
    int *pInt;
    float *pFloat;
    double *pDouble;
    // place your code below this line

    // (1) The sizeof() operator returns the number of bytes used to represent a variable. Use the operator to
    // display the size of all the variable declared in the program above (x, y, z, pInt, pFloat, and pDouble).
    
    // (2) Store the address of y in the pointer variable pInt. Then compile the program. The compile will
    // generate a compilation error. Explain why such statement is not allowed.
    
    // (3) Store the address of y into the pointer variable pDouble. Compile the program and explain what
    // happens.
    
    // (4) Explain why the following C++ statement will not compile?
    // pInt = static_cast<int*>(&y);
    
    // (5) Explain whay the output of the following cout line will not print the value 3.14.
    // pInt = reinterpret_cast<int*>(&y);
    // cout << *pInt << endl;

    return 0;
}