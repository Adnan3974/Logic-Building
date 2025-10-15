#include<iostream>
using namespace std;
#include<iostream>
using namespace std;

class Node{
public:
    Node *next;
    int data;
};
class List{
    Node *head;
    public:
    List(){
        head = NULL;
    }    
    void insert(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
/*
Input: 1->2->3->4->5->6->7
k=3
Output: 3->2->1->6->5->4->7
*/
void reversesKnodes(int k){
    if(head == NULL || k <= 1) return;
    Node* prev = head;
    Node* endk = NULL;
    Node* khead = NULL;
    while(prev->next!=NULL){
        int  count = 0;
        while(count<k){
            prev = prev->next;
            count++;
        }
        
    }
}

};

int main(){
    List list;
    for (int i = 10; i > 0; i--){
        list.insert(i);
    }
    cout << "Original list: ";
    list.display();
    cout<<"Enter k: ";
    int k; cin>>k;
    list.reversesKnodes(k);
    cout<<"After reversisng k nodes: "; 
    list.display();
    return 0;
}
