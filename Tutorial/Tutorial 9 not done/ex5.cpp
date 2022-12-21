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
    for (int i = 0; i < 3; i++)
    {
        cout << "---------\n";
        Shape *cptr;
        cptr = getShape();
        cptr->draw();
        delete cptr;
        cout << "---------\n";
    }
    Shape *cptr;
    cptr = getShape();
    cptr->draw();
    delete cptr;
    return 0;
}

//g++ ex5.cpp Shape.cpp Circle.cpp Square.cpp

// Question 9 output:
// ---------
// @ -> Shape param. constr.
// @ -> Circle param. constr.
// @ is Circle at (17,17) with radius 17
// @ => Circle destroyed.
// @ destroyed.
// ---------
// ---------
// # -> Shape param. constr.
// # -> Square param. constr.
// # is Square at (4,4) with side = 4
// # => Square destroyed.
// # destroyed.
// ---------
// ---------
// @ -> Shape param. constr.
// @ -> Circle param. constr.
// @ is Circle at (23,23) with radius 23
// @ => Circle destroyed.
// @ destroyed.
// ---------
// @ -> Shape param. constr.
// @ -> Circle param. constr.
// @ is Circle at (9,9) with radius 9
// @ => Circle destroyed.
// @ destroyed.
