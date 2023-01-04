// Place the class declaration in a
// header file that serves as the class
// specification file. Name the file
// classname.h (Square.h)

#ifndef SQUARE_H //Square.h. the underscore is a distraction from the dot
#define SQUARE_H
class Square {
private:
int side;
public:
Square(int s=1);
~Square();
void setSide(int v);
int getSide()const;
};
#endif