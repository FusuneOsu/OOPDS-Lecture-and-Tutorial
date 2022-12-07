#include <iostream>

using namespace std;


// void print (int s=7){

//     cout << s << endl;
// }

void print (int s, int k=0, int g=0){
    cout <<s<<k<<g<<endl;
} 

int main(){

    //print();  // because s in the function arguments must be sent as a parameter and
                // has no default value
    print(5);

    int k = 4;
    print(k);
    
  //  print ();
    print (1);
    print (1,2);
    print(1,2,3);


}