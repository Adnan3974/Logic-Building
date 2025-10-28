#include<iostream>
using namespace std;

class Node{
    public: 
    Node* next;
    int data;
    Node(int d=0): data(d){
        next=NULL;
    }
};
class List{
    Node* head;
    public:
    List(){
        head=NULL;
    }  
    void insertLast(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(head==NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;        
    }
/*
1->2->3->4->5
2->1->4->3->5
curr = 1;
curr = curr->next;

*/
    void swapAdjacentNodes() {
    if (head == nullptr || head->next == nullptr) return;
    Node* prev = nullptr;
    Node* curr = head;
    head = curr->next;  
    while (curr != nullptr && curr->next != nullptr) {
        Node* Next = curr->next;
        curr->next = Next->next;
        Next->next = curr;
        if (prev != nullptr)
            prev->next = Next;
        prev = curr;
        curr = curr->next;
    }
    }

    void display(){
        Node* temp = head;
        if(temp==NULL){
            cout<<"Nothing to display!";
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
        delete temp;
    }
};

int  main(){
    List list;
    for(int i=1; i<=10; ++i){
        list.insertLast(i);
    }
    cout<<"Initial list: ";
    list.display();
    list.swapAdjacentNodes();
    cout<<"After swapping: ";
    list.display();
    return 0;
}

/*
This program inserts a node at the given position
*/