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

int main()
{
srand(unsigned(time(0)));
Shape *sptr;
sptr = getShape();
cout << typeid(sptr).name() << endl;
cout << typeid(*sptr).name() << endl;
delete sptr;
return 0;
}

//g++ ex8.cpp Shape.cpp Circle.cpp Square.cpp

//Question 12 Output
// # -> Shape param. constr.
// # -> Square param. constr.
// # -> Shape param. constr.
// # -> Square param. constr.
// P5Shape
// 6Square
// # => Square destroyed.
// # destroyed.