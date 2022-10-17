#include <iostream>
#include <climits>
using namespace std;

int main(){

    int sum {0};  // int sum = 0;
    std::cout << sizeof(int) << ":" << INT_MAX << ":" << INT_MIN << std::endl;
    // int ---> -32768 - +32767

    char grade {'A'};  // char grade = 'A';

    char d = 65;     // char d = 'A';
    d = d - 66;
    cout << d << endl;

    // demo of underflow
    unsigned int i = 10;          // i is a primitive variable not an object
    for (int k=0; k<20; k++)
        cout << i-- << endl;

    bool flag {true};

    // string is a class therefore each variable is called object
    string name {"sharaf"};     // string : class , name : object
    string fname("Sharaf");
    string lname = "Horani";

    //Arrays
    int g0=90,g1=80,g2=78,g3=100;
    
    int g[4]={90,80,78,100};
    g[0], g[1], g[2], g[3];

    for (int j=0; j<4; j++)
        cout << "g[" << j << "] = " << g[j] << endl;
    
    cout << sizeof(g) << ":"<<sizeof(g)/sizeof(int) << endl;

    std::cout << sum << std::endl;

    // range loop
    for (int x : g)
        cout << x << endl;


    // modify array using range loops
    for (int &x : g)
        x++;
    
     for (int x : g)
        cout << x << endl;

}



// int main(){
//     5;              // signed int  - int , unsigned int - size_t, long int
//     4.123;          // double  , long double
//     3.1415f;         // float
//     'a';            // ASCII('a') = 97, 'A' = 65, 'B'=66
//     "sharaf sami";  // C++ strings (Objects) --- c_strings (Arrays of chars)
//     true;           // bool
// }