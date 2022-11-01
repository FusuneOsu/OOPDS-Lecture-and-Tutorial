#include "point.h"

Point::Point()
    : x(0), y(0), name("P") {
}

Point::Point(int x, int y, string name) 
: x(x), y(y), name(name) {}

Point::~Point() {}

void Point::setXY(int x, int y) {
  this->x = x;
  this->y = y;
  this->name = "P";
}

void Point::setName(string name) {
  this->name = name;
  this->x = this->y = 0;
}

int Point::getX() { return x; }

int Point::getY() { return y; }

string Point::getName() { return name; }