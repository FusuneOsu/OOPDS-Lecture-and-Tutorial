// Place the member function
// definitions in a class
// implementation file. Name the file
// classname.cpp (for example,
// Square.cpp)This file should
// #include the class specification file.

#include <iostream>
#include "Square.h"
using namespace std;
Square::Square(int s){
cout<<"Const ..."<<endl;
side = s;
}
Square::~Square(){
cout <<"Destr ..."<<endl;
}
void Square::setSide(int v){
side = v;
}
int Square::getSide()const{
return side;
}