#include "point.h"
using namespace std;

int main() {
  Point p;

  p.setXY(8, 7);

  cout << p.getName() << "(" 
       << p.getX() << "," 
       << p.getY() << ")" 
       << endl;

  return 0;
}