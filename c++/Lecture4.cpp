#include <iostream>
#include <vector>
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

A* find(auto vars, string name)
{
    auto it = vars.begin();
    while (it->first != name && it != vars.end())
    {
        it++;
    }

    return it->second;
}
using namespace std;

int main()
{
    // map <name of the variable, pointer to a superclass>
    vector<pair<string, A *>> vars;

    // Var stack int st;
    //  in our case is Var B int st

    pair<string, A *> p1("st", new B); // =  vars["st"] = new B;
    vars.push_back(p1);
    // Var C int ct
    vars.push_back({"ct", new C}); // = vars["ct"] = new C

    // ad ct 5
    auto it = find(vars,"ct");
    it->push(5); // = vars["ct"]->push(5);

    // vars["st"]->push(17);
}
