#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}
void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
Node* buildFromPrefix(string expr) {
    Node* stack[100];
    int top = -1;
    
    for (int i = expr.length() - 1; i >= 0; i--) {
        char c = expr[i];
        if (c == ' ') continue;
        
        if (isDigit(c)) {
            stack[++top] = new Node(c);
        } else if (isOperator(c)) {
            Node* node = new Node(c);
            node->left = stack[top--];
            node->right = stack[top--];
            stack[++top] = node;
        }
    }   
    return stack[top];
}

int main() {
    string expr;
    cout << "Enter prefix expression (space separated): ";
    getline(cin, expr);
    Node* tree = buildFromPrefix(expr);
    cout << "\nPrefix: "; 
    preOrder(tree); 
    cout << "\n";
    cout << "Postfix: "; 
    postOrder(tree); 
    cout << "\n";
    return 0;
}