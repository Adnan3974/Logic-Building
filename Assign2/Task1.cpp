#include<iostream>
using namespace std;
/*
Stack, Queue, 
*/
struct Node{
    string str;
    Node* next;
    Node():next(nullptr){};
};
class Stack{
    Node* top;
    public:
    Stack():top(nullptr){};
    void push(string s){
        Node* newNode = new Node();
        newNode->str = s;
        newNode->next = top;
        top = newNode;
    }
    string pop(){
        Node* temp = top; 
        string res; res = top->str;
        top = top->next;
        delete top; top = nullptr;
        return res;
    }
    void display(){
        Node* temp = top;
        while(temp!=nullptr){

        }
    }
};
class Queue{
    Node* front;
    Node* rear;
    public: 
    Queue():front(nullptr), rear(nullptr){};
    void enque(string fun){
        Node* queNode = new Node();
        queNode->str = fun;
        if(front == nullptr && rear==nullptr){
            front = queNode;
            rear = queNode;
        }
        else{
            rear->next = queNode;
            rear = queNode;
        }
    }
    string deque(){
        string res;
        Node* temp = front;
        if(front==nullptr){
            delete temp; res = "";
        }
        else{
            res = front->str;
            front = front->next;
            delete temp;
        }
        return res;
    }
};
int main(){
    cout<<"Enter function: ";
    string fun; getline(cin,fun);
    //Input validation
    while((fun[0]<65 && fun[0]>90) || (fun[0]<97 && fun[0]>122) || fun[0]!=95){
        cout<<"Function name must begin with letters a-z or underscore(_).";
        char ch; cin>>ch; fun[0]=ch;
    }

    return 0;
}