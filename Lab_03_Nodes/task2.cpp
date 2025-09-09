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
        newNode->next=head;
        head=newNode;
    }

    void display(){
        Node *temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void function(int n){
        if(n<=1){
            cout << "Kidding! nothing to change.";
            return;
        }
        Node *temp = head;
        while (n > 1 && temp->next!=NULL)
        {
            temp = temp->next;
        }
    }
};

int main()
{
    List list;
    for (int i = 10; i > 0; i--){
        list.insert(i);
    }
    list.display();


    return 0;
}