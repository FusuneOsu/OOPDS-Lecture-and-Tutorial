#include <iostream>
using namespace std;

int gl = 100;

int main(){
    int *ptr = nullptr;  // C lang equiv->int *ptr=NULL;
    int x = 10;    // x is created at compile time
    ptr = &x;
    cout << *ptr << endl;


    // storage can be in the stack or the heap
    // normal variables (primitive) are storedon the stack

    // dynamic memory allocation is on the heap
    // variable storage is created at runtime
    int *num1 = new int;
    *num1 = 10;

    // must delete num1 before allocating new
    // storage
    delete num1;
    // prevent the memory leak

    num1 = new int;
    *num1 = 99;

    // memory allocated for the first storage
    // and contains the value 10 is still
    // booked. your program lost this block
    // of memory (memory leak).

    delete num1;

}