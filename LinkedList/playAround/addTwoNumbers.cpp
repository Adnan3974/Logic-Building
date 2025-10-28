#include<iostream>
using namespace std;
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in
reverse order, and each of their nodes contain a single digit. Add the two numbers and return the sum as a
linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Input: L1 = [2,4,3], L2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:
Input: L1 = [0], L2 = [0]
Output: [0]
Example 3:
Input: L1 = [9,9,9,9,9,9,9], L2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
struct Node{
    int data;
    Node* next;
    Node(): next(nullptr){};
};
class List{
    public:
    Node* head;
    List():head(nullptr){};
    void insertLast(int val){
        Node* n = new Node();
        n->data = val;
        if(head == nullptr){
            head = n; return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = n;
    }
    void display(Node* temp){
        while(temp!=nullptr){
            cout<<temp->data<<" "; temp = temp->next;
        }cout<<endl;
        delete temp;
    }
};
void add(Node* n1, Node* n2){
    int carry = 0; 
    Node* result = nullptr; 
    Node* curr = nullptr;
    while(n1!=nullptr || n2!=nullptr || carry!=0){
        int sum = carry;
        if(n1!=nullptr){
            sum+=n1->data; n1 = n1->next;
        }
        if(n2!=nullptr){
            sum+=n2->data; n2 = n2->next;
        }
        Node* newNode = new Node();
        newNode->data = sum % 10;
        carry = sum / 10;
        if(result == nullptr){
            result = newNode;
            curr = newNode;
        }
        else{
            curr->next = newNode;
            curr = curr->next;
        }
    }
    List res;
    res.display(result);
}
int main(){
    List l1,l2;
    for(int i=0; i<7; ++i){
        l1.insertLast(9);
    }
    l1.display(l1.head);
    for(int i=0; i<4; ++i){
        l2.insertLast(9);
    }
    l2.display(l2.head);
    add(l1.head,l2.head);
    return 0;
}