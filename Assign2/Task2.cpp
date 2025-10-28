#include<iostream>
#include<algorithm>
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
        cin.ignore();
        getline(cin,newNode->name);
        cout<<"Enter department: ";
        cin>>newNode->department;
        cout<<"Enter status: ";
        cin>>newNode->status;
        while(newNode->status != "Available" && newNode->status != "Occupied"){
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
        cin.ignore();
        getline(cin,temp->name);
        cout<<"Enter department: ";
        cin>>temp->department;
        cout<<"Enter status: ";
        cin>>temp->status;
        while(temp->status != "Available" && temp->status != "Occupied"){
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
    }
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
        while(temp && temp->id != i){
            temp = temp->next;
        }
        if(!temp || temp->id != i){
            cout<<"No doctor exist with this id.\n";
            return;
        }
        cout<<"Doctor found with following info.\n";
        cout<<"ID: "<<temp->id
        <<"  Name: "<<temp->name
        <<"  Department: "<<temp->department
        <<"  Status: "<<temp->status
        <<"  Patient count: "<<temp->patientCount<<endl;
    }
    Node* findDoctorByID(int id){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->id == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};
struct Room{
    int roomId, patientId;
    string department, equipmentType, roomStatus;
    Room* next;
    public: 
    Room(){
        next = nullptr;
        patientId = -1;
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
        newRoom->roomStatus = "Available";
        newRoom->patientId = -1;
        
        if(tail == nullptr){
            tail = newRoom;
            tail->next = tail;
        }
        else{
            newRoom->next = tail->next;
            tail->next = newRoom;
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
        Room* prev = tail;
        do{
            if(temp->roomId == i) break;
            prev = temp;
            temp = temp->next;
        }while(temp != tail->next);
        
        if(temp->roomId != i){
            cout<<"Room not found!.\n"; return;
        }
        
        if(temp == tail->next && temp == tail){
            delete temp;
            tail = nullptr;
        } else {
            prev->next = temp->next;
            if(temp == tail) tail = prev;
            delete temp;
        }
    }
    void displayRooms(){
        if(tail == nullptr){
            cout<<"No rooms in the list!\n";
            return;
        }
        Room* temp = tail->next;
        do{
            cout<<"Room ID: "<<temp->roomId
            <<"  Department: "<<temp->department
            <<"  Equipment: "<<temp->equipmentType
            <<"  Status: "<<temp->roomStatus
            <<"  Current patient ID: "<<temp->patientId<<endl;
            temp = temp->next;
        }while(temp != tail->next);
    }
    
    Room* findAvailableRoom(string dep){
        if(tail == nullptr) return nullptr;
        Room* temp = tail->next;
        do{
            if(temp->department == dep && temp->roomStatus == "Available"){
                return temp;
            }
            temp = temp->next;
        }while(temp != tail->next);
        return nullptr;
    }
    
    Room* findRoomByID(int rid){
        if(tail == nullptr) return nullptr;
        Room* temp = tail->next;
        do{
            if(temp->roomId == rid) return temp;
            temp = temp->next;
        }while(temp != tail->next);
        return nullptr;
    }
    
    void rotateToNextRoom(int currentRoomId, int patientId, string department){
        if(tail == nullptr){
            cout<<"No rooms available!\n";
            return;
        }
        
        Room* currentRoom = findRoomByID(currentRoomId);
        if(!currentRoom){
            cout<<"Current room not found!\n";
            return;
        }
        
        // Free current room
        currentRoom->roomStatus = "Available";
        currentRoom->patientId = -1;
        
        // Find next available room in same department
        Room* nextRoom = currentRoom->next;
        while(nextRoom != currentRoom){
            if(nextRoom->department == department && nextRoom->roomStatus == "Available"){
                nextRoom->roomStatus = "Occupied";
                nextRoom->patientId = patientId;
                cout<<"Patient "<<patientId<<" rotated from Room "<<currentRoomId
                    <<" to Room "<<nextRoom->roomId<<endl;
                return;
            }
            nextRoom = nextRoom->next;
        }
        cout<<"No available room found for rotation in department "<<department<<endl;
    }
};

struct Patient{
    int PatientID, Age, SeverityLevel, AssignedDoctorID, AssignedRoomID, TreatmentStatus;
    string name, department;
    Patient* prev;
    Patient* next;
    Patient(): prev(nullptr), next(nullptr){
        AssignedDoctorID = -1;
        AssignedRoomID = -1;
        TreatmentStatus = 0;
    }
};

class dcList{
    public: 
    Patient* tail;
    dcList(): tail(nullptr){};
    
    void addPatient(){
        Patient* newNode = new Patient();
        cout<<"Enter Name: "; cin>>newNode->name;
        cout<<"Enter Patient ID: "; cin>>newNode->PatientID;
        cout<<"Enter Age: "; cin>>newNode->Age;
        cout<<"Enter Department: "; cin>>newNode->department;
        cout<<"Enter Severity Level (1-5, 5 is highest): "; cin>>newNode->SeverityLevel;
        newNode->AssignedDoctorID = -1;
        newNode->AssignedRoomID = -1;
        newNode->TreatmentStatus = 0;
        
        if(tail == nullptr){
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        }
        else{
            newNode->prev = tail;
            newNode->next = tail->next;
            tail->next->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
        cout<<"Patient added successfully!\n";
    }
    
    void updatePatient(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        cout<<"Enter ID of the intended patient: "; 
        int id; cin>>id;
        Patient* temp = tail->next;
        do{
            if(temp->PatientID == id) break;
            temp = temp->next;
        }while(temp != tail->next);
        
        if(temp->PatientID != id){
            cout<<"Patient with this id not found\n"; 
            return;
        }
        cout<<"Enter Name: "; cin>>temp->name;
        cout<<"Enter Age: "; cin>>temp->Age;
        cout<<"Enter Department: "; cin>>temp->department;
        cout<<"Enter Severity Level (1-5, 5 is highest): "; cin>>temp->SeverityLevel;
    }
    
    void dischargePatient(int pid, dList& doctors, cList& rooms){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        Patient* p = tail->next;
        Patient* prev = tail;
        bool found = false;
        do{
            if(p->PatientID == pid){ 
                found = true; 
                break; 
            }
            prev = p;
            p = p->next;
        } while(p != tail->next);
        
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return;
        }
        
        // Free doctor
        if(p->AssignedDoctorID != -1){
            Node* doc = doctors.findDoctorByID(p->AssignedDoctorID);
            if(doc){
                doc->patientCount--;
                if(doc->patientCount < doc->maxCap) doc->status = "Available";
            }
        }
        
        // Free room
        if(p->AssignedRoomID != -1){
            Room* room = rooms.findRoomByID(p->AssignedRoomID);
            if(room){
                room->roomStatus = "Available";
                room->patientId = -1;
            }
        }
        
        if(p == tail->next && p == tail){
            delete p; 
            tail = nullptr;
        } else {
            prev->next = p->next;
            p->next->prev = prev;
            if(p == tail) tail = prev;
            delete p;
        }
        cout<<"Patient with ID "<<pid<<" discharged successfully.\n";
    }
    
    void displayForward(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        Patient* temp = tail->next;
        do{
            cout<<"\n================================\n";
            cout<<"Name: "<<temp->name<<"\n"
            <<"Patient ID: "<<temp->PatientID<<"\n"
            <<"Age: "<<temp->Age<<"\n"
            <<"Department: "<<temp->department<<"\n"
            <<"Severity Level: "<<temp->SeverityLevel<<"\n"
            <<"Assigned Doctor ID: "<<temp->AssignedDoctorID<<"\n"
            <<"Assigned Room ID: "<<temp->AssignedRoomID<<"\n"
            <<"Treatment Status: "<<temp->TreatmentStatus<<"\n";
            temp = temp->next;
        }while(temp!=tail->next);
    }
    
    bool assignDoctor(int pid, dList& doctors){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return false;
        }
        Patient* p = tail->next;
        bool found = false;
        do{
            if(p->PatientID == pid){ 
                found = true; 
                break; 
            }
            p = p->next;
        } while(p != tail->next);
        
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return false;
        }
        
        if(doctors.head == nullptr){
            cout<<"No doctors available!\n";
            return false;
        }
        
        Node* best = nullptr;
        for(Node* d = doctors.head; d != nullptr; d = d->next){
            if(d->department == p->department && d->status == "Available" && d->patientCount < d->maxCap){
                if(!best || d->patientCount < best->patientCount) best = d;
            }
        }
        
        if(!best){
            cout<<"No available doctor in department "<<p->department<<".\n";
            return false;
        }
        
        best->patientCount++;
        p->AssignedDoctorID = best->id;
        if(best->patientCount >= best->maxCap) best->status = "Occupied";
        cout<<"Assigned Doctor ID "<<best->id<<" ("<<best->name<<") to Patient "<<p->PatientID<<".\n";
        return true;
    }
    
    bool assignRoom(int pid, cList& rooms){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return false;
        }
        Patient* p = tail->next;
        bool found = false;
        do{
            if(p->PatientID == pid){ 
                found = true; 
                break; 
            }
            p = p->next;
        } while(p != tail->next);
        
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return false;
        }
        
        Room* availableRoom = rooms.findAvailableRoom(p->department);
        if(!availableRoom){
            cout<<"No available room in department "<<p->department<<".\n";
            return false;
        }
        
        availableRoom->roomStatus = "Occupied";
        availableRoom->patientId = p->PatientID;
        p->AssignedRoomID = availableRoom->roomId;
        cout<<"Patient "<<p->PatientID<<" assigned to Room "<<availableRoom->roomId<<".\n";
        return true;
    }
    
    void performTreatment(int pid, cList& rooms, dList& doctors){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        Patient* p = tail->next;
        bool found = false;
        do{
            if(p->PatientID == pid){ 
                found = true; 
                break; 
            }
            p = p->next;
        } while(p != tail->next);
        
        if(!found){
            cout<<"Patient with ID "<<pid<<" not found.\n";
            return;
        }
        
        if(p->AssignedDoctorID == -1 || p->AssignedRoomID == -1){
            cout<<"Patient must have assigned doctor and room before treatment!\n";
            return;
        }
        
        cout<<"\n--- Performing Treatment ---\n";
        cout<<"Patient: "<<p->name<<" (ID: "<<p->PatientID<<")\n";
        cout<<"Current Severity: "<<p->SeverityLevel<<"\n";
        
        if(p->SeverityLevel > 0){
            p->SeverityLevel--;
            p->TreatmentStatus++;
            cout<<"Treatment completed! New Severity: "<<p->SeverityLevel<<"\n";
            
            if(p->SeverityLevel > 0){
                // Rotate to next room
                rooms.rotateToNextRoom(p->AssignedRoomID, p->PatientID, p->department);
                Room* newRoom = rooms.findAvailableRoom(p->department);
                if(newRoom && newRoom->patientId == p->PatientID){
                    p->AssignedRoomID = newRoom->roomId;
                }
            } else {
                cout<<"Patient "<<p->PatientID<<" is ready for discharge!\n";
            }
        }
    }
    
    Patient* findPatientByID(int pid){
        if(tail == nullptr) return nullptr;
        Patient* p = tail->next;
        do{
            if(p->PatientID == pid) return p;
            p = p->next;
        } while(p != tail->next);
        return nullptr;
    }
    
    bool hasPatients(){
        return tail != nullptr;
    }
};

void runSimulation(dcList& patients, dList& doctors, cList& rooms){
    cout<<"\n========== HOSPITAL SIMULATION STARTED ==========\n";
    
    while(patients.hasPatients()){
        cout<<"\n--- Current Patients Status ---\n";
        patients.displayForward();
        
        Patient* p = patients.tail->next;
        Patient* start = p;
        bool processed = false;
        
        do{
            int pid = p->PatientID;
            
            // Step 1: Assign doctor if not assigned
            if(p->AssignedDoctorID == -1){
                cout<<"\nAssigning doctor to Patient "<<pid<<"...\n";
                patients.assignDoctor(pid, doctors);
            }
            
            // Step 2: Assign room if not assigned
            if(p->AssignedRoomID == -1){
                cout<<"\nAssigning room to Patient "<<pid<<"...\n";
                patients.assignRoom(pid, rooms);
            }
            
            // Step 3: Perform treatment
            if(p->AssignedDoctorID != -1 && p->AssignedRoomID != -1){
                patients.performTreatment(pid, rooms, doctors);
                processed = true;
            }
            
            // Step 4: Check for discharge
            Patient* current = patients.findPatientByID(pid);
            if(current && current->SeverityLevel == 0){
                cout<<"\nDischarging Patient "<<pid<<"...\n";
                patients.dischargePatient(pid, doctors, rooms);
            }
            
            if(!patients.hasPatients()) break;
            
            p = p->next;
            if(p == start && !processed) break;
            
        }while(p != start && patients.hasPatients());
        
        if(!processed && patients.hasPatients()){
            cout<<"\nNo resources available to process remaining patients. Ending simulation.\n";
            break;
        }
        
        cout<<"\n--- Press Enter to continue simulation ---";
        cin.ignore();
        cin.get();
    }
    
    cout<<"\n========== SIMULATION COMPLETED ==========\n";
    cout<<"All patients have been processed!\n";
}

void manageDoctors(dList& doctors){
    cout<<"\npress 1 to add a doctor\n"
    <<"press 2 to delete a doctor\n"
    <<"press 3 to update a doctor\n"
    <<"press 4 to display doctors forward\n"
    <<"press 5 to display doctors backward\n"
    <<"press 6 to sort doctors by patient count\n"
    <<"press 7 to search for a doctor\n";
    int choice; cin>>choice;
    switch(choice){
        case 1: doctors.addDoctor(); break;
        case 2: doctors.delDoctor(); break;
        case 3: doctors.updDoctor(); break;
        case 4: doctors.displayForward(); break;
        case 5: doctors.displayReverse(); break;
        case 6: doctors.sortDoctors(); break;
        case 7: doctors.searchDoctor(); break;
        default: cout<<"Invalid choice.\n";  
    }
}

void manageRooms(cList& rooms){
    cout<<"\npress 1 to add a room\n"
    <<"press 2 to delete a room\n"
    <<"press 3 to display rooms\n";
    int choice; cin>>choice;
    switch(choice){
        case 1: rooms.addRoom(); break;
        case 2: rooms.delRoom(); break;
        case 3: rooms.displayRooms(); break;
        default: cout<<"Invalid choice.\n";
    }
}

void managePatients(dcList& patients, dList& doctors, cList& rooms){
    cout<<"\npress 1 to add a patient\n"
    <<"press 2 to update a patient\n"
    <<"press 3 to display patients forward\n"
    <<"press 4 to assign doctor to patient\n"
    <<"press 5 to assign room to patient\n"
    <<"press 6 to perform treatment\n"
    <<"press 7 to discharge patient\n";
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
        case 4:{
            cout<<"Enter Patient ID: ";
            int pid; cin>>pid;
            patients.assignDoctor(pid, doctors);
            break;
        }
        case 5:{
            cout<<"Enter Patient ID: ";
            int pid; cin>>pid;
            patients.assignRoom(pid, rooms);
            break;
        }
        case 6:{
            cout<<"Enter Patient ID: ";
            int pid; cin>>pid;
            patients.performTreatment(pid, rooms, doctors);
            break;
        }
        case 7:{
            cout<<"Enter Patient ID: ";
            int pid; cin>>pid;
            patients.dischargePatient(pid, doctors, rooms);
            break;
        }
        default: 
            cout<<"Invalid choice.\n";  
    }
}

int main(){
    dList doctors;
    cList rooms;
    dcList patients;
    
    bool status = true;
    while(status){
        cout<<"\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n";
        cout<<"Press 1 to manage Doctors\n"
        <<"Press 2 to manage Rooms\n"
        <<"Press 3 to manage Patients\n"
        <<"Press 4 to run simulation\n"
        <<"Press 5 to exit\n"
        <<"Choice: ";
        int choice; cin>>choice;
        switch(choice){
            case 1:
                manageDoctors(doctors);
                break;
            case 2:
                manageRooms(rooms);
                break;
            case 3:
                managePatients(patients, doctors, rooms);
                break;
            case 4:
                runSimulation(patients, doctors, rooms);
                break;
            case 5:
                status = false;
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }
    return 0;
}