#include<iostream>
using namespace std;
struct Node{
    string name;
    int age;
    Node* left;
    Node* right;
    Node(string n, int a){
        name = n; age = a;
        left = right = nullptr;
    }
};
class Tree{
    public: 
    Node* root;
    Tree():root(nullptr){};
    void insert(string name, int age) {
    Node* newNode = new Node(name, age);
    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node* current = root;
    while (true) {
        if (age == current->age) {
            cout << "Ages can't be equal in a tree!\n";
            delete newNode;
            return;
        }
        else if (age < current->age) {
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            }
            current = current->right;
        }
    }
}
    //left parent right
    void inorderTraversal(Node* root){
        if (root == nullptr){
            return;
        }
        inorderTraversal(root->left);
        cout << root->name << " " << root->age << "\n";
        inorderTraversal(root->right);
    }
    //parent left right
    void preorderTraversal(Node* root) {
    if (root != nullptr) {
        cout << root->name << " " << root->age << "\n";   
        preorderTraversal(root->left);   
        preorderTraversal(root->right);  
    }
    }
    //left right parent
    void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);   
        postorderTraversal(root->right);
        cout << root->name << " " << root->age << "\n";     
    }
    }
};
int main(){
    Tree t;
    t.insert("Ali", 32);
    t.insert("Sara", 29);
    t.insert("Zara", 7);
    t.insert("Ahmad", 2);
    cout<<"In-order:\n";
    t.inorderTraversal(t.root);
    cout<<"\nPre-order:\n";
    t.preorderTraversal(t.root);
    cout<<"\nPost-order:\n";
    t.postorderTraversal(t.root);
}