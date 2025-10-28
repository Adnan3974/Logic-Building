#include<iostream>
using namespace std;
struct Node{
    int id;
    string name,department,status;
    int patientCount,maxCap;
    Node* prev;
    Node* next;
    public:
    Node(){
        maxCap = 10;
        prev = next = nullptr;
    }
};

class dList{
    public:
    Node* head;
    Node* tail;
    dList(){
        head = tail = nullptr;
    }
    void addDoctor(){
        Node* newNode = new Node();
        cout<<"Enter ID: ";
        cin>>newNode->id;
        cout<<"Enter name: ";
        cin>>newNode->name;
        cout<<"Enter department: ";
        cin>>newNode->department;
        cout<<"Enter status: ";
        cin>>newNode->status;
        cout<<"Enter patient count: ";
        cin>>newNode->patientCount;
        if(head == nullptr && tail==nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void delDoctor(){
        if(head == nullptr && tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        cout<<"Enter id of the doctor to delete: ";
        int i; cin>>i;
        Node* temp = head;
        while(temp->next!=nullptr && temp->next->id != i)
            temp = temp->next;
        if(temp->next->id != i){
            cout<<"No doctor exist with this id.\n";
            return;
        }
        temp->next = temp->next->next;
        temp->next->next->prev = temp;
        delete temp->next; temp->next = nullptr;
    }
    void updDoctor(){
        if(head == nullptr && tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        cout<<"Enter id of the intended doctor: ";
        int i; cin>>i;
        Node* temp = head;
        while(temp->id != i){
            temp = temp->next;
        }
        if(temp->id != i){
            cout<<"No doctor exist with this id.\n";
            return;
        }
        cout<<"Enter following info to update: ";
        cout<<"\nEnter name: ";
        cin>>temp->name;
        cout<<"Enter department: ";
        cin>>temp->department;
        cout<<"Enter status: ";
        cin>>temp->status;
        cout<<"Enter patient count: ";
        cin>>temp->patientCount;
        cout<<"Updated successfully.\n";
    }
    void displayForward(){
        Node* temp = head;
        while(temp != nullptr){
        cout<<"ID: "<<temp->id
        <<"  Name: "<<temp->name
        <<"  Department: "<<temp->department
        <<"  Status: "<<temp->status
        <<"  Patient count: "<<temp->patientCount<<endl;
        temp = temp->next;    
        }
        delete temp; temp = nullptr;
    }
    void displayReverse(){
        Node* temp = tail;
        while(temp != nullptr){
        cout<<"ID: "<<temp->id
        <<"  Name: "<<temp->name
        <<"  Department: "<<temp->department
        <<"  Status: "<<temp->status
        <<"  Patient count: "<<temp->patientCount<<endl;
        temp = temp->prev;
        }
        delete temp; temp = nullptr;
    }
    void sortDoctors(){
        if(head == nullptr && tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            if(temp->next->patientCount < temp->patientCount){
                Node* temp2 = temp;
                temp = temp->next;
                temp->next = temp2;
            }
        }
        delete temp; 
    }
    void searchDoctor(){
        if(head == nullptr && tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        cout<<"Enter ID to search: ";
        int i; cin>>i;
        Node* temp = head;
        while(temp->id != i){
            temp = temp->next;
        }
        if(temp->id != i){
            cout<<"No doctor exist with this id.\n";
            return;
        }
        cout<<"Doctor found with following info.\n";
        cout<<"ID: "<<temp->id
        <<"  Name: "<<temp->name
        <<"  Department: "<<temp->department
        <<"  Status: "<<temp->status
        <<"  Patient count: "<<temp->patientCount<<endl;
        delete temp;
    }
    void assignPatient(){
        if(head == nullptr && tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        cout<<"Enter department: ";
        string dep; cin>>dep;
        Node* temp = head;
        while(temp->department != dep && temp->patientCount<10){
            temp = temp->next;
        }
        temp->patientCount+1; //Patient added
        delete temp;
    }
};

struct Room{
    int roomId, patientId;
    string department, equipmentType, roomStatus;
    Room* next;
    public: 
    Room(){
        next = nullptr;
    }
};
class cList{
    Room* tail;
    public: 
    cList(){
        tail = nullptr;
    }
    void addRoom(){
        Room* newRoom = new Room();
        cout<<"Enter rood ID: ";
        cin>>newRoom->roomId;
        cout<<"Enter Department: ";
        cin>>newRoom->department;
        cout<<"Enter Equipment type: ";
        cin>>newRoom->equipmentType;
        cout<<"Enter room status: ";
        cin>>newRoom->roomStatus;
        cout<<"Enter current patient ID: ";
        cin>>newRoom->patientId;
        if(tail == nullptr){
            tail = newRoom;
        }
        else{
            tail->next = newRoom;
            newRoom->next = tail;
            tail = newRoom;
        }
    }
    void delRoom(){
        if(tail == nullptr){
            cout<<"No room available in the list!\n"; return;
        }
        cout<<"Enter room ID to delete: ";
        int i; cin>>i;
        Room* temp = tail->next;
        while(temp->next->roomId != i)
        temp = temp->next;
        if(temp->next->roomId != i){
            cout<<"Room not found!.\n"; return;
        }
        if(temp->next->next != nullptr)
        temp->next = temp->next->next;
        delete temp->next;
    }
    void displayRooms(){
        Room* temp = tail->next;
        do{
            cout<<"Room ID: "<<temp->roomId
            <<"  Department: "<<temp->department
            <<"  Equipment: "<<temp->equipmentType
            <<"  Status: "<<temp->roomStatus
            <<"  Current patient ID: "<<temp->patientId<<endl;
            temp = temp->next;
        }while(temp != tail->next);
        delete temp;
    }
    void assignRoom(){
        if(tail == nullptr){
            cout<<"No room available in the list!\n"; return;
        }
        cout<<"Please enter your ID: ";
        int d; cin>>d; 
        cout<<"Enter related Department: ";
        string dep; cin>>dep;
        Room* temp = tail->next;
        while(temp->department != dep && temp->roomStatus == "Available")
        temp = temp->next;
        if(temp->department != dep){
            cout<<"Department not matched!.\n"; return;
        }
        else if(temp->roomStatus == "Available"){
            cout<<"Room not available.\n";
        }
        else{
        cout<<"Room with ID "<<temp->roomId<<" assigned.\n";
        temp->patientId = d;
        delete temp->next;
        }
    }
    void rotateRoom(){ //In this case only rotate room by one
        tail->next = tail->next->next;
    }
    void getNextAvailableRoom(){
        if(tail == nullptr){
        cout<<"No room available in the list!\n"; return;
        }
        cout<<"Please enter your ID: ";
        int d; cin>>d; 
        cout<<"Enter related Department: ";
        string dep; cin>>dep;
        Room* temp = tail->next;
        while(temp->department != dep && temp->roomStatus == "Available")
        temp = temp->next;
        while(temp->next->department != dep && temp->roomStatus == "Available")
        temp = temp->next;
        if(temp->department != dep){
        cout<<"Department not matched!.\n"; return;
        }
        else if(temp->roomStatus == "Available"){
        cout<<"Room not available.\n";
        }
        else{
        cout<<"Room with ID "<<temp->roomId<<" assigned.\n";
        temp->patientId = d;
        delete temp->next;
        }
    }
};

/*
5. prioritizePatient() – Reorganize the list dynamically if a patient’s severity changes.
6. assignDoctor() – Assign the patient to a doctor if possible (Validation)
7. assignRoom() – Assign a room from the same department if available.
8. dischargePatient() – Remove a patient once treatment is complete and free doctor/room
links.
*/
struct Patient{
    int PatientID, Age, SeverityLevel, AssignedDoctorID, AssignedRoomID, TreatmentStatus;
    string name, department;
    Patient* prev;
    Patient* next;
    Patient(): prev(nullptr), next(nullptr){};
};
class dcList{
    Patient* tail;
    public: 
    dcList(): tail(nullptr){};
    void addPatient(){
        Patient* newNode = new Patient();
        cout<<"Enter Name: "; cin>>newNode->name;
        cout<<"Enter Parient ID: "; cin>>newNode->PatientID;
        cout<<"Enter Age: "; cin>>newNode->Age;
        cout<<"Enter Department: "; cin>>newNode->department;
        cout<<"Enter Severity Level (1-5). 1 is the highest: "; cin>>newNode->SeverityLevel;
        cout<<"Enter Assgned doctor ID: "; cin>>newNode->AssignedDoctorID;
        cout<<"Enter Assigned room ID: "; cin>>newNode->AssignedRoomID;
        cout<<"Enter Treatment Status: "; cin>>newNode->TreatmentStatus;
        if(tail == nullptr){
            tail = newNode; return;
        }
        else{
            newNode->prev = tail;
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void updatePatient(){
        if(tail == nullptr) return;
        cout<<"Enter ID of the intended patient: "; int id; cin>>id;
        Patient* temp = tail->next;
        do{
            if(temp->PatientID != id){
                temp = temp->next; 
            }
        }
        while(temp->PatientID != id && temp != tail->next);
        if(temp == tail->next && temp->PatientID != id){
            cout<<"Patient with this id not found"; return;
        }
        cout<<"Enter ID of new patient: "; cin>>temp->PatientID;
        cout<<"Enter Name: "; cin>>temp->name;
        cout<<"Enter Parient ID: "; cin>>temp->PatientID;
        cout<<"Enter Age: "; cin>>temp->Age;
        cout<<"Enter Department: "; cin>>temp->department;
        cout<<"Enter Severity Level (1-5). 1 is the highest: "; cin>>temp->SeverityLevel;
        cout<<"Enter Assgned doctor ID: "; cin>>temp->AssignedDoctorID;
        cout<<"Enter Assigned room ID: "; cin>>temp->AssignedRoomID;
        cout<<"Enter Treatment Status: "; cin>>temp->TreatmentStatus;
    }
    void displayForward(){
        Patient* temp = tail->next;
        do{
        cout<<"Name: "<<temp->name<<"\n"
        <<"Parient ID: "<<temp->PatientID<<"\n"
        <<"Age: "<<temp->Age<<"\n"
        <<"Department: "<<temp->department<<"\n"
        <<"Severity Level (1-5). 1 is the highest: "<<temp->SeverityLevel<<"\n"
        <<"Assigned doctor ID: "<<temp->AssignedDoctorID<<"\n"
        <<"Assigned room ID: "<<temp->AssignedRoomID<<"\n"
        <<"Treatment Status: "<<temp->TreatmentStatus;
        temp = temp->next;
        }while(temp!=tail->next);
    }
    void displayBackward(){
        Patient* temp = tail;
        do{
        cout<<"Name: "<<temp->name<<"\n"
        <<"Parient ID: "<<temp->PatientID<<"\n"
        <<"Age: "<<temp->Age<<"\n"
        <<"Department: "<<temp->department<<"\n"
        <<"Severity Level (1-5). 1 is the highest: "<<temp->SeverityLevel<<"\n"
        <<"Assigned doctor ID: "<<temp->AssignedDoctorID<<"\n"
        <<"Assigned room ID: "<<temp->AssignedRoomID<<"\n"
        <<"Treatment Status: "<<temp->TreatmentStatus;
        temp = temp->prev;
        }while(temp != tail);
    }
    void assignDoctor(){
        if(tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        cout<<"Enter intended doctor's department: ";
        string dep; cin>>dep;
        Patient* temp = tail->next;
        Node* temp = dList.head;
        while(temp->department != dep && temp->)
    }
    
    void assignRoom(){

    }
};

/*
4. Treatment Cycle Simulation (Core Requirement)
After every treatment cycle:
1. Each patient currently in treatment moves one step toward completion.
2. Patients who complete treatment are discharged and removed from the list.
3. Rooms rotate cyclically (CLL rotation) to simulate new patients entering treatment.
4. If a room becomes free, the next waiting patient (highest severity) is assigned
automatically.
5. The simulation continues until all patients are treated and discharged.

You must implement:
• simulateTreatmentCycle() – Performs one round of room rotation and treatment status
updates.
• runSimulation() – Repeats treatment cycles until all patients are discharged.
*/
int main(){
    dList doctor;
    doctor.addDoctor();
    doctor.addDoctor();
    doctor.addDoctor();
    doctor.displayForward();
    doctor.updDoctor();
    doctor.displayReverse();
    doctor.delDoctor();
    doctor.sortDoctors();
    doctor.displayForward();
    doctor.searchDoctor();
    doctor.assignPatient();
    doctor.displayForward();
    return 0;

}