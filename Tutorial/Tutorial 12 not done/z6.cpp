// 2. Stack-based Evaluation of Postfix Expressions
// Write a program that reads postfix expressions and prints their values. Each input expression
// should be entered on its own line, and the program should terminate when the user enters a
// blank line. Assume that there are only binary operators and that the expressions contain no
// variables. Your program should use a stack. Here are sample input-output pairs:
// 78             78
// 78 6 +         84
// 78 6 + 9 2 - / 12

#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluate(string &exp){
    stringstream data(exp);
    stack<string> stk;

    while (!data.eof()){
        string op;
        data >> op;

        if ( op == "+" || op == "-" || op == "*" ||  op == "/")
        {
            int x = stoi(stk.top());
            stk.pop();
            int y = stoi(stk.top());
            stk.pop();

            if (op == "-")
                stk.push(to_string(y-x));
            else if (op == "+")
                stk.push(to_string(y+x));
            else if (op == "/")
                stk.push(to_string(y/x));
            else if (op == "*")
                stk.push(to_string(y*x));

        //cout << op << endl;
    }
    else stk.push(op);
}
return stoi(stk.top());
}

int evaluate2(string &exp){
    stringstream data(exp);
    stack<string> stk;

    while (!data.eof()){
        string op;
        data >> op;

        if (op == "+" || op == "-" || op == "*" ||  op == "/" )
        {
            int x = stoi(stk.top());
            stk.pop();
            int y = stoi(stk.top());
            stk.pop();

            if (op == "-")
                stk.push(to_string(x-y));
            else if (op == "+")
                stk.push(to_string(y+x));
            else if (op == "/")
                stk.push(to_string(x/y));
            else if (op == "*")
                stk.push(to_string(y*x));

        //cout << op << endl;
    }
    else stk.push(op);
}
return stoi(stk.top());
}

int PostFix(string &ex)
{
    return evaluate(ex);
}

int PreFix(string &ex)
{
    stack<string> stk;
    stringstream ss;

    string rex;
    while(!stk.empty()){
        rex += " " + stk.top();
        stk.pop();
    }

    //reverse the string
    while(!ss.eof())
    {
        string str;
        ss >> str;
        stk.push(str);
    }

    return evaluate2(ex);
}

int main(){

string exp = "78 6 + 9 2 - /";
// string exp;
// getline(cin, exp);
int value1 = PostFix(exp);
cout << "postfix: " << value1 << endl; //one of these

string exp2 = "/ + 78 6 - 9 2";
int value2 = PreFix(exp2);
cout << "prefix: " << value2 << endl;//is not working
}
