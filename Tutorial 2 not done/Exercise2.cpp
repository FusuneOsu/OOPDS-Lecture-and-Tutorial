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
    cout << sizeof(x) << "," << sizeof(y)<< "," << sizeof(z)<< "," << 
    sizeof(pInt)<< "," << sizeof(pFloat)<< "," << sizeof(pDouble)<< "," << endl;
    
    // (2) Store the address of y in the pointer variable pInt. Then compile the program. The compile will
    // generate a compilation error. Explain why such statement is not allowed.
    //Integer pointer cannot store y which is type float
    
    // (3) Store the address of y into the pointer variable pDouble. Compile the program and explain what
    // happens.
    //cannot convert 'float*' to 'double*' in assignment
    
    // (4) Explain why the following C++ statement will not compile?
    //pInt = static_cast<int*>(&y);
    //static_cast can only cast between two related types. An integer is not related to 
    //a pointer and vice versa, so you need to use reinterpret_cast instead, which tells 
    //the compiler to reinterpret the bits of the integer as if they were a pointer (and vice versa):
    
    // (5) Explain whay the output of the following cout line will not print the value 3.14.
    // pInt = reinterpret_cast<int*>(&y);
    // cout << *pInt << endl;
    //y contains a bit pattern that is a float

    return 0;
}