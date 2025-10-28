#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // Point to itself
        } 
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make it circular
        }
    }
    void removeNode(int value) {
        if (head == nullptr) {
            return;
        }
        
        Node* current = head;
        Node* prev = nullptr;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        if (head->next == head) {
            if (head->data == value) {
                delete head;
                head = nullptr;
            }
            return;
        }
        if (head->data == value) {
            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        prev = head;
        current = head->next;
        
        while (current != head) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    int findMinimum() {
        if (head == nullptr) {
            return -1;
        }
        
        int minSkill = head->data;
        Node* temp = head->next;
        
        while (temp != head) {
            if (temp->data < minSkill) {
                minSkill = temp->data;
            }
            temp = temp->next;
        }
        
        return minSkill;
    }
    int countNodes() {
        if (head == nullptr) {
            return 0;
        }
        
        int count = 1;
        Node* temp = head->next;
        
        while (temp != head) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    Node* movePositions(int M, Node* start) {
        Node* current = start;
        for (int i = 1; i < M; i++) {
            current = current->next;
        }
        return current;
    }
    
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) {
                cout << " -> ";
            }
        } while (temp != head);
        cout << " -> (back to " << head->data << ")" << endl;
    }
    int getWinner() {
        if (head == nullptr) {
            return -1;
        }
        return head->data;
    }
    void findWinner(int M) {
        if (head == nullptr) {
            cout << "List is empty. No winner." << endl;
            return;
        }
        cout << "\n=== Starting Winner Selection Process ===" << endl;
        cout << "Selection interval M = " << M << endl;
        cout << "\nInitial Circle: ";
        display();
        Node* current = head;
        int round = 1;
        while (countNodes() > 1) {
            cout << "\n--- Round " << round << " ---" << endl;
            current = movePositions(M, current);
            cout << "After " << M << " selections, reached person with skill: " << current->data << endl;
            int minSkill = findMinimum();
            cout << "Minimum skill level in current circle: " << minSkill << endl;
            cout << "Eliminating person with skill level: " << minSkill << endl;
            if (current->data == minSkill) {
                current = current->next;
            }
            removeNode(minSkill);
            cout << "Remaining circle: ";
            display();
            round++;
        }
        cout << "\n=== Winner Declared ===" << endl;
        int winner = getWinner();
        if (winner != -1) {
            cout << "The winner has skill level: " << winner << endl;
        }
    }
    ~CircularLinkedList() {
        if (head == nullptr) return;
        
        Node* current = head->next;
        while (current != head) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete head;
    }
};

int main() {
    CircularLinkedList list;
    for(int i=4; i<=11; ++i){
        list.insert(i);
    }
    for(int i=7; i<=17; ++i){
        list.insert(i);
    }
    list.findWinner(3);
    return 0;
}