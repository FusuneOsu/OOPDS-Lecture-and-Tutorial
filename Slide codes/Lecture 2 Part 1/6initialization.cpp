// constructor must be named the same as the class
// constructor must have no return type

// function inside class declaration
class Square
{
private:
    int side;

public:
    Square ( int s = 0) { //default and parameterized constructor combined
    side = s;
    }
    //top line is equal to below lines
    // Square(int v)
    // { // parameterized constructor
    //     side = v;
    // }
    // Square()
    // { // default constructor
    //     side = 0;
    // }
    void setSide(int v) 
    {
        side = v;
    }

    int getSide()
    {
        return side;
    }
};

// declare funcition outside the class
class Square
{
private:
    int side;

public:
    Square();
    Square(int v);
    void setSide(int v);
    int getSide();
};
Square::Square()
{ // default constructor
    side = 0;
}
Square::Square(int v)
{ // parameterized constructor
    side = v;
}
Void Square::setSide(int v)
{
    side = v;
}
int Square::getSide()
{
    return side;
}

int main()
{

}