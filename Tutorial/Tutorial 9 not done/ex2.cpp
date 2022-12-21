#include <iostream>
#include <memory>
#include "Shape.h"
using namespace std;
int main() {
Shape s1;
Shape s2("s2",10,12);
unique_ptr<Shape> s3 = make_unique<Shape>("s3",3,2);
Shape *s4 = new Shape("s4",4,4);
s1.draw();
s2.draw();
s3->draw();
s4->draw();
return 0;
}