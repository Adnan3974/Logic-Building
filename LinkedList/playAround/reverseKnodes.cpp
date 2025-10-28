#include<iostream>
using namespace std;
/*
Problem Statement
You are given a singly linked list and an integer. Write a function to reverse the nodes of the list k at a k time and
return its modified list. If the number of nodes is not a multiple of, then left-out nodes at k the end should remain as
they are.
Requirements
• You cannot alter the values in the nodes, only the nodes themselves may be changed.
• Do not use any extra memory (i.e., no arrays, no copying data, etc.), you must change the pointers in the
linked list itself.
Example
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For
k=2, you should return: 2 -> 1 -> 4 -> 3 -> 5
For
k=3, you should return: 3 -> 2 -> 1 -> 4 -> 5
*/
struct Node{
    int data;
    Node* next; 
    Node():next(nullptr){};
};
class List{
    Node* head; 
    public: 
    List(): head(nullptr){};
    void insertFront(int val){
        Node* n = new Node();
        n->data = val;
        if(head == nullptr){
            head = n; return;
        }
        n->next = head;
        head = n;
    }
    void reverse(int k){
        if(k<=1 || head == nullptr){
            return;
        }
        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;
        while(curr != nullptr){
            Node* nextNode = nullptr;
            Node* prevNode = nullptr;
            Node* groupHead = curr;
            int count = 0;
                while(count<k && curr!=nullptr){
                nextNode = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = nextNode; 
                count++;
                }
        if(newHead == nullptr){
        newHead = prevNode;
        }
        if(tail != nullptr){
        tail->next = prevNode;
        }
        tail = groupHead;
        }
        head = newHead;
    }
    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
        delete temp;
    }
};
int main(){
    List list;
    for(int i=1; i<=10; ++i){
        list.insertFront(i);
    }
    list.display();
    list.reverse(3);
    list.display();
    return 0;
}