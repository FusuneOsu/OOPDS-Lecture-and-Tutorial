#include <iostream>
using namespace std;
class Square
{
private:
    int side;

public:
    void setSide(int s) //Acessor, get, getter function
    {
        side = s;
    }
    int getSide() //Mutator, set, setter function
    {
        return side;
    }
};

int main()
{
    Square sq1, sq2;
    sq1.setSide(5);
    cout << sq1.getSide()
         << endl;
    return 0;
}