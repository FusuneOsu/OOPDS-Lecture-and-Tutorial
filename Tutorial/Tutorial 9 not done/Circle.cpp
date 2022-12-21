#include "Circle.h"

Circle::Circle() : Shape("@@", 0, 0)
{
    radius = 0;
    cout << getLabel() << " -> Circle default constr.\n";
}

Circle::Circle(string lbl, int x, int y, double r)
    : Shape(lbl, x, y)
{
    radius = r;
    cout << getLabel() << " -> Circle param. constr.\n";
}
void Circle::setRadius(double r) { radius = r; }
double Circle::getRadius() { return radius; }

void Circle::draw()
{
    cout << getLabel() << " is Circle at ("
         << getX() << "," << getY() << ")"
         << " with radius " << radius
         << endl;
}

//“ label is Circle at (x,y) with r = radius”.

Circle::~Circle()
{
    cout << getLabel() << " => Circle destroyed.\n";
}