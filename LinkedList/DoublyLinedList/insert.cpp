#include<iostream>
using namespace std;
/*
1. Insert at start.
2. Insert at end.
3. Insert after given value.
4. Delete at start.
5. Delete at end.
6. Delete given value.
*/
class Node{
    public: 
    int data;
    Node* prev;
    Node* next;
    Node(){
        prev = NULL;
        next = NULL;
    }
};
class List{
    Node* head;
    Node* tail;
    public: 
    List(){
        head = NULL;
        tail = NULL;
    }
    void insertAtStart(int val){ 
        Node* newNode = new Node();
        newNode->data = val;
        if(head==NULL && tail==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void  insertAtEnd(int val){
        Node* newNode = new Node();
        newNode->data = val;
        if(head==NULL && tail==NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAfterVal(int target, int val) {
    if (head == NULL) {
        cout << "List is empty, can't search for value!\n";
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value " << target << " not found!\n";
        return;
    }
    Node* insert = new Node();
    insert->data = val;
    insert->next = temp->next;
    insert->prev = temp;
    temp->next = insert;
    if (insert->next != NULL)
        insert->next->prev = insert;
    else
        tail = insert; // inserted at end → update tail
    }

    void deleteAtStart(){
        if(head==NULL && tail==NULL){
            cout<<"List is empty\n";
            return;
        }
        if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
        return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void deleteAtEnd(){
        if(head==NULL && tail==NULL){
            cout<<"List is empty\n";
            return;
        }
        if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
        return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    void deleteNodeByVal(int val){
        if(head==NULL && tail==NULL){
            cout<<"List is empty\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL && temp->data!=val){
            temp = temp->next;
        }
        if(temp == NULL){
            cout<<"Val coudn't be found in the list\n";
            return;
        }
        if(temp->next == NULL){
            tail = temp->prev;
            tail->next = NULL;
            delete temp;
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    List list;
    for(int i=10; i>=1; i--){
        list.insertAtStart(i);
    }
    cout<<"Inserting at start, List: ";
    list.display();
    cout<<"Inserting at end, List: ";
    for(int i=15; i>=11; i--){
        list.insertAtEnd(i);
    }
    list.display();
    cout<<"Inserting at value, List: ";
    list.insertAfterVal(12, 100);
    list.display();
    cout<<"After deleting first 3 elements: ";
    for(int i=0; i<3; ++i){
        list.deleteAtStart();
    }
    list.display();
    cout<<"After deleting last 3 elements: ";
    for(int i=0; i<3; ++i){
        list.deleteAtEnd();
    }
    list.display();
    cout<<"Delete val 7: ";
    list.deleteNodeByVal(7);   
    list.display();
    return 0;
}