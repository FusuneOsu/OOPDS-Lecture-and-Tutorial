#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;
class Shape {
private:
  string label;
  int x;
  int y;

public:
  Shape();
  Shape(string, int, int);
  Shape(const string &label);
  string getLabel();
  void setLabel(string);
  //virtual void draw();            // Lab 9 - Ex 7
                                  // virtual in the
                                  // .h file not
                                  // .cpp file
 
  virtual void draw()=0;     // Lab 9 - Ex 8
  // pure virtual function makes the class
  // abstract. So Shape can no longer be used
  // to create objects.
  // it can be used as a pointer to objects
  // of subclasses like Circle
 
  int getX();
  int getY();
  virtual ~Shape();              // ans: Lab 9 Ex 4
};

#endif