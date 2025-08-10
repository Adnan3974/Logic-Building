#include <iostream>
using namespace std;

class Node
{
public:
    double data;
    Node *next;
};

void Traverse(Node *);
int NodesCount(Node *);
void InsertOnHead(Node *&, int);
void InsertOnPosition(Node *&, int, int);
void DeleteFromBeginning(Node*&);
void deleteByData(Node *&,int);
void reverseList(Node*&);

int main()
{

    typedef Node *ptr;

    ptr head = new Node();
    ptr one = new Node();
    ptr two = new Node();
    ptr three = new Node();
    ptr four = new Node();
    ptr five = new Node();
    ptr six = new Node();
    ptr seven = new Node();

    head->data = 5.0;
    one->data = 10.0;
    two->data = 15.0;
    three->data = 20.0;
    four->data = 25.0;
    five->data = 30.0;
    six->data = 35.0;
    seven->data = 40.0;

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = five;
    five->next = six;
    six->next = seven;
    seven->next = NULL;

    cout << "==== Traversing Linked List ==== \n\n";
    Traverse(head);

    cout << "\n\n==== Nodes Count ====\n\n";
    cout << "No. of nodes: ";
    cout << NodesCount(head);

    cout << "\n\n==== Inserting node on head ====\n\n";
    cout << "Enter value of the node to insert in the beginning: ";
    int val;
    cin >> val;
    InsertOnHead(head, val);

    cout << "List after Insersion: ";
    Traverse(head);

    cout << "\n\n====Inserting node at given position ====\n\n";
    cout << "Enter position: ";
    int position;
    cin >> position;
    cout << "Enter value: ";
    cin >> val;
    InsertOnPosition(head, position, val);
    cout << "After inserstion: ";
    Traverse(head);
    
    cout<<"\n\n==== Deleting from the beginning ====\n\n";
    DeleteFromBeginning(head);
    cout<<"After deletion: ";
    Traverse(head);
    
    cout<<"\n\n==== Deleting by data ====\n\n";
    cout<<"Enter value\n";
    cin>>val;
    deleteByData(head,val);
    cout<<"After Deletion\n";
    Traverse(head);
    
    cout<<"\n\nReverse List\n\n";
    reverseList(head);
    Traverse(head);
    return 0;
}

void reverseList(Node *&head){
Node* prev=NULL;
Node* curr=head;
Node* Next;
while(curr!=NULL){
Next=curr->next;
curr->next=prev;
prev=curr;
curr=Next;
}
head=prev;
}

void deleteByData(Node *&head,int val){
//If no element in the list
if(head==NULL){
cout<<"Empty list";
return;
}
//If only head element in the list
if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
Node* current=head;
Node* prev=NULL;

while(current!=NULL && current->data!=val){
prev=current;
current=current->next;
}

if (current == NULL) {
        cout << "Invalid value" << endl;
        return;
    }
    
	prev->next = current->next;
	delete current;

}

void DeleteFromBeginning(Node *&head){
	if(head==NULL)
	return;
	Node* temp=head;
	head=head->next;
	delete temp;
}

void InsertOnPosition(Node *&head, int position, int val)
{
    if (position < 0)
        return;

    Node *newNode = new Node();
    newNode->data = val;

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

Node* current=head;
    for(int i=1; i<position-1; ++i){
    current=current->next;
    }
    if(current==NULL)
    return;
    /*
    1->2->3->4->5
    let given position be 3 with value 7
    which is b/w 2 and 3
    current* points to 2 (one less than position) and 
    before updating next* of current
    newNode->next=current->next (current next is pointer to 3)
    current->next=newNode; Now current is updated to point to the new Node
    so updated list is 1->2->7->3->4->5
    1->
    */
    newNode->next=current->next; 
    current->next=newNode;
    }


void Traverse(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int NodesCount(Node *n)
{
    int count = 0;
    while (n != NULL)
    {
        count++;
        n = n->next;
    }
    return count;
}

void InsertOnHead(Node *&head, int val) // Always pass by reference to show changes in the main
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = head; // Currently newNode is the head and head has become the second element
    head = newNode;       // Updated head which has again become the first element
}
