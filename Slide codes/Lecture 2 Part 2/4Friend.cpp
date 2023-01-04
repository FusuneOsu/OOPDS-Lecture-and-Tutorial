//Stand-alone Function as a Friend of a Class

#include <iostream>
using namespace std;

class myPair
{
private:
    int x;
    int y;

public:
    friend void print(const myPair &p);
    // Friend function: a function that is not a
    // member of a class, but has access to private
    // members of the class
    // A friend function can be a stand-alone
    // function or a member function of another class
    // It is declared a friend of a class with the friend
    // keyword in the function prototype

    myPair(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void setPair(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }
};

void print(const myPair &p)
{
    cout << p.x
         << ","
         << p.y
         << endl;
}
int main()
{
    myPair p[3] = {{1, 3}, {2, 4}, {3, 5}};
    print(p[1]);
    return 0;
}