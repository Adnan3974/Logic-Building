#include<iostream>
using namespace std;

class Node{
    public: 
    char data;
    Node* next;
    Node(){
        next=NULL;
    }
};

class Stack{
    Node* top;
    public: 
    Stack(){
        top=NULL;
    }
    void push(char val){
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=top;
        top=newNode;
    }
    void removeKdigits(int k, int length){
        if(k<=0) return; //nothing to remove
        if(k>=length){ //all to remove
            while(top!=NULL){
                Node* temp=top;
                top=top->next;
                delete temp; 
            }
            return;
        }
        while(k>0 && top!=NULL){
            Node* temp=top;
            Node* maxNode=top;
            while(temp!=NULL && temp->next!=NULL){
                if(temp->next->data > maxNode->data){
                    maxNode = temp->next;
                }
                temp=temp->next;
            }
            if(maxNode == top){
                top = top->next;
                delete maxNode;
            } else {
                Node* temp2=top;
                while(temp2!=NULL && temp2->next!=maxNode){
                    temp2 = temp2->next;
                }
                if(temp2!=NULL){
                    temp2->next=maxNode->next;
                    delete maxNode;
                }
            }
            k--;
        }
    }
    void display(){
        Node* temp=top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

};

int main(){
    Stack stack;
    cout<<"Enter number: ";
    string n; cin>>n;
    for(int i=0; i<n.length(); ++i){
        stack.push(n[i]);
    }
    cout<<"Initial number: "; stack.display();
    cout<<"\nEnter k: ";
    int k; cin>>k;
    stack.removeKdigits(k, n.length());
    cout<<"After removing k digits: \n"; stack.display();
}
