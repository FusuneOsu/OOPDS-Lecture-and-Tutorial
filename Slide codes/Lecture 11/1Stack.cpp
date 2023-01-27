#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

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
Stack& operator=(const Stack&ot);
bool full();
bool empty();
bool push(T v);
bool pop();
T top();
int size();
int getcapacity();
};

Stack(int cp):capacity(cp),sz(0),tp(-1){
data = new T[cp];
}
Stack(const Stack& ot){
capacity=ot.capacity;
sz= ot.sz;
tp = ot.tp;
data = new T[capacity];
for (int i=0;i<capacity;i++){
data[i] = ot.data[i];
}
}

Stack(Stack&& ot)
{
capacity=ot.capacity;
size = ot.sz;
tp = ot.tp;
data = ot.data;
ot.data = nullptr;
}

Stack& operator=(const Stack& ot) {
capacity=ot.capacity;
sz = ot.sz;
tp = ot.tp;
data = new T[capacity];
for (int i=0;i<capacity;i++) {
data[i] = ot.data[i];
}
return *this;
}

bool full() {
return sz == capacity;
}

bool empty() {
return tp == -1;
}

bool push(T v) {
if (!full()) {
tp++;
data[tp]=v;
sz++;
return true;
}
else
return false;
}

bool pop() {
if (!empty()) {
data[tp] = -1;
tp--;
sz--;
}
return false;
}
T top() {
if (!empty())
return data[tp];
else
return T();
}
int size() {
return sz;
}
int getcapacity() {
return capacity;}

int main() {
Stack<int> a(5);
Stack<int> b(5);
Stack<int> d(Stack<int>(3));
cout << d.getcapacity() << endl;
for (int i=0;i<5;i++)
a.push(i*2);
Stack<int> c(a);
cout << "Stack a:\n";
while (!c.empty()){
cout << c.top() << ":";
c.pop();
}
cout << endl;
while (!a.empty()){
b.push(a.top());
a.pop();
}

cout << "Stack b:\n";
while (!b.empty()) {
cout << b.top()
<< ":";
b.pop();
}
cout << endl;
return 0;
}