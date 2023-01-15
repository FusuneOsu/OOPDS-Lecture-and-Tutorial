#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
const int SIZE = 5;
array<int, SIZE> a1 {1,2,3,4,5};
for (int i=0;i<a1.size();i++)
cout << a1[i] << ":";
cout << endl;
array<string,3> a2 = {"A","B","C"};
cout << a2[0] << endl;
a2[1]="D";
for (auto x:a2)
cout << x << ":";
cout << endl;
return 0;
}