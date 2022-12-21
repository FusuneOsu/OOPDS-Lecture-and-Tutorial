#include "Square.h"
Square::Square() : Shape("##", 0, 0)
{
    side = 0;
    cout << getLabel() << " -> Square default constr.\n";
}
Square::Square(string lbl, int x, int y, int sd) : Shape(lbl, x, y)
{
    side = sd;
    cout << getLabel() << " -> Square param. constr.\n";
}
Square::~Square()
{
    cout << getLabel() << " => Square destroyed.\n";
}
void Square::draw()
{
    cout << getLabel() << " is Square at ("
         << getX() << "," << getY() << ") with side = "
         << side << endl;
}
int Square::getSide()
{
    return side;
}
void Square::setSide(int s)
{
    side = s;
}

