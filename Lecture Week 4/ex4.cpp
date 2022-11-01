#include <iostream>
using namespace std;
class Square{
    double side;
    string name;
public:
    Square(){
        cout << "Default (" << name << "): Object is created\n";
        side = 0;
    }

    Square(double side, string n){
        cout << "Param ("<< n << "): Object is created\n";
        this->side = side;
        name = n;
    }

    Square(const Square &other){
        side = other.side;
        name = "Copy "+ other.name;
        cout << name << " : Copy constructor\n";
    }

    ~Square(){
        cout << name << " is deleted\n";
    }

    void setSide(double s){
        side = s;
    }

    double getSide() const {
        return side;
    }
};

void print(Square s){
    cout << s.getSide() << endl;
}


int main(){
    Square s(20, "S");
    s.setSide(10);

    Square s2(s);  // calls the copy constructor

    cout << s2.getSide() << endl;

    print (s);

    Square s3(10, "S3");


    int x = 10;
    //int y(x);
    // int y=x;
    // int y{x};

  
}