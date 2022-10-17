#include <iostream>
using namespace std;

int main(){

    // ptr can change and *ptr can also change
    int *ptr = new int(10);
    delete ptr;
    ptr = new int (99);
    *ptr = 100;


    // qtr can change but *qtr can't change
    // because it is a constant
    const int *qtr = new int (100);
    delete qtr;
    qtr = new int(200);
    // *qtr = 900;  // error *qtr is const


    // cptr is a constant must be initialized
    // when declared. Then can't change.
    // *cptr can change
    int *const cptr  = new int(9);
    
    // error because cptr is const
    //cptr = new int(8);
    *cptr = 88;


    const int * const ccptr = new int(77);
    // the following 2 lines are illegal
    // because both the ccptr and its 
    // storage on the heap are both const
    // ccptr = new int(55);
    // *ccptr = 30;

}