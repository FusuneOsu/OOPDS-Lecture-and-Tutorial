#include <iostream>
using namespace std;

class Name {
public:
  string first;
  string middle;
  string family;

  Name(string f="", string m="", string fm=""){
    first = f;
    middle = m;
    family = fm;
  }
};

int g = 1;

int &fun() { return g; }

// void print(int x){
//     cout << x*x << endl;
// }

//1
void print(int &x){
    cout << x*2 << endl;
}

//2
void print(int &&x){
    cout << (x-1) << endl;
}


int main() 
{
    print (10);
    // since 10 is an rvalue
    // print 2 is called
    int ee = 10;
    print(ee);
    // ee is an lvalue
    // print 1 is having an
    // lvalue reference therefore
    // print is called

    print(ee+2);
    //ee+2 --> rvalue
    // print 2 is called



  // what is an lvalue
  //    lvalue is a variable or and expression
  //    that can exist on the left side of the
  //    assignment statement.
  //    int x = 10;
  //    ----> x is an lvalue
  //    Any expression with the following
  //    properties is considered an lvalue:
  //    1. has a name
  //    2. has an address
  //    3. can return the address using &
  //    4. can change
  //
  //    rvalue is anything else other than
  //    lvalue.

  // examples of lvalues

  // example 1
  int a;
  cout << &a << endl;
  a = 20;

  // example 2
  fun() = 30; // fun() --> is a reference to g
  cout << g << endl;
  cout << &(fun()) << endl;
  cout << &g << endl;

  // example 3
  int arr[3];
  arr[0] = 1;
  cout << &arr[0] << endl;

  // example 4
  Name name;
  name.first = "Sharaf";
  name.middle = "Sami";
  name.family = "Horani";
  cout << &name << endl;

  // example 5
  string x = "sharaf";   // "sharaf" is an lvalue
                         // special case

  // rvalue examples

  // example 1
  int w = 20;      // 20 is an rvalue
  char ch = 'A';   // 'A' is an rvalue


  Name("A", "B", "ABC");    // rvalue

  int tt = 0;
  int mm = 10;

  cout << (tt+mm) << endl;
  // tt is an lvalue 
  // mm is an lvalue
  // tt+mm is an rvalue

  // lvalue (+-*/%) lvalue or rvalue ---> rvalue
  // x+y/2-z  --> rvalue


   int kk = 90;
   // kk is an lvalue
   int &rkk = kk;
   // int & --> is an lvalue reference that
   // can point to an lvalue

   // can an lvalue reference point to an rvalue
   //int &rf = 20;
   // rf is an lvalue ref
   // 20 is an rvalue
   // error to bind the two

    // rvalue reference can point to an rvalue
    int &&rvref = 40;
    // int && is an rvalue reference
    // 40 is an rvalue, therefore, the two can be bound 


    // test cases

    cout << &kk << endl;
    // &kk ---> expression &kk ---> rvalue

    // &(kk+1)  ---> kk --> lvalue
    //          ---> 1  --> rvalue
    //          ---> kk+1 ---> rvalue
    // can we take the address of an rvalue?
    // NO

    Name mmm = Name("A", "B","C");
    &mmm;


    int *ptr = &kk;
    ptr = &mm;
    cout << &ptr << endl;

    // ptr --> lvalue

    int **qtr = &ptr;
    // qtr ---> lvalue
    // &ptr --> rvalue
    // &mm --> rvalue
    // &kk --> rvalue
    // ptr --> lvalue
    // mm --> lvalue
    // kk --> lvalue

    
  return 0;
}