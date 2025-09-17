#include<iostream>
using namespace std;

class StackNode {
public:
    StackNode *next;
    char data;
    StackNode() {
        next = NULL;
    }
};

class Stack {
    StackNode *top;
public:
    Stack() {
        top = NULL;
    }
    
    bool isEmpty() {
        return top == NULL;
    }
    
    void push(char ch) {
        StackNode *newNode = new StackNode();
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }
    
    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        StackNode *temp = top;
        char ch = temp->data;
        top = top->next;
        delete temp;
        return ch;
    }
};

int main() {
    Stack stack1, stack2;
    string str;
    
    cout << "Enter string to reverse: ";
    getline(cin, str);
    
    for (int i = 0; i < str.length(); i++) {
        stack1.push(str[i]);
    }
    
    while (!stack1.isEmpty()) {
        stack2.push(stack1.pop());
    }
    
    while (!stack2.isEmpty()) {
        stack1.push(stack2.pop());
    }

    cout << "Reversed string: ";
    while (!stack1.isEmpty()) {
        cout << stack1.pop();
    }
    cout << endl;
    
    return 0;
}