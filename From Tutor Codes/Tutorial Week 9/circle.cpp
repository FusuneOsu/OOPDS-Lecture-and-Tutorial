#include "circle.h"

Circle::Circle() 
: Shape("@@", 0, 0) {
  radius = 0;
  cout << getLabel() 
       << " -> Circle default constr.\n";
}

Circle::Circle(string lbl, int x, int y, double r) 
: Shape(lbl, x, y) {
  radius = r;
  cout << getLabel() 
       << " -> Circle param. constr.\n";
}

void Circle::setRadius(double r) { 
    radius = r; 
}

double Circle::getRadius() { 
    return radius; 
}

Circle::~Circle() { 
    cout << getLabel() 
         << " => Circle destroyed.\n"; 
}

// Circle inherited getLabel(), getX(),
// and getY() from its super class Shape
// we can't access label, x, and y in shape
// since they are private.

// lab 9 - Ex 5
void Circle::draw() {
  cout << getLabel() 
       << " is Circle at (" << getX() 
       << "," << getY() << ")"
       << " radius = " << radius 
       << endl;
}

// draw() in Circle overrides the pure
// virtual function in Shape
// when we create a new class that inherits
// from Shape, you must provide a function
// draw() for the new class.
// if not declared you will get a compiler error