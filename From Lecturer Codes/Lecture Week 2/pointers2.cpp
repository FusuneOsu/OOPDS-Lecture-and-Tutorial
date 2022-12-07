#include <iostream>
#include <cstring>

using namespace std;
// C strings and C++ strings

int main(){

    char a[] {"abc"};

    cout << sizeof(a) << endl;
    cout << strlen(a) << endl;

    string s {"abc"};
    // cout << sizeof(s) << strlen(s) << endl;
    cout << sizeof(s) << ":" << s.length() << endl;


    string cppstr{"abcd"};
    char   cstr[] {"1234"};
    // cstr is an array of chars
    // array names are constants
    // array names are addresses in memory

    cout << cstr << ":" << cppstr <<endl;

    // cppstr = cstr;     // OK

    // cstr = cppstr;     // error
    // cstr = cppstr.c_str();  // error

    memcpy(cstr, cppstr.c_str(), cppstr.length()+1);

    cout << cstr << ":" << cppstr <<endl;

}