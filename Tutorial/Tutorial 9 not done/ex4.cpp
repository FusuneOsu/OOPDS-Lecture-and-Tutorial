//Question 6

#include <memory>
#include "Shape.h"
#include "Circle.h"
using namespace std;
int main() {

//no need for all these because Shape is now a pure virtual function
// Shape *sptr;
// sptr = new Shape("s",1,1);
// sptr->draw();

Shape *cptr;
cptr = new Circle("c",2,2,3.5);
cptr->draw();
//delete sptr;
delete cptr;
return 0;
}

//g++ ex4.cpp Shape.cpp Circle.cpp

// Question 6 output:
// s -> Shape param. constr.
// s is Shape at (1,1)
// c -> Shape param. constr.
// c -> Circle param. constr.
// c is Shape at (2,2)
// s destroyed.
// c => Circle destroyed.
// c destroyed.

//Question 7 output:
// s -> Shape param. constr.
// s is Shape at (1,1)
// c -> Shape param. constr.
// c -> Circle param. constr.
// c is Circle at (2,2) with radius 3.5
// s destroyed.
// c => Circle destroyed.
// c destroyed.

// Question 8 output:
// c -> Shape param. constr.
// c -> Circle param. constr.
// c is Circle at (2,2) with radius 3.5
// c => Circle destroyed.
// c destroyed.
//There is no more "s"
 
// Question 8 compile time errors:
// ex4.cpp: In function 'int main()':
// ex4.cpp:9:25: error: invalid new-expression of abstract class type 'Shape'    
//     9 | sptr = new Shape("s",1,1);
//       |                         ^
// In file included from ex4.cpp:4:
// Shape.h:5:7: note:   because the following virtual functions are pure within  
// Shape':
//     5 | class Shape
//       |       ^~~~~
// Shape.h:23:18: note:     'virtual void Shape::draw()'
//    23 |     virtual void draw() =0;
//       |                  ^~~~
// Shape.cpp:39:1: error: 'virtual' outside class declaration
//    39 | virtual void Shape::draw() =0;
// Shape.cpp:39:14: error: function 'virtual void Shape::draw()' is initialized like a variable
//    39 | virtual void Shape::draw() =0;
//       |              ^~~~~
// Shape.cpp:42:1: error: expected unqualified-id before '{' token
//    42 | {
//       | ^
//Because no declaration of pure virtual function in Shape.h

