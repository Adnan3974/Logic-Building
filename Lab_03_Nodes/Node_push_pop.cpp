#include<iostream>
using namespace std;

class Node{
    public: 
    Node* next;
    int data;
    Node(int d=0) : data(d){
        next=NULL;
    }
};

class List{
    Node* head;
    public: 
    List(){
        head=NULL;
    }
    void insertStart(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
        head = newNode;
        }
        
        else{
        newNode->next=head;
        head=newNode;
        }        
    }

    void insertEnd(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
        head = newNode;
        }
        
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void display(){
        if(head==NULL){
            cout<<"List is empty\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next; 
        }
    }

    void deleteStart(){
        if(head==NULL){
            cout<<"Nothing to delete!";
            return;
        }
        Node* first = head;
        head = head->next;
        delete first;
    }

    void deleteLast(){
        if(head==NULL){
            cout<<"Nothing to delete!";
            return;
        }
        if(head->next=NULL){
            delete head;
            head=NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }

    void searchByValue(int val){
        if(head==NULL){
            cout << "The list is empty!";
            return;
        }

        Node *newNode = head;
        int pos = 0;
        while (newNode != NULL && newNode->data != val)
        {
            newNode = newNode->next;
            pos++;
        }

        if(newNode==NULL){
            cout << "Couldn't find a match for this value.\n";
            return;
        }
        cout << "Node found on position: " << pos<<"\n";
    }


};

int main(){
    List list;
    
    // Inserting elements in the beginning
    for(int i=10; i>0; i--){
    list.insertStart(i);   
    } 

    cout<<"Initial List: \n";
    list.display();
    
    // Inserting elemets at the end
    for(int j=11; j<21; ++j){
    list.insertEnd(j);   
    }

    cout<<"\nAfter inserting elements in the end: \n";
    list.display();

    //1. Deleting element from the start
    list.deleteStart();
    cout<<"\nAfter deleting one element from the start: \n";
    list.display();
    //Repetitive deletion
    for(int i=0; i<9; ++i){
    list.deleteStart();
    }
    cout<<"\nAfter deleting n elements from the start: \n";
    list.display();

    //2. Delete element from the last
    list.deleteLast();
    cout<<"\nAfter deleting element from the last: \n";
    list.display();

    cout << "Enter value to search in the list: ";
    int target;
    cin >> target;
    list.searchByValue(target);

    return 0;
    cout << "Something terrible has done";
}

/*
1. Delete element from the start
2. Delete element from the last
3. Searching List by value
4. Deleting particular element
5. Array of lists
6. List of Lists
*/