#include <iostream>

using namespace std;


void fun(float *v){
     cout << *v << endl;
    *v = 56.4f;
}

int main()
{
    int x = 10;
    int &rx = x;    // lvalue reference to x

    float &&PI = 3.1415962f;    // rvalue reference

    PI+=10;

    cout << PI << endl;
}



// void fun(float *v){
//      cout << *v << endl;
//     *v = 56.4f;
// }

// void fun(int *v)
// {
//     cout << *v << endl;
//     *v = 40;
// }

// void fun(int x){
//     cout << x << endl;
//     x = 200;
// }

// void fun(float x){
//     cout << x << endl;
//     x = 1.12f;
// }

// int main()
// {
//     int x = 10;
//     float y = 3.14f;
    
//     fun(&x);
//     fun(&y);
//     fun(10);
//     fun(x);
//     fun(3.145f);

// }


// void fun(int *v)
// {
//     cout << *v << endl;
//     *v = 40;
// }

// int main()
// {
//     int x = 10;
//     cout << x << endl;
//     fun(&x);
//     cout << x << endl;
// }




// void fun(int &v){
//     cout << v << endl;
//     v = 40;
// }

// int main()
// {
//     // int t = 10;
//     // int &r = t;    // t is an int reference to t

//     // cout << t << ":" << r << endl;

//     // // int &tr;  // references must be initialized to reference 
//     //              // a variable of the same type

//     int x = 10;
//     cout << x << endl;
//     fun(x);
//     cout << x << endl;
// }



// #include <iostream>

// using namespace std;

// void fun(int x){
//     cout << x << endl;
//     x = 40;
// }

// int main()
// {
//     int x = 10;
//     cout << x << endl;
//     fun(x);
//     cout << x << endl;
// }



// #include <iostream>

// using namespace std;

// void fun(){
//     int x = 20;
//     cout << x << endl;
//     x = 40;
// }

// int main()
// {
//     int x = 10;
//     cout << x << endl;
//     fun();
//     cout << x << endl;
// }

// #include <iostream>

// using namespace std;

// double x = 9.9;   // global variable

// int main(){

//     int x = 10;   // local variable to main

//     {
//         cout << x << endl; // 10

//         float x = 4.5f;    // local variable to the block

//         cout << x << endl; // 4.5
//         cout << ::x << endl;   // prints the value of the global variable
//     }

//     {
//         char x = 'A';

//     }

// }

// int main()
// {
//      int y = 10;
//     // cout << x << endl;
//      {
//         int x;  cout << x << endl;
//         {
//             cout << x << endl;
//             {
//                 cout << x << endl;
//                 {
//                     cout << x << endl;

//                 }
//             }
//         }
//      } // end of the scope of x

//     // cout << x << endl;

// } // end of y's scope