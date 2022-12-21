#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>

#include "shape.h"

using namespace std;

class Circle : public Shape {
  double radius;

public:
  Circle();
  Circle(string, int, int, double);
  void setRadius(double);
  double getRadius();
  void draw();
  ~Circle();
};
#endif