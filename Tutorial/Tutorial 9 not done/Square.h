#ifndef Square_h
#define Square_h
#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;
class Square : public Shape
{
    int side;

public:
    Square();
    Square(string, int, int, int);
    ~Square();
    void draw();
    int getSide();
    void setSide(int);
};
#endif