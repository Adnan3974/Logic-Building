#include<iostream>
using namespace std;
int main(){
cout<<"==== Welcome to the Bus ====\n";
cout<<"Enter the number of rows in the bus: ";
int rows; 
cin>>rows;

while(cin.fail() || rows<0){
cout<<"Invalid choice!\n";
cout<<"Re-Enter: ";
cin>>rows;
}

int* array = new int[rows];
char ch='A';

for(int i=0; i<rows; ++i){
cout<<i+1;
for(int j=0; j<4; ++j){
cout<<" "<<ch++<<" ";
}
cout<<endl;
ch='A';
} 

while(true){
cout<<"Enter Row: ";
int row;
cin>>row;

while(cin.fail() || row<0 || row>rows){
cout<<"Invalid choice!\n";
cout<<"Re-Enter: ";
cin>>row;
}

cout<<"Enter seat (A,B,C,D)\n";
char seat;
cin>>seat;
while(seat!='A' || seat!='B' || seat!='C' || seat!='D'){
cout<<"Invalid seat!\nRe-Enter: ";
cin>>seat;
}

for(int i=1; i<=rows; ++i){
for(int j=0; j<4; ++j){

if(i==row && ch!='X')
ch='X';
else
cout<<"Seat is already booked\n";
} 
}

cout<<"Seat booked Successfully\n";
cout<<"Updated Seating\n";


cout<<"Do you want to continue (y/n)\n";
char status;
cin>>status;
if(status != 'Y' || status != 'y')
break;
}
return 0;
}






