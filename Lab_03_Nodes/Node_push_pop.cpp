// #include<iostream>
// using namespace std;

// struct Employee{
//     int ID;
//     string Name;
//     string CNIC;
//     int Salery;
//     Employee(int i=0, string n="", string c="", int s=0){
//         ID = i;
//         Name = n;
//         CNIC = c;
//         Salery = s;
//     }
// };

// struct Student{
//     int ID;
//     string Name;
//     string CNIC;
//     int Class;
//     Student(int i=0, string n="", string c="", int s=0){
//         ID = i;
//         Name = n;
//         CNIC = c;
//         Class = s;
//     }
// };

// class Node{
//     public: 
//     Node* next;
//     Employee *emp;
//     Student *stu;
//     int count;    
//     Node(int c = 0) : count(c)
//     {
//         next=NULL;
//     }
// };

// class List
// {
//     Node* head;
//     public: 
//     List(){
//         head=NULL;
//     }
    
//     void insertStart(Employee* e, Student* s){
//         if (head->count >= 10)
//         {
//             cout << "The list is already full";
//             return;
//         }

//         Node* newNode = new Node();
//         head->count++;
        
//         if(head->count%2==0){
//             newNode->emp = e;
//             newNode->stu = NULL;
//         }
//         else if (head->count%2!=0){
//             newNode->stu = s;
//             newNode->emp = NULL;
//         }

//         if (head == NULL)
//         {
//             head = newNode;
//         }

//         else{
//         newNode->next=head;
//         head=newNode;
//         }        
//     }

//     void insertEnd(Employee* e, Student* s){
//         Node* newNode = new Node();
//         head->count++;
//         if(head->count%2==0){
//             newNode->emp = e;
//             newNode->stu = NULL;
//         }
//         else if(head->count%2!=0){
//             newNode->stu = s;
//             newNode->emp = NULL;
//         }

//         if (head == NULL)
//         {
//             head = newNode;
//         }

//         else{
//             Node* temp = head;
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->next = newNode;
//         }
//     }
    
//     void display(){
//         if(head==NULL){
//             cout<<"List is empty\n";
//             return;
//         }
        
//         Node* temp = head;
//         if(head->count%2==0){
//             while(temp!=NULL){
//                 cout << temp->emp->Name << "\n"
//                 << temp->emp->CNIC << "\n"
//                 << temp->emp->ID << "\n"                     
//                 << temp->emp->Salery << "\n";
//                 temp = temp->next;
//         }
//         }
//     }

//     void insertByValue(Employee* e, Student* s){
//         if(head==NULL){
//             cout << "The list is empty!";
//             return;
//         }
//         if(head->count>=10){
//             cout << "The list is already Full!";
//             return;
//         }

//         Node *temp = head;
//         Node *newNode = new Node();
//         head->count++;
//         if (head->count % 2 == 0)
//         {
//             newNode->emp = e;
//             newNode->stu = NULL;
//         }
//         else if(head->count % 2 != 0){
//             newNode->stu = s;
//             newNode->emp = NULL;
//         }

//         if(head->count%2==0){
//             while (temp->next != NULL && temp->emp->ID!=e->ID)
//         {
//             temp = temp->next;
//         }

//         if(temp->next==NULL && temp->emp->ID==e->ID){
//             temp->next = newNode;
//             return;
//         }

//         if(temp->next==NULL && temp->emp->ID!=e->ID){
//             cout << "No match found";
//             return;
//         }
//         newNode->next = temp->next;
//         temp->next = newNode;
//         }
        
//         if(head->count%2!=0){
//             while (temp->next != NULL && temp->stu->ID!=s->ID)
//         {
//             temp = temp->next;
//         }

//         if(temp->next==NULL && temp->stu->ID==s->ID){
//             temp->next = newNode;
//             return;
//         }

//         if(temp->next==NULL && temp->stu->ID!=s->ID){
//             cout << "No match found";
//             return;
//         }
//         newNode->next = temp->next;
//         temp->next = newNode;
//         }
        
        
//     }
// };

// int main(){
//     List list;
//     Student stu1(1234,"temp1", "987234098", 4), stu2(4324, "temp2", "98734289", 5), stu3(5345, "temp3", "5098734258", 6), stu4(5378, "temp4", "50734258", 7), stu5(5095, "temp5", "50987348", 9);
    
//     Employee emp1(1233454, "temporary1", "988934798", 49083745), emp2(4453454, "temporary2", "98askdjf89", 9034986), emp3(53434555, "temporary3", "50sdkfj;58", 9689568), emp4(53789035, "temporary4", "507342;laskdj58", 9043867), emp5(5098495, "temporary5", "50ksdjfsdfh348", 3049875);

//     list.insertStart(&emp1, &stu1);     
//     list.insertEnd(&emp2, &stu2);       
//     list.insertByValue(&emp3, &stu3);
//     list.display();
//     return 0;
// }

#include<iostream>
using namespace std;

struct Employee{
    int ID;
    string Name;
    string CNIC;
    int Salary;
    Employee(int i=0, string n="", string c="", int s=0){
        ID = i;
        Name = n;
        CNIC = c;
        Salary = s;
    }
};

struct Student{
    int ID;
    string Name;
    string CNIC;
    int Class;
    Student(int i=0, string n="", string c="", int s=0){
        ID = i;
        Name = n;
        CNIC = c;
        Class = s;
    }
};

class Node{
    public: 
    Node* next;
    Employee *emp;
    Student *stu;
    
    Node(Employee* e = nullptr, Student* s = nullptr) {
        next = nullptr;
        emp = e;
        stu = s;
    }
};

class List {
    Node* head;
    int count;
    
    public: 
    List() {
        head = nullptr;
        count = 0;
    }
    
    bool isFull() {
        return count >= 10;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    void insertStart(Employee* e, Student* s) {
        if (isFull()) {
            cout << "List is full! Cannot insert more elements.\n";
            return;
        }
        
        Node* newNode;
        if (count % 2 == 0) { 
            newNode = new Node(e, nullptr);
        } 
        else { 
            newNode = new Node(nullptr, s);
        }
        
        count++;
        
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    
    void insertEnd(Employee* e, Student* s) {
        if (isFull()) {
            cout << "List is full! Cannot insert more elements.\n";
            return;
        }
        
        Node* newNode;
        if (count % 2 == 0) { 
            newNode = new Node(e, nullptr);
        } 
        else { 
            newNode = new Node(nullptr, s);
        }
        
        count++;
        
        if (head == nullptr) {
            head = newNode;
        } 
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void insertAfterValue(Employee* e, Student* s, int targetID) {
        if (isFull()) {
            cout << "List is full! Cannot insert more elements.\n";
            return;
        }
        
        if (isEmpty()) {
            cout << "List is empty! Cannot insert after value.\n";
            return;
        }
        
        Node* temp = head;
        bool found = false;
        
        while (temp != nullptr) {
            if ((temp->emp != nullptr && temp->emp->ID == targetID) || 
                (temp->stu != nullptr && temp->stu->ID == targetID)) {
                found = true;
                break;
            }
            temp = temp->next;
        }
        
        if (!found) {
            cout << "Value " << targetID << " not found in the list!\n";
            return;
        }
        
        Node* newNode;
        if (count % 2 == 0) { 
            newNode = new Node(e, nullptr);
        } 
        else { 
            newNode = new Node(nullptr, s);
        }
        
        count++;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void deleteNode(int targetID) {
        if (isEmpty()) {
            cout << "List is empty! Cannot delete.\n";
            return;
        }
        
        Node* temp = head;
        Node* prev = nullptr;
        bool found = false;
        
        if ((head->emp != nullptr && head->emp->ID == targetID) || 
            (head->stu != nullptr && head->stu->ID == targetID)) {
            head = head->next;
            delete temp;
            count--;
            cout << "Node with ID " << targetID << " deleted successfully.\n";
            return;
        }
        
        while (temp != nullptr) {
            if ((temp->emp != nullptr && temp->emp->ID == targetID) || 
                (temp->stu != nullptr && temp->stu->ID == targetID)) {
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        
        if (!found) {
            cout << "Value " << targetID << " not found in the list!\n";
            return;
        }
        
        prev->next = temp->next;
        delete temp;
        count--;
        cout << "Node with ID " << targetID << " deleted successfully.\n";
    }
    
    void sortList() {
        if (isEmpty() || count == 1) {
            return;
        }
        
        // Bubble sorting
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            Node* prev = nullptr;
            
            while (current != nullptr && current->next != nullptr) {
                Node* nextNode = current->next;
                bool shouldSwap = false;
                
                int currentID, nextID;
                
                if (current->emp != nullptr) currentID = current->emp->ID;
                else currentID = current->stu->ID;
                
                if (nextNode->emp != nullptr) nextID = nextNode->emp->ID;
                else nextID = nextNode->stu->ID;
                
                // Determine sorting order based on node type
                if (current->emp != nullptr && nextNode->emp != nullptr) {
                    // Both are Employees - sort ascending
                    shouldSwap = currentID > nextID;
                } else if (current->stu != nullptr && nextNode->stu != nullptr) {
                    // Both are Students - sort descending
                    shouldSwap = currentID < nextID;
                }
                // If different types, maintain original order
                
                if (shouldSwap) {
                    swapped = true;
                    
                    if (prev == nullptr) {
                        // Swapping head node
                        current->next = nextNode->next;
                        nextNode->next = current;
                        head = nextNode;
                    } else {
                        prev->next = nextNode;
                        current->next = nextNode->next;
                        nextNode->next = current;
                    }
                    prev = nextNode;
                } 
                else {
                    prev = current;
                    current = current->next;
                }
            }
        } while (swapped);
    }
    
    void display() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        int position = 1;
        
        while (temp != nullptr) {
            if (temp->emp != nullptr) {
                cout << "[EMPLOYEE] ID: " << temp->emp->ID<<"\n" 
                     << "Name: " << temp->emp->Name <<"\n"
                     << "Salary: " << temp->emp->Salary<<"\n";
            }
            
            if (temp->stu != nullptr) {
                cout << "[STUDENT] ID: " << temp->stu->ID 
                     << "\nName: " << temp->stu->Name 
                     << "\nClass: " << temp->stu->Class;
            }
            
            temp = temp->next;
            position++;
        }
        }
};

int main() {
    List list;
    
    Student stu1(1234, "Student1", "987234098", 4);
    Student stu2(4324, "Student2", "98734289", 5);
    Student stu3(5345, "Student3", "5098734258", 6);
    Student stu4(5378, "Student4", "50734258", 7);
    Student stu5(5095, "Student5", "50987348", 9);
    
    Employee emp1(1001, "Employee1", "988934798", 50000);
    Employee emp2(1002, "Employee2", "98askdjf89", 60000);
    Employee emp3(1003, "Employee3", "50sdkfj;58", 70000);
    Employee emp4(1004, "Employee4", "507342;laskdj58", 80000);
    Employee emp5(1005, "Employee5", "50ksdjfsdfh348", 90000);

    list.insertStart(&emp1, &stu1);
    list.insertEnd(&emp2, &stu2);  
    list.insertEnd(&emp3, &stu3);  
    list.insertEnd(&emp4, &stu4);  
    
    cout << "\nCurrent list:\n";
    list.display();
    
    cout << "\nSorting list...\n";
    list.sortList();
    list.display();
    
    cout << "\nTesting full list condition:\n";
    //adding more than 10
    for (int i = 0; i < 10; i++) {
        list.insertEnd(&emp5, &stu5);
    }
    
    cout << "\nDeleting node...\n";
    list.deleteNode(1002); 
    list.display();
    
    return 0;
}