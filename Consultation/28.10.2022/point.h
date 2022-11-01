#include <iostream>
using namespace std;

class Point {
  int x;
  int y;
  string name;

public : 
  Point();
  Point(int, int, string);
  ~Point();
  void setXY(int, int);
  void setName(string);
  int getX();
  int getY();
  string getName();
};