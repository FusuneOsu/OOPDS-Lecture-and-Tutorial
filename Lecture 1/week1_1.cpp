#include <iostream>
using namespace std;

int main(){
    int x = 199;
    int y = 100;
    char ch = 'A';
    char ed = '\0';

    int *ptr = &x;
    int *qtr = &y;
    char *ctr = &ch;

    cout << ptr << endl;
    cout << qtr << endl;
    cout << ctr << endl;

    cout << *ptr << endl;  // the content of the address stored in ptr
    cout << *qtr << endl;
    cout << *ctr << endl;

    return 0;
}   