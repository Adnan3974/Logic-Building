#include<iostream>
using namespace std;

class Node{
    public: 
    Node* next;
    char data;
    Node(){
        next = NULL;
    }
};

class Stack{
    Node* top;
    public: 
    bool isEmpty(){
        return top == NULL;
    }
    Node* newNode = new Node();
    void  push(char ch){
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }
    char pop(){
        Node* temp = top;
        char ch;
        ch = temp->data;
        top = top->next;
        delete temp;
        return ch;
    }
};
//1 2 3
/*
A+B*C = BCA*+
*/
int main(){
    Stack stack1, stack2;
    cout<<"Enter infix string: ";
    string infix;
    cin>>infix;
    int i=0;
    while(i<infix.length()){
        if((infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '%')){
        stack1.push(infix[i]);
        }
        else{
            stack2.push(infix[i]);
        }
    }
    i=0;
    string result;
    while(!stack2.isEmpty()){
        result[i] = stack2.pop();
    }
    while(!stack1.isEmpty()){
        while(stack1.pop() == '+' || stack1.pop() == '-'){
        result[i]=stack1.pop();
        i++;    
    }
    while(stack1.pop() == '*' || stack1.pop() == '/' || stack1.pop() == '%'){
        result[i]=stack1.pop();        
        i++;
    }
    }
    cout<<"\n"<<result;
    return 0;
}
