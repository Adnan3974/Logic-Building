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
        getline(cin,newNode->name);
        cout<<"Enter department: ";
        cin>>newNode->department;
        cout<<"Enter status: ";
        cin>>newNode->status;
        while(newNode->status != "Available" || newNode->status != "Occupied"){
           cout<<"Invalid input, Please Enter \"Occupied\" or \"Available\"\n";
            cin>>newNode->status;
        }
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
        getline(cin,temp->name);
        cout<<"Enter department: ";
        cin>>temp->department;
        cout<<"Enter status: ";
        cin>>temp->status;
        while(temp->status != "Available" || temp->status != "Occupied"){
           cout<<"Invalid input, Please Enter \"Occupied\" or \"Available\"\n";
            cin>>temp->status;
        }
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
    //check for validation
    void sortDoctors(){
        if(head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        for(Node* i = head; i != nullptr; i = i->next){
            Node* minNode = i;
            for(Node* j = i->next; j != nullptr; j = j->next){
                if(j->patientCount < minNode->patientCount) minNode = j;
            }
            if(minNode != i){
                swap(i->id, minNode->id);
                swap(i->name, minNode->name);
                swap(i->department, minNode->department);
                swap(i->status, minNode->status);
                swap(i->patientCount, minNode->patientCount);
                swap(i->maxCap, minNode->maxCap);
            }
        }
        tail = head;
        while(tail && tail->next) 
        tail = tail->next;
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
        temp->patientCount++; //Patient added
        delete temp;
    }
};

struct Room{
    int roomId, patientId;
    string department, equipmentType, roomStatus; //status(occupied/available)
    Room* next;
    public: 
    Room(){
        next = nullptr;
    }
};
class cList{
    public: 
    Room* tail;
    cList(){
        tail = nullptr;
    }
    void addRoom(){
        Room* newRoom = new Room();
        cout<<"Enter room ID: ";
        cin>>newRoom->roomId;
        cout<<"Enter Department: ";
        cin>>newRoom->department;
        cout<<"Enter Equipment type: ";
        cin>>newRoom->equipmentType;
        cout<<"Enter room status: ";
        cin>>newRoom->roomStatus;
        while(newRoom->roomStatus != "Available" || newRoom->roomStatus != "Occupied"){
           cout<<"Invalid input, Please Enter \"Occupied\" or \"Available\"\n";
            cin>>newRoom->roomStatus;
        }
        cout<<"Enter current patient ID: ";
        cin>>newRoom->patientId;
        if(tail == nullptr){
            tail = newRoom;
        }
        else{
            tail->next = newRoom;
            newRoom->next = tail->next;
            tail = newRoom;
        }
    }
    void delRoom(){
        if(tail == nullptr){
            cout<<"No room available to delete in the list!\n"; return;
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
            cout<<"No room available in the list to assign!\n"; return;
        }
        cout<<"Please enter your Patient's ID: ";
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
    //check rotation
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

struct Patient{
    int PatientID, Age, SeverityLevel, AssignedDoctorID, AssignedRoomID, TreatmentStatus;
    string name, department;
    Patient* prev;
    Patient* next;
    Patient(): prev(nullptr), next(nullptr){};
};
class dcList{
    public: 
    Patient* tail;
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
    void prioritizePatient(){
        if(tail == nullptr) return;
        cout<<"Enter ID of the intended patient to reprioritize: "; 
        int id; cin>>id;
        Patient* temp = tail->next;
        do{
            if(temp->PatientID != id){
                temp = temp->next; 
            }
        }while(temp->PatientID != id && temp != tail->next);
        if(temp == tail->next && temp->PatientID != id){
            cout<<"Patient with this id not found"; return;
        }
        cout<<"Enter new Severity Level (1-5). 1 is the highest: "; cin>>temp->SeverityLevel;
        Patient* current = tail->next;
        do{
            if(current->SeverityLevel > temp->SeverityLevel){
                swap(current->PatientID, temp->PatientID);
                swap(current->name, temp->name);
                swap(current->Age, temp->Age);
                swap(current->department, temp->department);
                swap(current->SeverityLevel, temp->SeverityLevel);
                swap(current->AssignedDoctorID, temp->AssignedDoctorID);
                swap(current->AssignedRoomID, temp->AssignedRoomID);
                swap(current->TreatmentStatus, temp->TreatmentStatus);
            }
            current = current->next;
        }while(current != tail->next);
    }
    void dischargePatient(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        cout<<"Enter Patient ID to discharge: ";
        int pid; cin>>pid;
        Patient* p = tail->next;
        Patient* prev = tail;
        bool found = false;
        do{
            if(p->PatientID == pid){ found = true; break; }
            prev = p;
            p = p->next;
        } while(p != tail->next);
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return;
        }
        // free doctor and room links can be handled here if needed
        if(p == tail->next && p == tail){ // only one node
            delete p; tail = nullptr;
        } else {
            prev->next = p->next;
            if(p == tail) tail = prev; // update tail if needed
            delete p;
        }
        cout<<"Patient with ID "<<pid<<" discharged successfully.\n";
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
    void assignDoctor(dList &doctors){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        cout<<"Enter Patient ID to assign doctor: ";
        int pid; cin>>pid;
        Patient* p = tail->next;
        bool found = false;
        do{
            if(p->PatientID == pid){ found = true; break; }
            p = p->next;
        } while(p != tail->next);
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return;
        }
        if(doctors.head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        Node* best = nullptr;
        for(Node* d = doctors.head; d != nullptr; d = d->next){
            if(d->department == p->department && d->status == "Available" && d->patientCount < d->maxCap){
                if(!best || d->patientCount < best->patientCount) best = d;
            }
        }
        if(!best){
            cout<<"No available doctor in department "<<p->department<<".\n";
            return;
        }
        // assign
        best->patientCount++;
        p->AssignedDoctorID = best->id;
        if(best->patientCount >= best->maxCap) best->status = "Occupied";
        cout<<"Assigned Doctor ID "<<best->id<<" to Patient "<<p->PatientID<<".\n";
    }
    void assignRoom(Room* rooms){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        cout<<"Enter Patient ID to assign room: ";
        int pid; cin>>pid;
        Patient* p = tail->next;
        bool found = false;
        do{
            if(p->PatientID == pid){ 
                found = true; break; 
            }
            p = p->next;
        } while(p != tail->next);
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return;
        }
        while(rooms->roomStatus != "Available" || rooms->department != p->department){
            rooms = rooms->next;
        }
        if(rooms->roomStatus != "Available"){
            cout<<"No available room in department "<<p->department<<".\n";
            return;
        }
        cout<<"Patient "<<p->PatientID<<" assigned to Room "<<rooms->roomId<<".\n";
        rooms->roomStatus = "Occupied";
        p->AssignedRoomID = rooms->roomId;
    }
    void prioritizePatient(){
        if(tail == nullptr) 
        return;
        cout<<"Enter ID of the intended patient to reprioritize: "; 
        int id; cin>>id;
        Patient* temp = tail->next;
        do{
            if(temp->PatientID != id){
                temp = temp->next; 
            }
        }while(temp->PatientID != id && temp != tail->next);
        if(temp == tail->next && temp->PatientID != id){
            cout<<"Patient with this id not found"; return;
        }
        cout<<"Enter new Severity Level (1-5). 1 is the highest: "; cin>>temp->SeverityLevel;
        
        //Reorganize list based on severity level
        Patient* current = tail->next;
        do{
            if(current->SeverityLevel > temp->SeverityLevel){
                //Swap data
                swap(current->PatientID, temp->PatientID);
                swap(current->name, temp->name);
                swap(current->Age, temp->Age);
                swap(current->department, temp->department);
                swap(current->SeverityLevel, temp->SeverityLevel);
                swap(current->AssignedDoctorID, temp->AssignedDoctorID);
                swap(current->AssignedRoomID, temp->AssignedRoomID);
                swap(current->TreatmentStatus, temp->TreatmentStatus);
            }
            current = current->next;
        }while(current != tail->next);
    }
};

void manageDoctors(){
    dList doctors;
    cout<<"press 1 to add a doctor\n"
    <<"press 2 to delete a doctor\n"
    <<"press 3 to update a doctor\n"
    <<"press 4 to display doctors forward\n"
    <<"press 5 to display doctors backward\n"
    <<"press 6 to sort doctors by patient count\n"
    <<"press 7 to search for a doctor\n";
    int choice; cin>>choice;
    switch(choice){
        case 1:
            doctors.addDoctor();
            break;
        case 2:
            doctors.delDoctor();
            break;
        case 3:
            doctors.updDoctor();
            break;
        case 4:
            doctors.displayForward();
            break;
        case 5:
            doctors.displayReverse();
            break;
        case 6:
            doctors.sortDoctors();
            break;
        case 7:
            doctors.searchDoctor();
            break;
        default:
            cout<<"Invalid choice.\n";  
    }
}
void manageRooms(){
    cList rooms;
    cout<<"press 1 to add a room\n"
    <<"press 2 to delete a room\n"
    <<"press 3 to display rooms\n"
    <<"press 4 to assign room to patient\n"
    <<"press 5 to rotate rooms\n"
    <<"press 6 to get next available room\n";
    int choice; cin>>choice;
    switch(choice){
        case 1:
            rooms.addRoom();
            break;
        case 2:
            rooms.delRoom();
            break;
        case 3:
            rooms.displayRooms();
            break;
        case 4:
            rooms.assignRoom();
            break;
        case 5:
            rooms.rotateRoom();
            break;
        case 6:
            rooms.getNextAvailableRoom();
            break;
        default:
            cout<<"Invalid choice.\n";
}
}
void managePatients(){
    dcList patients;
    dList doctors;
    cList rooms;
    cout<<"press 1 to add a patient\n"
    <<"press 2 to update a patient\n"
    <<"press 3 to display patients forward\n"
    <<"press 4 to display patients backward\n"
    <<"press 5 to assign doctor to patient\n"
    <<"press 6 to assign room to patient\n"
    <<"press 7 to prioritize patient\n"
    <<
    int choice; cin>>choice;
    switch(choice){
        case 1:
            patients.addPatient();
            break;
        case 2:
            patients.updatePatient();
            break;
        case 3:
            patients.displayForward();
            break;
        case 4:
            patients.displayBackward();
            break;
        case 5:
            patients.assignDoctor(doctors);
            break;
        case 6:
            patients.assignRoom(rooms.tail->next);
            break;
        case 7:
            patients.prioritizePatient();
            break;
        default:
            cout<<"Invalid choice.\n";  
    }
}
int main(){
    bool status = true;
    while(status){
        cout<<"Press 1 to manage Doctors\n"
        <<"Press 2 to manage Rooms\n"
        <<"Press 3 to manage Patients\n"
        <<"Press 4 to exit\n";
        int choice; cin>>choice;
        switch(choice){
            case 1:
                manageDoctors();
                break;
            case 2:
                manageRooms();
                break;
            case 3:
                managePatients();
                break;
            case 4:
                status = false;
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }
    return 0;

}