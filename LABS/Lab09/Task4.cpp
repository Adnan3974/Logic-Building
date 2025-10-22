#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
int getMaxSumUtil(Node* node) {
    if (node == NULL) return 0;

    int includeNode = node->data;

    if (node->left != NULL) {
        includeNode += getMaxSumUtil(node->left->left) +
                       getMaxSumUtil(node->left->right);
    }

    if (node->right != NULL) {
        includeNode += getMaxSumUtil(node->right->left) +
                       getMaxSumUtil(node->right->right);
    }
    int excludeNode = getMaxSumUtil(node->left) + 
                      getMaxSumUtil(node->right);
    return max(includeNode, excludeNode);
}

int getMaxSum(Node* root) {
    if (root == NULL) return 0;
    return getMaxSumUtil(root);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);
    cout << getMaxSum(root) << endl;
    return 0;
}