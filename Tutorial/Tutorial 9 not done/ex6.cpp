#include <ctime>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
using namespace std;
Shape *getShape()
{
    int x = rand() % 40;
    if (rand() % 2 == 0)
        return new Circle("@", x, x, x);
    else
        return new Square("#", x, x, x);
}

int main()
{
    srand(unsigned(time(0)));
    Shape *sptr;
    sptr = new Circle;
    sptr->draw();
    Circle *cptr;
    
    // (11) Modify the line [cptr = sptr;] to [cptr = static_cast<Circle*> (sptr);] then compile and run the
    // program. Using the static cast here is allowed since we are certain about the type off the
    // object pointed at by a Shape pointer (Circle object).
    //cptr = sptr;
    cptr = static_cast<Circle*> (sptr);

    cptr->draw();
    delete sptr;
    return 0;
}

//g++ ex6.cpp Shape.cpp Circle.cpp Square.cpp

// Question 10 errors:
// ex6.cpp: In function 'int main()':
// ex6.cpp:22:12: error: invalid conversion from 'Shape*' to 'Circle*' [-fpermissive]       
//    22 |     cptr = sptr;
//       |            ^~~~
//       |            |
//       |            Shape*

// Question 11 Output:
// @@ -> Shape param. constr.
// @@ -> Circle default constr.
// @@ is Circle at (0,0) with radius 0
// @@ is Circle at (0,0) with radius 0
// @@ => Circle destroyed.
// @@ destroyed.