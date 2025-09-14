#include<iostream>
using namespace std;
//Stack implementation using arrays

class Stack{
    int *stackArray;
    int size;
    int top;
    public:
    Stack(int  s){
        stackArray = new int[s];
        size = s;
        top = -1;
    } 
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == size-1;
    }
    void push(int x){
        if(isFull()){
            cout<<"Stack is full";
            return;
        }
        top++;
        stackArray[top] = x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack empty";
            return -1;
        }
        int v=-1;
        v = stackArray[top];
        top--;
        return v;
    }
    void display(){
    for(int i=0; i<top; ++i){
        cout<<stackArray[i]<<" ";
    }
}
};

int main(){
    Stack stack(10);
    for(int i=0; i<8; ++i){
        stack.push(i+12);
    }
    stack.display();
    cout<<"\nAfter popping elements: \n";
    for(int i=0; i<4; ++i){
        stack.pop();
    }
    stack.display();
}