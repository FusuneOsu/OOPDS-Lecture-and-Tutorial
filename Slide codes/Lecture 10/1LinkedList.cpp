#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

template <class T> class MyList
    {
    private:
        struct Node
        {
            T value;
            Node *next;
        };
        Node *head;
        Node *tail;
        int sz;
        void *getNew(T d);
        //void *search(T);
        void *movetoend();

    public:
        MyList();
        void push_back(T);
        void push_back_tail(T);
        void push_front(T);
        void insert(T);
        bool insert(int, T);
        bool deleteNode(T);
        void print() const;
        int size();
        ~MyList();
    };


//what does this thing do
template<class T>
MyList<T>::MyList() {
head = nullptr;
sz = 0;
}

// Create a list
template<class T>
void *MyList<T>::getNew(T d)
{
Node *newNode = new Node;
newNode->value = d;
newNode->next = nullptr;
return newNode;
}

// append a node to the end of the list
template<class T>
void MyList<T>::push_back(T d)
{
Node *newNode = static_cast<Node*>(getNew(d));
sz++; //size of the list
if (head == nullptr) {
head = newNode;
} else {
Node *ptr = static_cast<Node*> (movetoend());
ptr->next = newNode;
newNode->next = nullptr;
}
}

//Adding a tail pointer to the end of a linear linked list eliminates the need to traverse the list to reach the last node.
// template<class T>
// void MyList<T>::push_back_tail(T d)
// {
// Node *newNode =
// static_cast<Node*>(getNew(d));
// sz++;
// if (head == nullptr) {
// head = newNode;
// tail = newNode;
// }
// else
// {
// tail->next = newNode;
// tail = newNode;
// }
// }

// Insert a node to the front of the list
template<class T>
void MyList<T>::push_front(T d)
{
Node *newNode = static_cast<Node*>(getNew(d));
sz++;
if(head == nullptr)
{
head = newNode;
}
else
{
newNode->next = head;
head = newNode;
}
}

// insert a node within the list
template<class T>
void MyList<T>::insert(T d){
Node *newNode = static_cast<Node*>(getNew(d));
sz++;
if (head == nullptr) {
head = newNode;
}
else
{
Node *ptr = head;
Node *prev=nullptr;
while (ptr!=nullptr && ptr->value<d)
{
prev = ptr;
ptr = ptr->next;
}
if (prev == nullptr){
head = newNode;
newNode->next = ptr;
}
else {
prev->next = newNode;
newNode->next = ptr;
}
}
}

//Insert a node at a specific position in the linked list
template<class T>
bool MyList<T>::insert(int pos, T v) {
if (pos > sz) return false;
else
{
sz++;
Node *newNode = static_cast<Node*>(getNew(v));
if(pos == 0){
newNode->next = head;
head = newNode;
} else
{
Node *ptr = head;
for (int i=0;i<pos-1;i++){
ptr=ptr->next;
}

newNode->next = ptr->next;
ptr->next = newNode;
}
}
return true;
}

// traverse the linked list
template<class T>
void *MyList<T>::movetoend()
{
Node *ptr = head;
while(ptr->next != nullptr)
ptr=ptr->next;
return ptr;
}

template<class T>
void MyList<T>::print() const
{
Node *ptr = head;
while(ptr!=nullptr)
{
cout << ptr->value << "->";
ptr=ptr->next;
}
cout << endl;
}

// delete a node
template<class T>
bool MyList<T>::deleteNode (T d)
{
Node *prev=nullptr;
Node *cur=head;
while(cur->next!=nullptr && cur->value!=d)
{
prev=cur;
cur=cur->next;
}
if (cur == head)
head = head->next; //first node
else
if(cur->next == nullptr)
prev->next = nullptr; //last node
else
prev->next = cur->next; //middle
sz--;
delete cur;
return true;
}

// delete/destroy the list'
template<class T>
MyList<T>::~MyList()
{
Node *cur;
Node *nextNode;
cur = head;
while(cur != nullptr)
{
nextNode = cur->next;
delete cur;
cur = nextNode;
}
sz =0;
}

//size
template<class T>
int MyList<T>::size() {
return sz;
}
int main()
{
//Add to the front of the list, slide 9
MyList<int> lst;
lst.push_front(10);
lst.push_back(20);
cout << lst.size() << endl;
lst.push_back(40);
lst.push_front(5);
cout << lst.size() << endl;
lst.print();

//New node inserted in order in the linked list, slide 11
MyList<int> lst2;
lst.push_front(10);
lst.push_back(20);
cout << lst2.size() << endl;
lst.insert(15);
cout << lst2.size() << endl;
lst.print();

//Insert a node at a specific position in the linked list, slide 12
MyList<int> lst3;
lst.push_front(10);
lst.push_back(20);
lst.push_back(30);
lst.push_back(40);
cout << lst3.size() << endl;
lst.insert(3,15);
cout << lst3.size() << endl;
lst.print();

//Deleting a Node, slide 15
MyList<int> lst4;
lst.push_front(10);
lst.push_back(20);
lst.push_back(30);
lst.push_back(40);
cout << lst4.size() << endl;
lst.insert(3,15);
cout << lst4.size() << endl;
lst.print();
lst.deleteNode(30);
cout << lst4.size() << endl;
lst.print();

return 0;

}



// https://drive.google.com/file/d/1pD2zfpAw9-cBdz5ZpsRyXdbFMaMbfPWU/view
// https://drive.google.com/file/d/1qJLfj8cVe-Zngqyt8ykD7YWqQsKPK7ej/view
// https://drive.google.com/file/d/1JwUQveRDM0vaVyirYuizskXJaiN2_hMK/view
// https://drive.google.com/file/d/1izrmGd2K1MmODOZsr0nOzO65NeiilUvW/view
// https://drive.google.com/file/d/1kutVMA25JdLVvCRdHxrF_YfHx1mDQehx/view