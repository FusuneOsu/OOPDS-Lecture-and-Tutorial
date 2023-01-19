#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;


template <typename S,typename T> 
class Var {
    S data_structure_type; //type of the data structure
    T data_type; //datatype of the data structure
    public:

    //create a named data structure
    Var() { cout << "Created a data structure using the default constructor" << endl; }
    Var(T value, S ds) { 
        data_type = value;
        data_structure_type = ds;
        cout << "Created a data structure using the parameterized constructor" << endl;
    }
    void set_data_type(T value) { data_type = value; }
    void set_data_structure(S ds) { data_structure_type = ds; }
    T get_data_type() { return data_type; }
    S get_data_structure() { return data_structure_type; }

    // Delete a named data structure
    ~Var(){ cout << "Deleted the data structure" << endl; }

    // Display contents of DS
    void display() { 
        cout << "Data Type: " << data_type << endl;
        cout << "Data Structure Type: " << data_structure_type << endl;
    }

    // Search for an element


    // Sort the elements

    // Clone a data structure

};

class SLL:public Var<int, int> {
    // Add node to the end
    // Delete a node from the end
    // Add node to the front
    // Delete a node from the front
    // insert value after a node
    // Point to the beginning of the list
    // Get the value at a pointer and store it in var
    // Move the pointer forward
    // Check if ptr reached the end of list
    // if boolean variable true print message
    // if boolean variable not true print message
    private:

    public:
    
    // struct Node {
    //     int data;
    //     Node* next;
    // };
    // Node* head;
    // private:

    // public:
    // SLL() { head = nullptr; }
    // void push(int data);
    // int pop();
    // bool isEmpty();
    // void display();
};

class DLL {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;
    Node* tail;
    public:
    DLL() { head = tail = nullptr; }
    void push(int data);
    int pop();
    bool isEmpty();
    void display();
};

class Stack {
    struct Node {
        int data;
        Node* next;
    };
    Node* top;
    public:
    Stack() { top = nullptr; }
    void push(int data);
    int pop();
    bool isEmpty();
    void display();
};

class Queue {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    public:
    Queue() { head = tail = nullptr; }
    void enqueue(int data);
    int dequeue();
    bool isEmpty();
    void display();
};

class BST {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;
    public:
    BST() { root = nullptr; }
    void insert(int data);
    bool search(int data);
    void remove(int data);
    void display();
};

class Vec {
    std::vector<int> data;
    public:
    void push(int value);
    int pop();
    int size();
    void display();
};

int main(){
    //cout << enter the dataset:
    //getline (cin, Var);
    Var<string, int> *v = new Var<string, int>;
    v->set_data_structure("SLL");
    v->set_data_type(90);
    v->display();
    delete v;
    return 0;
}