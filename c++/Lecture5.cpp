#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack : private vector<T>
{
    public:
    void push(T v)
    {
        this->push_back(v);
    }

    void pop()
    {
        this->pop_back();
    }

    T top()
    {
        return this->back();
    }

    bool empty()
    {
       return vector<T>::empty();
    }
};

int main()
{
    Stack<string> s;
    s.push("A"); //
    s.push("B"); //

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}