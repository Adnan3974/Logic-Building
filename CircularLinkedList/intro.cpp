#include<iostream>
using namespace std;
/*
Circular singly linked list
*/
struct Node{
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};
class cList{
    Node* tail;
    public: 
    cList(){
        tail = NULL;
    }
    void insertAtStart(int val){
        Node* newNode = new Node();
        newNode->data = val;
        if(tail == NULL){
            tail = newNode;
            tail->next = newNode;
        }
        else{
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
    void deleteAtStart(){
        Node* temp = tail->next;
        tail->next = temp->next;
        delete temp; temp = nullptr;
    }
/*
1. Reversing the clist using traversal.
2. Reversing the clist using recursion.
*/
    void reverse(){
        Node* temp = tail;
    }
    void display(){
        if (tail == NULL) return;
        Node* temp = tail->next;
        do {
            cout<<temp->data<<" ";
            temp = temp->next;
        } while(temp != tail->next);
        cout<<endl;
        delete temp; temp = nullptr;
    }
};

int main(){
    cList list;
    for(int i=34; i<54; i++){
        list.insertAtStart(i);
    }
    list.display();

    return 0;
}