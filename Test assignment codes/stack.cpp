#include <iostream>
using namespace std;

template <class T>
class Stack{
private:
    T *data;
    int sz;
    int tp;
    int capacity;

public:
    Stack()=delete;
    Stack(int cp); 
    Stack(const Stack& ot);    
    Stack(Stack&& ot);

    Stack& operator=(const Stack& ot); 
    bool full();
    bool empty(); 
    bool push(T v);    
    bool pop();
    T top(); 
    int size();
    int getcapacity();
};

template<class T>
Stack<T>::Stack(int cp)
    :capacity(cp),sz(0),tp(-1){
        data = new T[cp];
}

template<class T>
Stack<T>::Stack(const Stack& ot){
        capacity=ot.capacity;
        sz= ot.sz;
        tp = ot.tp;
        data = new T[capacity];
        for (int i=0;i<capacity;i++){
            data[i] = ot.data[i];
   }
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack& ot) {
        capacity=ot.capacity;
        sz = ot.sz;
        tp = ot.tp;
        delete[] data;          
        data = new T[capacity];
        for (int i=0;i<capacity;i++) {
            data[i] = ot.data[i];
        }
        return *this;
}

template <class T>
Stack<T>::Stack(Stack&& ot)
{
      capacity=ot.capacity;
      sz = ot.sz;
      tp = ot.tp;
      data = ot.data;
      ot.data = nullptr;
}

template <class T>
bool Stack<T>::full() {
    return sz == capacity;
}

template <class T>
bool Stack<T>::empty() {
        return tp == -1;
}

template <class T>
bool Stack<T>::push(T v) {
  if (!full()) {
      tp++;
      data[tp]=v;
      sz++;
      return true;
   }
    else
   return false;
}

template <class T>
bool Stack<T>::pop() {
    if (!empty()) {
        data[tp] = -1;
        tp--;
        sz--;
     }
      return false;
}

template <class T>
T Stack<T>::top() {
    if (!empty())
        return data[tp];
    else
        return T();
}

template <class T>
int Stack<T>::size() {
    return sz;
}

template <class T>
int Stack<T>::getcapacity() {
    return capacity;
}


int main(){
    Stack<string> st(3);
    st.push("A");
    st.push("B");
    st.push("C");

    Stack<string> st2(2);
    st2 = st;

    while (!st2.empty()){
        cout << st2.top() << endl;
        st2.pop();
    }

}

// int main() {
//     Stack<int> a(5);
//     Stack<int> b(5);
    
//     Stack<int> d(Stack<int>(3));  
//     cout << d.getcapacity() << endl;
    
//     for (int i=0;i<5;i++)
//         a.push(i*2);

//     Stack<int> c(a);
//     cout << "Stack a:\n";
//     while (!c.empty()){
//         cout << c.top() << ":";
//         c.pop();
//     }
//     cout << endl;
    
//     while (!a.empty()){
//         b.push(a.top());
//         a.pop();
//     }
//     cout << "Stack b:\n";
//     while (!b.empty()) {
//         cout << b.top() << ":";
//         b.pop();
//     }
//     cout << endl;
    
//     return 0;
// }