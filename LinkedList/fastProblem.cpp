#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *createNode(int val)
{
    Node *n = new Node();
    n->data = val;
    n->next = NULL;
    return n;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

/*

*/
void getPartitionedList(Node *head, int x){

if(head==NULL)
return;

if(head->next==NULL && x!=head->data){
cout<<"Invalid X";
return;
}

if(head->next==NULL)
return;

typedef Node* ptr;
ptr curr=new Node();
ptr Next=new Node();

curr=head;
while(curr!=NULL){
if(curr->data<=x)
continue;

}
}

int main()
{

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


















