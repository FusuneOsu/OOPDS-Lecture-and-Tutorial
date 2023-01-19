#include <iostream>
#include <string>
#include <stack>
using namespace std;

template <typename S, typename T>
class Var
{
    S data_structure_type;
    stack<T> data;
    string name;

public:
    Var() {}
    Var(T value, S ds, string dname)
    {
        data.push(value);
        data_structure_type = ds;
        name = dname;
    }
    void AddE(T value) { data.push(value); }
    void set_data_structure(S ds) { data_structure_type = ds; }
    void set_data_structure_name(string dname) { name = dname; }
    T get_data_type() { return data.top(); }
    S get_data_structure() { return data_structure_type; }
    string get_data_structure_name() { return name; }
    void display()
    {
        while (!data.empty())
        {
            cout << data.top() << ":";
            data.pop();
        }
    }
    void Delete()
    {
        while (!data.empty())
            data.pop();
    }
};

int main()
{
    string command;
    cin >> command;
    if (command == "Var")
    {
        string ds, dt, dname;
        cin >> ds >> dt >> dname;
        if (dt == "integer")
        {
            int value;
            cin >> value;
            Var<string, int> v(value, ds, dname);
            while (cin >> command)
            {
                if (command == "AddE")
                {
                    cin >> dname;
                    if (dname == v.get_data_structure_name())
                    {
                        int val;
                        cin >> val;
                        v.AddE(val);
                    }
                }
                else if (command == "print")
                {
                    cin >> dname;
                    if (dname == v.get_data_structure_name())
                    {
                        v.display();
                    }
                }
                else if (command == "delete")
                {
                    cin >> dname;
                    if (dname == v.get_data_structure_name())
                    {
                        v.Delete();
                    }
                }
                else
                    break;
            }
        }
    }
    return 0;
}
