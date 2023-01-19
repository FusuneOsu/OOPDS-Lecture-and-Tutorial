#include <iostream>
using namespace std;
int main() {
pair<int,int> p1 = {1,1};
pair<int,int> p2 {2,2};
pair<int,int> p3 = make_pair(3,3);
cout << p1.first << ":" << p1.second << endl;
p2.first = 1;
p2.second = 1;
cout << p2.first << ":" << p2.second << endl;
cout << get<0>(p3) << ":" << get<1>(p3) << endl;
pair<int,int> p4 = p2;
pair<int,int> *p = &p4;
cout << p->first << ":" << p->second << endl;
p4.swap(p1);
cout << p4.first << ":" << p4.second << endl;
if (p1 == p2 ) cout << "p1 and p2 are equal\n";
else cout << "p1 and p2 are not the equal\n";
}