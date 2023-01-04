// A client program (client code) that
// uses the class must #include the
// class specification file and be
// compiled and linked with the class
// implementation file.

#include <iostream>
#include "Square.h"
using namespace std;
Square initSquare()
{
    Square s;
    int inSize;
    cout << "Enter side: ";
    cin >> inSize;
    s.setSide(inSize);
    return s;
}
int main()
{
    Square sq = initSquare();
    cout << sq.getSide()
         << endl;
    return 0;
}

// g++ 13mainSquare.cpp Square.cpp