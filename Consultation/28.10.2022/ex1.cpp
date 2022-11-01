#include <iostream>
using namespace std;

struct Point{
    int x;            //4 bytes
    int y;            //4 bytes   
    char name[20];    //20 bytes
};

int main()
{
    Point p{10, 20, "ABCD"};

    cout << sizeof(p) << endl; // 4+4+20 ==> 28 bytes
    
    char *buffer = reinterpret_cast<char *>(&p);

    for (char *ptr=buffer, i=0;i<28; i++, ptr++){
        cout << int(*ptr);
    }
    cout << endl;
    //1000020000656667680000000000000000
    //xxxxxyyyyy

    // reading the first 4 bytes of the buffer
    // convert them into an int
    short *b1 = reinterpret_cast<short *>(buffer);
    cout << *b1 << endl;

    short *b2 = reinterpret_cast<short *>(buffer+2);
    cout << *b2 << endl;


    // take the next 4 bytes of the buffer and 
    // convert them into int
    int *c = reinterpret_cast<int *>(buffer+4);
    cout << *c << endl;

    char *name = buffer+8;

    cout << name << endl;

    return 0;
}