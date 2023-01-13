#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Stack
{

    vector<T> data;
    public:
    void push(T v)
    {
        data.push_back(v);
    }

    void pop()
    {
        data.pop_back();
    }

    T top()
    {
        return data.back();
    }

    bool empty()
    {
       return data.empty();
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