#include <iostream>
using namespace std;
class Square{
    double side;
public:
    void setSide(int s){
        side = s;
    }

    double getSide(){
        return side;
    }
};

void print(Square s){
    cout << s.getSide() << endl;int s;
}

int main(){
    Square s;
    s.setSide(5);
    cout << s.getSide() << endl;

    Square *p = nullptr;
    cout << &s << endl;

    p = &s;   // p points to the object s

    p->setSide(10);
    cout << (*p).getSide() << endl;


    // references to objects
    Square s2;
    Square &z = s2;     // s2 and z are two names for the same object

    s2.setSide(20);
    cout << z.getSide() << endl;

    print(s2);

}