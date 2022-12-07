#include <iostream>
using namespace std;

int main(){
    int *ptr = new int(10);
    int *qtr = new int(10);

    cout << ptr << ":" << *ptr << endl;
    cout << qtr << ":" << *qtr << endl;

    if (ptr == qtr)
        cout << "equal" << endl;
    else
     cout << "not equal" << endl;

    if (*ptr == *qtr)
        cout << "equal" << endl;
    else
     cout << "not equal" << endl;

    delete ptr;  // no leak
    delete qtr;  // no leak
}