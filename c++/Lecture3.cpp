#include <iostream>
#include <map>
#include <utility>
#include <stack>
#include <queue>

class A
{
public:
    virtual void push(int) = 0;
};

class B : public A
{
    void push(int v)
    {
        cout << " B was push man come on!" << v << endl;
    }
};

class C : public A
{
    void push(int v)
    {
        cout << " C was push man come on!" << v << endl;
    }
};
using namespace std;

int main()
{
    // map <name of the variable, pointer to a superclass>
    map<string, A *> vars;

    // Var stack int st;
    //  in our case is Var B int st

    vars["st"] = new B;

    // Var C int ct
    vars["ct"] = new C;

    // ad ct 5
    vars["ct"]->push(5);
    vars["st"]->push(17);
}
