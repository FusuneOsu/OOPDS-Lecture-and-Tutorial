#include "Shape.h"
#include "Circle.h"
using namespace std;
int main() {
Circle c1;
c1.draw();
return 0;
}

//g++ ex3.cpp Shape.cpp Circle.cpp

// no virtual:
// @@ -> Shape param. constr.
// @@ -> Circle default constr.
// @@ is Shape at (0,0)
// @@ => Circle destroyed.
// @@ destroyed.

//with virtual:
// @@ -> Shape param. constr.
// @@ -> Circle default constr.
// @@ is Shape at (0,0)
// @@ => Circle destroyed.
// @@ destroyed.

//after question 5:
// @@ -> Shape param. constr.
// @@ -> Circle default constr.
// @@ is Circle at (0,0) with radius 0
// @@ => Circle destroyed.
// @@ destroyed.