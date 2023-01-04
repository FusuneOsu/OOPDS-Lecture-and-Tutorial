#include <iostream>
using namespace std;

class myPair {
private:
int x;
int y;
public:
myPair(int x=0, int y = 0) {
this->x = x;
this->y = y;
}
int getX(){ return x;}
int getY(){ return y;}
void show(){
cout << x << "," << y << endl;
}
};

int main()
{
myPair a(10,20);
a.show();
myPair b = a;
b.show();
myPair c;
c = a;
c.show();
return 0;
}