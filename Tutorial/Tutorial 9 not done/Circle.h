#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
using namespace std;
#include "Shape.h"
class Circle : public Shape
{
    double radius;

public:
    Circle();
    Circle(string, int, int, double);
    void setRadius(double);
    double getRadius();
    void draw();
    ~Circle();

    // (5) Add a method [void draw()] to the Circle class and run the program again. The method must
    // display a message “ label is Circle at (x,y) with r = radius”. You must add two methods to the
    // Shape class to access the data members x and y [getX() and getY()]. Then run the main
    // function in step 3.
};
#endif