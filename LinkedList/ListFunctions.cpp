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
    
    void insertFront(int value){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertLast(int value){
        Node* newNode = new Node();
        newNode->data = value;
        if(head==NULL){
            newNode->next=NULL;
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;        
    }

    void insertAtPosition(int pos, int val){        
        Node* newNode = new Node();
        newNode->data = val;
        if(head == NULL){
            if(pos == 1){
                newNode->next=NULL;
                head = newNode;
                return;
            }
            else{
                cout<<"Position exceeds the list length!\n";
                delete newNode;
                return;
            }
        }
//calling insertFront() if position is 1
        if(pos==1){
            insertFront(val);
        }
//1 2 3 4 5 6 7
        int i=1;
        Node* temp = head;
        while(i<pos-1 && temp!=NULL){
            temp = temp->next;
            i++;
        }
        if(temp == NULL){
            delete newNode;
            cout<<"Position exceeds the list length!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        if(temp==NULL){
            cout<<"Nothing to display!";
        }
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int  main(){
    List list;
    for(int i=1; i<10; ++i){
        list.insertFront(i);
    }
    
    list.display();
    
    for(int i = 9; i>0; --i){
        list.insertLast(i);
    }
    list.display();
    cout<<"\nEnter position: ";
    int pos;
    cin>>pos;
    
    while(pos<=0){
            cout<<"Invalid position! Re-Enter: \n";
            cin>>pos;
    }
    cout<<"Enter value: ";
    int value;
    cin>>value;

    list.insertAtPosition(pos,value);
    cout<<"After Inserting a Node at "<<pos<<"\n";
    list.display();
    return 0;
}

