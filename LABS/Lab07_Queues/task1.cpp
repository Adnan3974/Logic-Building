#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(){
        next=NULL;
    }
};

class Queue{
    Node* front;
    Node* rear;
    int size;
    public: 
    Queue(){
        front = NULL;
        rear = NULL;
        size = 10; //default size
    }
    void enque(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = front;
        front = newNode;
    }
    void deque(){
        
    }
};
int main(){

    return 0;
}