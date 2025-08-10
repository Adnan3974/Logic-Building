#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *Next;
};

void displayNode(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << "  ";
        n = n->Next;
    }
}

int main()
{
    Node *head = new Node();
    Node *first = new Node();
    Node *second = new Node();

    head->data = 10;
    head->Next = first;
    first->data = 20;
    first->Next = second;
    second->data = 30;
    second->Next = NULL;

    displayNode(head);

    Node *begin = new Node();
    begin->data = 5;
    begin->Next = head;

    cout << "\nAfter inserting 5 in the beginning\n";
    displayNode(begin);

    Node *after_20 = new Node();
    after_20->data = 25;
    after_20->Next = second;
    first->Next = after_20;

    cout << "\nAfter inserting 25\n";
    displayNode(begin);

    Node *temp = first;
    head->Next = after_20;
    delete temp;
    cout << "\nAfter deleting 20\n";
    displayNode(begin);

    delete after_20;
    delete second;
    delete head;
    delete begin;
    return 0;
}