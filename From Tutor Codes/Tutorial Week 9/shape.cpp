#include <iostream>
#include "shape.h"

Shape::Shape() {
  x = 0;
  y = 0;
  label = "??";
  cout << label 
       << " Shape created using default\n";
}

Shape::Shape(string lbl, int xx, int yy) 
: x(xx), y(yy), label(lbl) 
{
  cout << label 
       << " -> Shape param. constr.\n";
}

string Shape::getLabel() { 
    return label; 
}

void Shape::setLabel(string lbl) { 
    label = lbl; 
}

// lab 9 Ex 8
// draw() is pure virtual and has no implementation

// void Shape::draw() {
//   cout << label 
//        << " is Shape at (" << x 
//        << "," << y << ")" 
//        << endl;
// }

int Shape::getX(){
    return x;
}

int Shape::getY(){
    return y;
}

Shape::~Shape() { 
    cout << label << " destroyed.\n"; 
}