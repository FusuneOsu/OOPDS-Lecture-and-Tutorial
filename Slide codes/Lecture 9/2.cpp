#include <iostream>
#include <array>
using namespace std;

int main()
{
const int SIZE = 5;
array<string, SIZE> names = {"Sarah", "William",
"Alfredo"};
array<string,SIZE>::iterator it;
it = names.begin();
*it = "Sharaf";
it++;
it++;
it++;
it++;
*it = "ChienLee";
for (auto x:names)
cout << x << ":";
cout << endl;
return 0;
}