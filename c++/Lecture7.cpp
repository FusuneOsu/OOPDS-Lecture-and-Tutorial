#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue
{

    list<T> data;
    public:
    void push(T v)
    {
        data.push_back(v);
    }

    void pop()
    {
        data.pop_front();
    }

    T front()
    {
        return data.front();
    }

    bool empty()
    {
       return data.empty();
    }
};

int main()
{
    Queue<string> s;
    s.push("A"); //
    s.push("B"); //

    while (!s.empty())
    {
        cout << s.front() << endl;
        s.pop();
    }
}