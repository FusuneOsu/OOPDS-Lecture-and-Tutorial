#include <iostream>
using namespace std;

class Shape
{
private:
    int x;
    int y;
    string label;

public:
    Shape()
        : x(0), y(0), label("Generic Shape")
    {
        cout << label << " created using default\n";
    }
    Shape(int xx, int yy, string lbl) : x(xx), y(yy), label(lbl)
    {
        cout << label << " created using (int,int, string)\n";
    }

    void setX(int x){this->x=x;}
    void setY(int y){this->y=y;}

    int getX(){return x;}
    int getY(){return y;}

    string getLabel()
    {
        return label;
    }
    void setLabel(string lbl)
    {
        label = lbl;
    }
    virtual ~Shape()
    {
        cout << label << " destroyed.\n";
    }

   virtual void print()=0; //=0; turns it into pure void function
    // {
    //     cout << getLabel() << "(" << getX() << "," << getY() << ")" << endl;
    // }
};

// 1) Derive a class named Circle with public inheritance from class
// Shape. The class Circle has a data member named radius of type
// double.

class Circle:public Shape
{
    private:
    double radius;

// 2) Write a default constructor for Circle that will explicitly
// invoke the default constructor of Shape, sets the label in
// Circle to (Default circle), x and y to zeros and sets the
// radius to (0.0f). The constructor must display a message
// saying a generic circle is created.
public:
    Circle():Shape()
    {
        setLabel("Default circle");
        cout << "a generic circle is created" << endl;
    }

// 3) Write a parameterized constructor for class Circle that
// accepts 2 integer values for x and y, a double value for
// radius, and a string value for label. Initialize the shape by
// explicitly invoking the Shape parametrized constructor then
// initialize the data members of Circle using these parameters.
// The constructor must display a message with the label (A
// Circle is created using non-default cons).
    Circle(int x, int y, double r, string lbl):Shape(x,y,lbl)
    {
        radius = r;
        cout << "A Circle is created using non-default cons" << endl;
    }

// 4) Create accessors and mutators for the private variables (x and
// y, label, and radius) inside the Circle class.

    void setRadius(double r){radius = r;}

    void print()
    {
        cout << getLabel() << "(" << getX() << "," << getY() << ")"
        << "radius = " << radius << endl; 
    }

    virtual ~Circle()
    {cout << getLabel() << " is destroyed - in circle" << endl;}
};
// 5) Add a method print to the Shape class to print the label of
// the shape and its position (x,y).

// 6) Add a method print to Circle to print the label of the circle,
// position (x,y), and radius.

// 7) In the main program create an objects of type Shape named
// vShape and an object of type Circle named vCircle. Then invoke
// the print method for both objects. Observe the output of the
// program and identify which print method is executed in both
// cases.
int main()
{
    // Shape vShape;
    // Circle vCircle;

    //vShape.print();
    //vCircle.print();

// 8) Declare a pointer to Shape named sptr1 and a pointer to Circle
// named cptr. Assign both to heap objects of type Circle. Run
// the program and observe which print method is invoked.
    // Shape *sptr1 = new Shape;
    // Circle *cptr = new Circle;
    // sptr1->print();
    // cptr->print();

// 9) Set the print method in class Shape as virtual.

// 10) Rerun the program and explain the difference in the output
// caused by the virtual keyword.

// 11) Modify the print method in Shape to become a pure virtual
// method. Then compile the program and explain the errors. Study
// and document these errors.

// 12) Add a destructor to the Circle class. The destructor must
// display a label and a message saying circle destructor is
// invoked.

// 13) In the main program, create a heap object of type Circle
// pointed at by ptr. Then run the program. Explain why the
// destructor of Circle is not invoked.

// 14) In the main program free the object allocated to ptr. Then run
// the program and observe the output. Explain the output.

// 15) Add virtual keyword to the destructor of the Circle. Then
// rerun the main program and explain what happens.

// 16) Create a class named Rectangle that inherits publicly from
// Shape. The rectangle class has two private members length and
// height.

// 17) Add a print method to the Rectangle class. Perform all the
// steps from 7 to 15 replacing the Circle with Rectangle.

// 18) Create an array of Shape pointers that will randomly point to
// Circles or Rectangles. Then invoke the method print in these
// objects.
    return 0;
}