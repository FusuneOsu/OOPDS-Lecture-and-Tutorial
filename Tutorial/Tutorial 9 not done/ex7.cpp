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
}
return ptr;
}

int main()
{
srand(unsigned(time(0)));
cout << "-------1------\n";
Shape *sptr;
sptr = getShape();
sptr->draw();
cout << "-------2------\n";
Circle *cptr;
cptr = static_cast<Circle*>(sptr);
cptr->draw();
cout << "-------3------\n";
delete sptr;
return 0;
}

//g++ ex7.cpp Shape.cpp Circle.cpp Square.cpp

//Question 12 Output:
// -------1------
// # -> Shape param. constr.
// # -> Square param. constr.
// # is Square at (3,3) with side = 3
// -------2------
// # is Square at (3,3) with side = 3
// -------3------
// # => Square destroyed.
// # destroyed.