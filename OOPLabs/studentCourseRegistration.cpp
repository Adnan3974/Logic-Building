#include<iostream>
#include<vector>
using namespace std;

const int MAX_COURSES = 5;
const int MAX_STUDENTS = 10;
const int MAX_INSTRUCTORS = 5;
 
class Student{
string name;
string ID;
string email;
Courses* registeredCourses[MAX_COURSES];
public: 
Student(string n="",string id="",string e=""):name(n),ID(id),email(e){
for(int i=0; i<MAX_COURSES; ++i){
registeredCourses[i]=nullptr;
}
}

string getName(){
return name;
}

string getID(){
return ID;
}

string getEmail(){
return email;
}

};

class Course{
string title;
string code;
string description;

Student* enrolledStudents[MAX_STUDENTS];
Instructor* assignedInstructors[MAX_INSTURCTORS];

public: 
Course(string t="",string c="", string des=""):title(t),code(c),description(des){
for(int i=0; i<MAX_STUDENTS; ++i){
enrolledStudents[i]=nullptr;
assignedInstructors[i]=nullptr;
}
}

string getTitle(){
return title;
}

string getCode(){
return code;
}

string getDescription(){
return des;
}

};

class Instructor{
string name;
string ID;
string experties;
Courses* assignedCourses[MAX_COURSES];

public: 
Student(string n="",string id="",string e=""):name(n),ID(id),experties(e){
assignedCourses[i];
}

string getName(){
return name;
}

string getID(){
return ID;
}

string getExperties(){
return experties;
}

};

void registerCourse(){

}

void displayStudentDetails(Student stu){
cout<<"Name: "<<stu.name<<endl;
cout<<"ID: "<<stu.ID<<endl;
cout<<"Email: "<<stu.email<<endl;

}

int main(){
while(true){
cout<<"1. Register a Student\n"
<<"2. Register an Instructor\n"
<<"3. Register a Course\n";
int choice;
cin>>choice;

vector<Student>stu;
vector<Instructor>ins;
vector<Course>cou;

switch(choice){
case 1:
{
cout<<"Enter name: ";
string name;
getline(cin,name);
cout<<"Enter  ID: ";
string id;
cin>>id;
cout<<"Enter email: ";
string email;
cin>>email;
cout<<"\nStudent Registered Successfully!\n";
stu.emplace_back(name,id,email);
}
break;

case 2:
{
cout<<"Enter name: ";
string name;
getline(cin,name);
cout<<"Enter  ID: ";
string id;
cin>>id;
cout<<"Enter Expertise: ";
string exp;
getline(cin,exp);
ins.emplace_back(name,id,exp);
}
break;

case 3:
{ 
cout<<"Enter course title: ";
string title;
cout<<"Enter code: ";
string code;
getline(cin,code);
cout<<"Enter description: ";
string des;
getline(cin,des);
cou.emplace_back(title,code,des);
}

cout<<"\nDo you want to continue (Y/N) ?\n";
char status;
cin.get(status);
while(status!='Y' || status!='N'){
cout<<"Invalid input!";
cin.get(status);
}

if(status=='N'){
break;
}

}





return 0;
}

















