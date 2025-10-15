#include<iostream>
using namespace std;
/*
Reversing a linked list
*/
class Node{
    public: 
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};
class List{
    Node* head;
    public: 
    List(){
        head = NULL;
    }
    void insertFront(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    /*
        Initial: 1->2->3->4
        Reversed: 4->3->2->1
    */
    void reverseList() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;   // Store next node
        curr->next = prev;   // Reverse current node's pointer
        prev = curr;         // Move prev to current node
        curr = next;         // Move to next node
    }
    head = prev; 
}

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" "; temp = temp->next;
        }
    }
};
int main(){
    List list;
    for(int i=10; i<=20; i++){
        list.insertFront(i);
    }
    cout<<"Initial list: ";
    list.display();
    list.reverseList();
    cout<<"\nAfter reversal: ";
    list.display();
}