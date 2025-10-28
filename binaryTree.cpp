#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    public:
    Node(){
        left = right = nullptr;
    }
};
class binaryTree{
    public: 
    Node* root;
    binaryTree(){
        root = nullptr;
    }
    void insert(int val){
        Node* newNode = new Node();
        newNode->data = val;
        if(root == nullptr){
            root = newNode; return;
        }
        if(newNode->data < root->data){
            root->left = newNode;
            return;
        }
        if(newNode->data > root->data){
            root->right = newNode;
            return;
        }
    }
};
void inorder(Node* node){
        if(node == nullptr){
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);    
    }

int main(){
    binaryTree bt;
    bt.insert(3);
    bt.insert(7);
    bt.insert(2);
    bt.insert(8);
    bt.insert(3);
    bt.insert(9);
    bt.insert(5);
    bt.insert(1);
    inorder(bt.root);
}