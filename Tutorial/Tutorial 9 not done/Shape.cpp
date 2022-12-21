#include "Shape.h"
#include <iostream>
Shape::Shape()
{
    x = 0;
    y = 0;
    label = "??";
    cout << label << " Shape created using default\n";
}
Shape::Shape(string lbl, int xx, int yy)
    : x(xx), y(yy), label(lbl)
{
    cout << label << " -> Shape param. constr.\n";
}
string Shape::getLabel()
{
    return label;
}
void Shape::setLabel(string lbl)
{
    label = lbl;
}

int Shape::getX()
{
    return x;
}

int Shape::getY()
{
    return y;
}

// (8) Modify the Shape class by setting the draw member function as a pure virtual method.
// Remove the implementation of the draw method from the Shape.cpp file. Rerun the
// program in step 6 and identify the compile time errors. Explain these errors.

// pure virtual function: 
//virtual void Shape::draw() = 0;

// void Shape::draw()
// {
//     cout << label << " is Shape at ("
//          << x << "," << y << ")"
//          << endl;
// }


Shape::~Shape()
{
    cout << label << " destroyed.\n";
}