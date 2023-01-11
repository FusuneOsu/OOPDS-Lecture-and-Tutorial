//bst = binary search tree . cpp

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};


template <class T>
class BST {
private:
    Node<T>* root;

public:
    BST() {
        root = nullptr;
    }
    
    void insert(T data) {
        root = insertHelper(root, data);
    }

    Node<T>* insertHelper(Node<T>* r, T data) {
        if (r == nullptr) {
            return new Node<T>(data);
        }

        if (data < r->data) {
            r->left = insertHelper(r->left, data);
        } else if (data > r->data) {
            r->right = insertHelper(r->right, data);
        }

        return r;
    }

    void rec_inorder(Node<T> *ptr){
        if (ptr == nullptr) return;
        rec_inorder(ptr->left);
        cout << ptr->data << ":";
        rec_inorder(ptr->right);
    }

    void inorder(){
        cout << "\nInorder traversal:" << endl;
        rec_inorder(root);
        cout << "\nEnd ..." << endl;
    }
    

    void deleteNode(T key) {
        root = deleteNodeHelper(root, key);
    }

    Node<T>* deleteNodeHelper(Node<T>* r, T key) {
        if (r == nullptr) return r;

        if (key < r->data) {
            r->left = deleteNodeHelper(r->left, key);
        } 
        else 
            if (key > r->data) 
            {
                r->right = deleteNodeHelper(r->right, key);
            } 
            else 
            {
                if (r->left == nullptr) 
                {
                    Node<T>* temp = r->right;
                    delete r;
                    return temp;
                } 
                else 
                if (r->right == nullptr) 
                {
                    Node<T>* temp = r->left;
                    delete r;
                    return temp;
                }
                Node<T>* temp = minValueNode(r->right);
                r->data = temp->data;
                r->right = deleteNodeHelper(r->right, temp->data);
        }
        return r;
    }

    Node<T>* minValueNode(Node<T>* r) {
        Node<T>* current = r;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
    
    void deleteTree(Node<T>* r) {
        if (r == nullptr) return;
        deleteTree(r->left);
        deleteTree(r->right);
        delete r;
    }
    
    ~BST() {
        deleteTree(root); //delete the entire binary tree
    }
};

int main(){
    BST<int> bt;

    bt.insert(9);
    bt.insert(7);
    bt.insert(11); 
    bt.insert(10);
    
    bt.inorder();
    bt.deleteNode(11);
    bt.inorder();

    return 0;
}