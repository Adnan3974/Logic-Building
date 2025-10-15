#include <iostream>
using namespace std;
// Intro to Linked List

class Node
{
public:
    int data;
    Node *Next;
};

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->Next;
    }
}

void insertInFront(Node *&head, int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->Next = head;
    head = newNode;
}

int main()
{
    Node *head = new Node();
    head->data = 10;
    Node *second = new Node();
    second->data = 20;
    Node *third = new Node();
    third->data = 30;
    Node *forth = new Node();
    forth->data = 40;
    Node *fifth = new Node();
    fifth->data = 50;

    head->Next = second;
    second->Next = third;
    third->Next = forth;
    forth->Next = fifth;
    fifth->Next = NULL;

    printList(head);

    // Inserting element in front of lined list
    cout << "\nEnter value of node to insert in front\n";
    int val;
    cin >> val;

    insertInFront(head, val);

    printList(head);

    return 0;
}