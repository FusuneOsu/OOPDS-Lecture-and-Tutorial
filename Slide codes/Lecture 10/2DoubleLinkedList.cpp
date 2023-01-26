#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

template<typename T>
struct DNode{
T info;
DNode<T> *next;
DNode<T> *prev;
DNode(T v=T()){
info = v;
next = nullptr;
prev = nullptr;
}
};

template<typename T>
class DoubleList {
DNode<T> *head;
DNode<T> *tail;
int sz;
:
public:
DoubleList(){
head = tail = nullptr;
sz = 0;

}

};

