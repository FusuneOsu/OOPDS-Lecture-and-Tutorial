#include <iostream>
#include <ctime>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
using namespace std;

Shape* getShape(){
int x = rand()%4;
Shape *ptr=nullptr;
switch(x){
case 0:
case 2: ptr = new Circle("@",x,x,x);
break;
case 1:
case 3: ptr = new Square("#",x,x,x);
default:
ptr = new Square("#",x,x,x);
}
return ptr;
}

int main() {
srand(unsigned(time(0)));
int c=0,s=0;
for (int i=0;i<1000;i++){
Shape *sptr = getShape();

//Question 15 added code lines:
//
Circle *cptr;
cptr = dynamic_cast<Circle*>(sptr);
//

if (typeid(*sptr) == typeid(Circle))
c++;
else
s++;
delete sptr;
}
cout << "The program created " << c << "circles\n";
cout << "The program created " << s << "squares\n";
return 0;
}

//g++ ex9.cpp Shape.cpp Circle.cpp Square.cpp

//Question 14 output (last part only):
// The program created 488circles
// The program created 512squares

//Question 15 output:
// The program created 471circles
// The program created 529squares

//Question 16 answer:

