#include<iostream>
using namespace std;

struct Node{
    int id;
    string name, department, status;
    int patientCount, maxCap;
    Node* prev;
    Node* next;
    
    Node(){
        maxCap = 10;
        patientCount = 0;
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
        cin.ignore();
        cout<<"Enter name: ";
        getline(cin, newNode->name);
        cout<<"Enter department: ";
        cin>>newNode->department;
        cout<<"Enter status (Available/Occupied): ";
        cin>>newNode->status;
        
        while(newNode->status != "Available" && newNode->status != "Occupied"){
            cout<<"Invalid input, Please Enter \"Occupied\" or \"Available\"\n";
            cin>>newNode->status;
        }
        
        cout<<"Enter patient count: ";
        cin>>newNode->patientCount;
        
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout<<"Doctor added successfully!\n";
    }
    
    void delDoctor(){
        if(head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        
        cout<<"Enter id of the doctor to delete: ";
        int i; cin>>i;
        
        Node* temp = head;
        while(temp != nullptr && temp->id != i){
            temp = temp->next;
        }
        
        if(temp == nullptr){
            cout<<"No doctor exists with this id.\n";
            return;
        }
        
        if(temp == head && temp == tail){
            head = tail = nullptr;
        }
        else if(temp == head){
            head = head->next;
            head->prev = nullptr;
        }
        else if(temp == tail){
            tail = tail->prev;
            tail->next = nullptr;
        }
        else{
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        
        delete temp;
        cout<<"Doctor deleted successfully!\n";
    }
    
    void updDoctor(){
        if(head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        
        cout<<"Enter id of the intended doctor: ";
        int i; cin>>i;
        
        Node* temp = head;
        while(temp != nullptr && temp->id != i){
            temp = temp->next;
        }
        
        if(temp == nullptr){
            cout<<"No doctor exists with this id.\n";
            return;
        }
        
        cin.ignore();
        cout<<"Enter following info to update: ";
        cout<<"\nEnter name: ";
        getline(cin, temp->name);
        cout<<"Enter department: ";
        cin>>temp->department;
        cout<<"Enter status (Available/Occupied): ";
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
        if(head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        
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
        if(tail == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        
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
                if(j->patientCount < minNode->patientCount) 
                    minNode = j;
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
        cout<<"Doctors sorted by patient count!\n";
    }
    
    void searchDoctor(){
        if(head == nullptr){
            cout<<"No doctors available!\n";
            return;
        }
        
        cout<<"Enter ID to search: ";
        int i; cin>>i;
        
        Node* temp = head;
        while(temp != nullptr && temp->id != i){
            temp = temp->next;
        }
        
        if(temp == nullptr){
            cout<<"No doctor exists with this id.\n";
            return;
        }
        
        cout<<"Doctor found with following info.\n";
        cout<<"ID: "<<temp->id
        <<"  Name: "<<temp->name
        <<"  Department: "<<temp->department
        <<"  Status: "<<temp->status
        <<"  Patient count: "<<temp->patientCount<<endl;
    }
};

struct Room{
    int roomId, patientId;
    string department, equipmentType, roomStatus;
    Room* next;
    
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
        cout<<"Enter room status (Available/Occupied): ";
        cin>>newRoom->roomStatus;
        
        while(newRoom->roomStatus != "Available" && newRoom->roomStatus != "Occupied"){
            cout<<"Invalid input, Please Enter \"Occupied\" or \"Available\"\n";
            cin>>newRoom->roomStatus;
        }
        
        if(newRoom->roomStatus == "Occupied"){
            cout<<"Enter current patient ID: ";
            cin>>newRoom->patientId;
        }
        
        if(tail == nullptr){
            tail = newRoom;
            tail->next = tail;
        }
        else{
            newRoom->next = tail->next;
            tail->next = newRoom;
            tail = newRoom;
        }
        cout<<"Room added successfully!\n";
    }
    
    void delRoom(){
        if(tail == nullptr){
            cout<<"No room available to delete in the list!\n";
            return;
        }
        
        cout<<"Enter room ID to delete: ";
        int i; cin>>i;
        
        Room* temp = tail->next;
        Room* prev = tail;
        
        do{
            if(temp->roomId == i){
                if(temp == tail && temp->next == tail){
                    tail = nullptr;
                }
                else{
                    prev->next = temp->next;
                    if(temp == tail){
                        tail = prev;
                    }
                }
                delete temp;
                cout<<"Room deleted successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }while(temp != tail->next);
        
        cout<<"Room not found!\n";
    }
    
    void displayRooms(){
        if(tail == nullptr){
            cout<<"No rooms available!\n";
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
    
    void rotateRoom(){
        if(tail == nullptr){
            cout<<"No rooms to rotate!\n";
            return;
        }
        tail = tail->next;
        cout<<"Rooms rotated!\n";
    }
    
    void getNextAvailableRoom(){
        if(tail == nullptr){
            cout<<"No room available in the list!\n";
            return;
        }
        
        cout<<"Enter Department: ";
        string dep; cin>>dep;
        
        Room* temp = tail->next;
        Room* start = temp;
        
        do{
            if(temp->department == dep && temp->roomStatus == "Available"){
                cout<<"Next available room: ID "<<temp->roomId<<endl;
                return;
            }
            temp = temp->next;
        }while(temp != start);
        
        cout<<"No available room in department "<<dep<<endl;
    }
};

struct Patient{
    int PatientID, Age, SeverityLevel, AssignedDoctorID, AssignedRoomID, TreatmentStatus;
    string name, department;
    Patient* prev;
    Patient* next;
    
    Patient(){
        prev = nullptr;
        next = nullptr;
        AssignedDoctorID = -1;
        AssignedRoomID = -1;
        TreatmentStatus = 1;
    }
};

class dcList{
    public: 
    Patient* tail;
    
    dcList(){
        tail = nullptr;
    }
    
    void addPatient(){
        Patient* newNode = new Patient();
        cin.ignore();
        cout<<"Enter Name: ";
        getline(cin, newNode->name);
        cout<<"Enter Patient ID: ";
        cin>>newNode->PatientID;
        cout<<"Enter Age: ";
        cin>>newNode->Age;
        cout<<"Enter Department: ";
        cin>>newNode->department;
        cout<<"Enter Severity Level (1-5, 1 is highest): ";
        cin>>newNode->SeverityLevel;
        
        if(tail == nullptr){
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        }
        else{
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
        
        sortBySeverity();
        cout<<"Patient added successfully!\n";
    }
    
    void sortBySeverity(){
        if(tail == nullptr || tail->next == tail) return;
        
        Patient* current = tail->next;
        do{
            Patient* minNode = current;
            Patient* temp = current->next;
            
            while(temp != tail->next){
                if(temp->SeverityLevel < minNode->SeverityLevel){
                    minNode = temp;
                }
                temp = temp->next;
            }
            
            if(minNode != current){
                swap(current->PatientID, minNode->PatientID);
                swap(current->name, minNode->name);
                swap(current->Age, minNode->Age);
                swap(current->department, minNode->department);
                swap(current->SeverityLevel, minNode->SeverityLevel);
                swap(current->AssignedDoctorID, minNode->AssignedDoctorID);
                swap(current->AssignedRoomID, minNode->AssignedRoomID);
                swap(current->TreatmentStatus, minNode->TreatmentStatus);
            }
            
            current = current->next;
        }while(current != tail->next);
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
            if(temp->PatientID == id){
                cin.ignore();
                cout<<"Enter Name: ";
                getline(cin, temp->name);
                cout<<"Enter Age: ";
                cin>>temp->Age;
                cout<<"Enter Department: ";
                cin>>temp->department;
                cout<<"Enter Severity Level (1-5, 1 is highest): ";
                cin>>temp->SeverityLevel;
                cout<<"Enter Treatment Status (1-3, 3 completed): ";
                cin>>temp->TreatmentStatus;
                cout<<"Updated successfully!\n";
                return;
            }
            temp = temp->next;
        }while(temp != tail->next);
        
        cout<<"Patient with this id not found!\n";
    }
    
    void prioritizePatient(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        
        cout<<"Enter ID of the intended patient to reprioritize: ";
        int id; cin>>id;
        
        Patient* temp = tail->next;
        do{
            if(temp->PatientID == id){
                cout<<"Enter new Severity Level (1-5, 1 is highest): ";
                cin>>temp->SeverityLevel;
                sortBySeverity();
                cout<<"Patient reprioritized!\n";
                return;
            }
            temp = temp->next;
        }while(temp != tail->next);
        
        cout<<"Patient with this id not found!\n";
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
        
        do{
            if(p->PatientID == pid){
                if(p == tail && p->next == tail){
                    tail = nullptr;
                }
                else{
                    prev->next = p->next;
                    p->next->prev = prev;
                    if(p == tail){
                        tail = prev;
                    }
                }
                delete p;
                cout<<"Patient with ID "<<pid<<" discharged successfully.\n";
                return;
            }
            prev = p;
            p = p->next;
        }while(p != tail->next);
        
        cout<<"Patient with ID "<<pid<<" not found.\n";
    }
    
    void displayForward(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        
        Patient* temp = tail->next;
        do{
            cout<<"\n--- Patient Info ---\n"
            <<"Name: "<<temp->name<<"\n"
            <<"Patient ID: "<<temp->PatientID<<"\n"
            <<"Age: "<<temp->Age<<"\n"
            <<"Department: "<<temp->department<<"\n"
            <<"Severity Level: "<<temp->SeverityLevel<<"\n"
            <<"Assigned Doctor ID: "<<temp->AssignedDoctorID<<"\n"
            <<"Assigned Room ID: "<<temp->AssignedRoomID<<"\n"
            <<"Treatment Status: "<<temp->TreatmentStatus<<"\n";
            temp = temp->next;
        }while(temp != tail->next);
    }
    
    void displayBackward(){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        
        Patient* temp = tail;
        do{
            cout<<"\n--- Patient Info ---\n"
            <<"Name: "<<temp->name<<"\n"
            <<"Patient ID: "<<temp->PatientID<<"\n"
            <<"Age: "<<temp->Age<<"\n"
            <<"Department: "<<temp->department<<"\n"
            <<"Severity Level: "<<temp->SeverityLevel<<"\n"
            <<"Assigned Doctor ID: "<<temp->AssignedDoctorID<<"\n"
            <<"Assigned Room ID: "<<temp->AssignedRoomID<<"\n"
            <<"Treatment Status: "<<temp->TreatmentStatus<<"\n";
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
        do{
            if(p->PatientID == pid){
                if(doctors.head == nullptr){
                    cout<<"No doctors available!\n";
                    return;
                }
                
                Node* best = nullptr;
                for(Node* d = doctors.head; d != nullptr; d = d->next){
                    if(d->department == p->department && d->status == "Available" && d->patientCount < d->maxCap){
                        if(best == nullptr || d->patientCount < best->patientCount){
                            best = d;
                        }
                    }
                }
                
                if(best == nullptr){
                    cout<<"No available doctor in department "<<p->department<<".\n";
                    return;
                }
                
                best->patientCount++;
                p->AssignedDoctorID = best->id;
                if(best->patientCount >= best->maxCap){
                    best->status = "Occupied";
                }
                cout<<"Assigned Doctor ID "<<best->id<<" to Patient "<<p->PatientID<<".\n";
                return;
            }
            p = p->next;
        }while(p != tail->next);
        
        cout<<"Patient with ID "<<pid<<" not found.\n";
    }
    
    void assignRoom(cList &rooms){
        if(tail == nullptr){
            cout<<"No patients in list!\n";
            return;
        }
        
        cout<<"Enter Patient ID to assign room: ";
        int pid; cin>>pid;
        
        Patient* p = tail->next;
        do{
            if(p->PatientID == pid){
                if(rooms.tail == nullptr){
                    cout<<"No rooms available!\n";
                    return;
                }
                
                Room* temp = rooms.tail->next;
                Room* start = temp;
                
                do{
                    if(temp->roomStatus == "Available" && temp->department == p->department){
                        temp->roomStatus = "Occupied";
                        temp->patientId = p->PatientID;
                        p->AssignedRoomID = temp->roomId;
                        cout<<"Patient "<<p->PatientID<<" assigned to Room "<<temp->roomId<<".\n";
                        return;
                    }
                    temp = temp->next;
                }while(temp != start);
                
                cout<<"No available room in department "<<p->department<<".\n";
                return;
            }
            p = p->next;
        }while(p != tail->next);
        
        cout<<"Patient with ID "<<pid<<" not found.\n";
    }
};

void simulateTreatmentCycle(dcList &patients, cList &rooms, dList &doctors){
    if(patients.tail == nullptr){
        cout<<"No patients in treatment.\n";
        return;
    }
    
    cout<<"\n=== Starting Treatment Cycle ===\n";
    
    Patient* p = patients.tail->next;
    Patient* start = p;
    
    do{
        Patient* current = p;
        p = p->next;
        
        if(current->TreatmentStatus < 3){
            current->TreatmentStatus++;
            cout<<"Patient "<<current->PatientID<<" treatment progress: "<<current->TreatmentStatus<<"/3\n";
        }
        
        if(current->TreatmentStatus == 3){
            cout<<"Patient "<<current->PatientID<<" treatment completed. Discharging...\n";
            
            if(current->AssignedRoomID != -1 && rooms.tail != nullptr){
                Room* r = rooms.tail->next;
                do{
                    if(r->roomId == current->AssignedRoomID){
                        r->roomStatus = "Available";
                        r->patientId = -1;
                        break;
                    }
                    r = r->next;
                }while(r != rooms.tail->next);
            }
            
            if(current->AssignedDoctorID != -1 && doctors.head != nullptr){
                Node* d = doctors.head;
                while(d != nullptr){
                    if(d->id == current->AssignedDoctorID){
                        d->patientCount--;
                        if(d->patientCount < d->maxCap){
                            d->status = "Available";
                        }
                        break;
                    }
                    d = d->next;
                }
            }
            
            int dischargeId = current->PatientID;
            if(current == patients.tail && current->next == current){
                patients.tail = nullptr;
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if(current == patients.tail){
                    patients.tail = current->prev;
                }
            }
            delete current;
            
            if(patients.tail == nullptr) break;
        }
        
    }while(p != start && patients.tail != nullptr);
    
    if(rooms.tail != nullptr){
        rooms.rotateRoom();
    }
    
    cout<<"=== Treatment Cycle Complete ===\n\n";
}

void runSimulation(dcList &patients, cList &rooms, dList &doctors){
    cout<<"\n*** Starting Full Treatment Simulation ***\n";
    
    int cycle = 1;
    while(patients.tail != nullptr){
        cout<<"\n--- Cycle "<<cycle<<" ---\n";
        simulateTreatmentCycle(patients, rooms, doctors);
        cycle++;
        
        if(cycle > 100){
            cout<<"Maximum cycles reached. Stopping simulation.\n";
            break;
        }
    }
    
    cout<<"\n*** All patients discharged. Simulation complete! ***\n";
}

void manageDoctors(dList &doctors){
    cout<<"\n=== Doctor Management ===\n"
    <<"1. Add a doctor\n"
    <<"2. Delete a doctor\n"
    <<"3. Update a doctor\n"
    <<"4. Display doctors forward\n"
    <<"5. Display doctors backward\n"
    <<"6. Sort doctors by patient count\n"
    <<"7. Search for a doctor\n"
    <<"Enter choice: ";
    
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

void manageRooms(cList &rooms){
    cout<<"\n=== Room Management ===\n"
    <<"1. Add a room\n"
    <<"2. Delete a room\n"
    <<"3. Display rooms\n"
    <<"4. Rotate rooms\n"
    <<"5. Get next available room\n"
    <<"Enter choice: ";
    
    int choice; cin>>choice;
    
    switch(choice){
        case 1: rooms.addRoom(); break;
        case 2: rooms.delRoom(); break;
        case 3: rooms.displayRooms(); break;
        case 4: rooms.rotateRoom(); break;
        case 5: rooms.getNextAvailableRoom(); break;
        default: cout<<"Invalid choice.\n";
    }
}

void managePatients(dcList &patients, dList &doctors, cList &rooms){
    cout<<"\n=== Patient Management ===\n"
    <<"1. Add a patient\n"
    <<"2. Update a patient\n"
    <<"3. Display patients forward\n"
    <<"4. Display patients backward\n"
    <<"5. Assign doctor to patient\n"
    <<"6. Assign room to patient\n"
    <<"7. Prioritize patient\n"
    <<"8. Discharge patient\n"
    <<"Enter choice: ";
    
    int choice; cin>>choice;
    
    switch(choice){
        case 1: patients.addPatient(); break;
        case 2: patients.updatePatient(); break;
        case 3: patients.displayForward(); break;
        case 4: patients.displayBackward(); break;
        case 5: patients.assignDoctor(doctors); break;
        case 6: patients.assignRoom(rooms); break;
        case 7: patients.prioritizePatient(); break;
        case 8: patients.dischargePatient(); break;
        default: cout<<"Invalid choice.\n";
    }
}

int main(){
    dList doctors;
    cList rooms;
    dcList patients;
    
    bool status = true;
    while(status){
        cout<<"\n========== HOSPITAL MANAGEMENT SYSTEM ==========\n"
        <<"1. Manage Doctors\n"
        <<"2. Manage Rooms\n"
        <<"3. Manage Patients\n"
        <<"4. Simulate Treatment Cycle\n"
        <<"5. Run Full Simulation\n"
        <<"6. Exit\n"
        <<"Enter choice: ";
        
        int choice; cin>>choice;
        
        switch(choice){
            case 1: manageDoctors(doctors); break;
            case 2: manageRooms(rooms); break;
            case 3: managePatients(patients, doctors, rooms); break;
            case 4: simulateTreatmentCycle(patients, rooms, doctors); break;
            case 5: runSimulation(patients, rooms, doctors); break;
            case 6: status = false; cout<<"Exiting system. Goodbye!\n"; break;
            default: cout<<"Invalid choice.\n";
        }
    }
    return 0;
}