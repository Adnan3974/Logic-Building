#include<iostream>
#include<string>
using namespace std;

class Employee{
char* name;
string number;
string date;
public: 
Employee(char* n,string num, string d) : name(n),number(num){
name=new char[strlen(n)+1];
for(int i=0; i<strlen(n)+1; ++i){
name[i]=n[i];
}
}
//copy constructor
Employee(Employee& other){
other.number = number;
other.date = date;
other.name = new char[strlen(n)+1];
for(int i=0; i<strlen(n)+1; ++i){
name[i]=n[i];
}
}
//destructor
~Employee(){
delete name;
}

};

class Product : protected Employee{
int shift;
double hourlyPayRate;
public: 
Product(char* n,string num,string d,int s,double r) : Employee(n,num,d),shift(s),hourlyPatRate(r){};

double payRate(){
//day shift
if(shift==1){
return shift*hourlyPayRate*12;
}
//night shift (double pay)
if(shift==2){
return shift*hourlyPayRate*12;
}

}
};

void display(Product pro){
cout<<"Name: "<<pro->name<<endl;
cout<<"Employee No: "<<pro.number<<endl;
cout<<"Hire Date: "<<pro.date<<endl;
cout<<"Shift: "<<pro.shift<<endl;
cout<<"Hourly pay rate: "<<pro.hourlyPayRate<<endl;
cout<<"Total Amount Earned: "<<pro.payRate()<<endl;
}

int main(){

int count=0;
while(true){
cout<<"Enter name: ";
string name;
cin>>name;
cout<<"Enter employee no.";
string no;
cin>>no;
cout<<"Enter Hire date format: (23/3/2005) ";
string date;
cin>>date;
cout<<"Enter shift day(1) or night(2): ";
int shift;
cin>>shift;
cout<<"Enter Hourly Pay Rate: ";
double rate;
cin>>rate;
Product* pro[count] = new Product(&name,no,date,shift,rate);
cout<<"Do you want to continue(Y/N): ";
char flag;
cin.get(flag);

if(flag=='N' || flag=='Y')
break;
else
count++;

}
}





