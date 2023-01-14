#include <iostream>
using namespace std;

int main()
{
const int constInt = 10;
const int *constPtr = &constInt;
int *d1 = const_cast<int*>(constPtr);

*d1 = 15;
cout << *d1 << endl;

int varInt = 20;
const int *varPtr = &varInt;
int *d2 = const_cast<int*> (varPtr);

*d2 = 30;
cout << *d2 << endl;

return 0;
}