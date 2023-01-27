#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T>
class Stack:private list<T> {
public:
Stack()=default;
bool full();
bool empty();
void push(T v);
void pop();
T top();
int size();
};

template<class T>
void Stack<T>::push(T v) {
list<T>::push_back(v);
}

template<class T>
int Stack<T>::size() {
return this->size();
}

template<class T>
bool Stack<T>::empty() {
return list<T>::empty();
}

template<class T>
void Stack<T>::pop() {
this->pop_back();
}
template<class T>
T Stack<T>::top() {
if (!empty())
return this->back();
else
return T();
}

int main() {
Stack<int> a, b;
for (int i=0;i<5;i++) a.push(i*2);
cout << "Stack a:\n";
while (!a.empty()) {
cout << a.top() << ":";
b.push(a.top());
a.pop();
}
cout << endl;
cout << "Stack b:\n";
while (!b.empty()) {
cout << b.top() << ":";
b.pop();
}
cout << endl;
return 0;
}