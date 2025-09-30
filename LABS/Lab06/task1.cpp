#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};

class List{
    public:
    Node* head; 
    List(){
        head = NULL;
    }

    void push(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next=head;
        head = newNode;
        }
    
        void display(){
        Node* temp =  head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    void swaping(Node* node1, Node* node2){
        if(head==NULL){
            cout<<"List is empty!";
            return;
        }        
        if(node1==NULL || node2==NULL){ //end of list reached
        return;
        }
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
        
        if (node2->next != NULL && node2->next->next != NULL) {
        swaping(node2->next, node2->next->next);
        }
    }
};

int main(){
    List list;
    for(int i=1; i<=10; i++){
        list.push(i);
    }
    cout<<"Initial List: \n";list.display();
    list.swaping(list.head,list.head->next);
    cout<<"\nAfter swapinig: \n"; list.display();
    return 0;
}