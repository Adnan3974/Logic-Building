#include<iostream>
using namespace std;

class Node{
    public:
    Node *next;
    int data;
    Node(){
        next = NULL;
    }
};

class Str{
public:
    Str *next;
    char data;
    Str(){
        next = NULL;
    }
};

class Stack
{
    Node *top;
    Str *strTop;

public:
    Stack(){
        top = NULL;
        strTop = NULL;
    }
    bool isEmpty(){
        return (top == NULL);
    }
    bool isEmptyStr(){
        return strTop == NULL;
    }
    void push(int val){
        Node *newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    void push(char ch){
        Str *newNode = new Str();
        newNode->data = ch;
        newNode->next = strTop;
        strTop = newNode;
    }
    char popStr(){
        Str *temp = strTop;
        char ch;
        ch = temp->data;
        strTop = strTop->next;
        delete temp;
        return ch;
    }
    int pop(){
        Node *temp = top;
        int v;
        v = temp->data;
        top = top->next;
        delete temp;
        return v;
    }
    void display(){
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    bool isValid(string str){
        int i = 0;
        if(str.empty()){
            cout << "String can't be empty!";
            return false;
        }
        while (i < str.length())
        {
            if(str[i] == '{' || str[i] == '(' || str[i] == '['){
                push(str[i]);
            }

            else if(str[i] == '}'){
                if(isEmptyStr() || popStr() != '{'){
                    return false;
                }
            }
            if(str[i] == ')'){
                if(isEmptyStr() || popStr() != '(')
                    return false;
            }
            if(str[i] == ']'){
                if(isEmptyStr() || popStr() != '[')
                    return false;
            }
        i++;
        }
        return isEmptyStr();
    }
};
int main()
{
    Stack stack;
    for (int i = 1; i < 11; ++i){
        stack.push(i + 5);
    }
    cout << "Initial Stack\n";
    stack.display();
    cout << "\nAfter callng pop 5 times: \n";
    for (int i = 0; i < 5; ++i){
        stack.pop();
    }
    stack.display();

    string str;
    cout << "Enter parenthesis to verify: ";
    cin >> str;
    if(stack.isValid(str))
        cout << "Valid";
    else
        cout << "Not Valid";
    return 0;
}

/*
1. string is Palindrome
*/