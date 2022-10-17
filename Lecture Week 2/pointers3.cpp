#include <iostream>
using namespace std;

int main(){
    int x {10};

    cout << x << endl;

    cout << &x << endl;
    int *ptr = &x;   // ptr is a pointer variable that 
                     // stores addresses


    cout << *&x << endl;   // next line is the same
    cout << *ptr << endl;

    int *qtr = ptr;
    int **pptr = &ptr;

    cout << "**pptr = " << **pptr << endl;

    int ***ppptr = &pptr;

    // arrays and pointers
   
    int grades[]{90,80,70,67};
    cout << *(grades+0) << endl;
    cout << *(grades+1) << endl;
    cout << *(grades+2) << endl;
    cout << *(grades+3) << endl;
     
     // grades is equal --> const int *grades

      int *aptr = grades;
     aptr = &grades[0];
     
     // grades[0]   == *(aptr+0)   == *(grades+0) == aptr[0]


     cout << aptr[0] << endl;
     cout << *aptr << endl;
     cout << *(aptr+0) << endl;

     // grades = ptr;   // error: grades is constant


    cout << grades << endl;
    cout << aptr << endl;
    cout << (aptr + 1) << endl;
    cout << &grades[1] << endl;
    cout << &aptr[1] << endl;

    int b[]{1,2,3,4};

    aptr = b;
    cout << *aptr << endl;

}