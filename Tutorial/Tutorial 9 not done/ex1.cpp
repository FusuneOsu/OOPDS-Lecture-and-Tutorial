#include <iostream>
#include <memory>
#include "Shape.h"
using namespace std;
int main()
{
    Shape s1;                                              //
    Shape s2("s2", 10, 12);                                //
    unique_ptr<Shape> s3 = make_unique<Shape>("s3", 3, 2); //
    Shape *s4 = new Shape("s4", 4, 4);                     //
    return 0;
}

//how to run: 1) g++ ex1.cpp Shape.cpp
            //2) ./a.exe