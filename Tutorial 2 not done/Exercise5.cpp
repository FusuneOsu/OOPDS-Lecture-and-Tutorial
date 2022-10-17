#include <iostream>
using namespace std;

int fun(int &x)
{
    cout << "&" << endl;
    return x + 1;
}
int fun(const int &x)
{
    cout << "const&" << endl;
    return x + 3;
}
int fun(int &&x)
{
    cout << "&&" << endl;
    return x + 2;
}

int main()
{
    int m = 10;
    int &a = m;
    a = 20;
    cout << a << ":" << m << endl;
    // insert your code below the line

    // (1) Compile and run the program above. Discuss the statement (int &a=m;).
    
    // (2) Add the line (int &b = 10;) to the program and compile your program. Explain the
    // compilation error.
    
    // (3) Add the line (int &&c = 5;) to the program and compile your program. Explain the symbol
    // &&. Increment c then print out the value of c.
    
    // (4) If you add the following lines of code to the program,
    // int x = 4;
    // const int y = 10;
    // cout << fun(1) << endl;
    // cout << fun(x) << endl;
    // cout << fun(y) << endl;
    // Which functions will be called in the last 3 cout statements?

    return 0;
}