#include <iostream>
using namespace std;
/*
1->9->6->1->2->0->5->3->nullptr
x = 3
1->1->2->0->3->9->6->5->nullptr
*/
class Node{
public:
    int data;
    Node *next;
    Node(){
        next = nullptr;
    }
};
class List{
    Node* head;
    List(){
        head = nullptr;
    }
    void insertFront(int val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    }
    void partition(int x){
        if(head == nullptr){
            cout<<"List empty!\n"; return;
        }
        Node* temp = head;
        while(temp->next != nullptr){
            if(temp->data <= x){
                temp = temp->next;
            }
            else{
                Node* temp2 = temp;
            }
        }
    }
};
int main(){
    int val = 0;
    cout << "Enter elements in the linked list and -999 to stop adding elements: ";
    Node *head = NULL;
    Node *tail = NULL;

    while (true)
    {
        cin >> val;
        if (val == -999)
            break;

        Node *newNode = createNode(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "Enter  X: ";
    int x;
    cin >> x;
    


    return 0;
}


















