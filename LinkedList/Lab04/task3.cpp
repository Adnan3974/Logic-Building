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
    
    int countNodes(Node* start){
        int count = 0;
        while(start != NULL){
            count++;
            start = start->next;
        }
        return count;
    }
    
    Node* reverseGroup(Node* start, int k){
        Node* prev = NULL;
        Node* current = start;
        Node* next = NULL;
        
        for(int i = 0; i < k && current != NULL; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        if(start != NULL){
            start->next = current;
        }
        
        return prev;
    }
    
    void reverseKNodes(int k){
        if(k <= 1 || head == NULL){
            cout << "Sorry! Nothing to reverse!" << endl;
            return;
        }
        
        Node* current = head;
        Node* prevGroupTail = NULL;
        bool isFirstGroup = true;
        
        while(current != NULL){
            Node* temp = current;
            int availableNodes = 0;
            
            for(int i = 0; i < k && temp != NULL; i++){
                temp = temp->next;
                availableNodes++;
            }
            
            if(availableNodes < k){
                break;
            }
            
            Node* currentGroupHead = current;
            
            for(int i = 0; i < k; i++){
                current = current->next;
            }
            
            Node* newGroupHead = reverseGroup(currentGroupHead, k);
            
            if(isFirstGroup){
                head = newGroupHead;
                isFirstGroup = false;
            } else {
                prevGroupTail->next = newGroupHead;
            }
            
            prevGroupTail = currentGroupHead;
        }
    }
    
private:
    Node* reverseKHelper(Node* head, int k){
        if(head == NULL) return NULL;
        
        Node* temp = head;
        for(int i = 0; i < k; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }
        
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        
        for(int i = 0; i < k && current != NULL; i++){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        if(next != NULL){
            head->next = reverseKHelper(next, k);
        }
        
        return prev; 
    }
};

int main()
{
    List list;
    
    for (int i = 10; i > 0; i--){
        list.insert(i);
    }
    
    cout << "Original list: ";
    list.display();
    
    cout << "Reversing every 3 nodes: ";
    list.reverseKNodes(3);
    list.display();
    
    List list2;
    for(int i = 5; i > 0; i--){
        list2.insert(i);
    }
    
    cout << "\nNew list: ";
    list2.display();
    
    cout << "Reversing every 2 nodes: ";
    list2.reverseKNodes(2);
    list2.display();
    
    return 0;
}
