#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    //contoh aku ada tukar pape dlm ni
};
int main()
{
    Node *head, *ptr;
    head = new Node; // 1
    head->data = 10;
    ptr = new Node;
    ptr->data = 20;            // 2
    ptr->next = nullptr;       // 3
    head->next = ptr;          // 4
    ptr = head;                // 5
    cout << ptr->data << endl; // 6
    ptr = ptr->next;           // 7
    cout << ptr->data << endl;
    ptr = ptr->next;
    if (ptr == nullptr) // 8
        cout << "end of chain\n";
    return 0;
}