#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
class List
{
    Node *head;
    int size;

public:
    List()
    {
        head = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }

    // 2) Write a parametrized constructor to add a single node to the list initialized to a value passed as
    // a parameter to the constructor and initialize its pointer to nullptr, then increase the size. Then
    // run the main function below.
    List(int value)
    {
        head = new Node;
        head->data = value;
        head->next = nullptr;
        size = 1;
    }

    //3) Write a function [void push_front(int v);] that will add a new node. The front of the list.
    void push_front(int value)
    { 
        Node *ptr = new Node;
        ptr->data = value;
        if (head == nullptr)
        {
            head = ptr;
            head->next = nullptr;
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
        size++;
    }

    // 4) Write a method named begin() that will return the head of the List.

    //REWATCH TUTORIAL WEEK 10 TO GET ALL ANSWERS
    //https://drive.google.com/file/d/1JazQ2ZjAYB0-63EaYW946wOnD0-mzMk7/view

    // 5) Write a method named end() that will return nullptr as the end of list.
};

//EX2 Question 1
// int main()
// {
//     List lst;
//     cout << boolalpha << lst.isEmpty() << endl;
//     return 0;
// }

//EX2 Question 3
int main() {
List lst;

cout << boolalpha << lst.isEmpty() << endl;
lst.push_front(20);
lst.push_front(10);
return 0;
}
