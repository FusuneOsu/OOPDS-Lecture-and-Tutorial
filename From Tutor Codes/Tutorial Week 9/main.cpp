#include <iostream>
#include "shape.h"
#include "circle.h"

using namespace std;

// Lab 9 - Ex 6, 7, and 8
int main() 
{
    // Shape is now abstract
    // has pure virtual function

    // Shape *sptr;
    // sptr = new Shape("s",1,1);
    // sptr->draw();

    Shape *cptr;
    cptr = new Circle("c",2,2,3.5);
    cptr->draw();
    // if draw() in the Shape class
    // is not virtual, the draw() 
    // function is decided based on the 
    // pointer type no the object type
    // cptr is a Shape pointer, therefore
    // it will call the draw() in the 
    // Shape class.

    // if draw() in the Shape class is
    // virtual, and the circle has its own
    // draw() function, then the draw() 
    // inside the Circle class will be
    // executed.


    //delete sptr;
    delete cptr;
    return 0;
}

// lab 9 - Ex 5
// int main() 
// {
//     Circle c1("c1", 2,4,9);
//     c1.draw();

//     return 0;
// }


// Lab 9 - Ex 2
// int main() {
//   Shape s1;
//   Shape s2("s2", 10, 12);
//   Shape *s3 = new Shape("s3", 3, 3);

//   s1.draw();
//   s2.draw();
//   s3->draw();

//   delete s3;

//   return 0;
// }

// Lab 9 - Ex 1
// int main() {
//   Shape s1;
//   Shape s2("s2", 10, 12);

//   // s3 is a pointer variable
//   // it is not an object
//   // s3 is a stack variable

//   Shape *s3;

//   // new Shape("s3",3,3) -> a heap object
//   // it  address is stored in s3
//   s3 = new Shape("s3", 3, 3);

//   delete s3;

//   return 0;
// }