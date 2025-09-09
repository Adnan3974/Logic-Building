#include<iostream>
using namespace std;

void display(int* arr, int size){
for(int i=0; i<size; ++i){
cout<<*(arr+i)<<" ";
}
}

bool checkSum(int* arr,int size,int guess){
int result=0;
for(int i=0; i<size; ++i){
result+=*(arr+i);
}
return (result=guess);
}

void swap(int* arr, int size){
for(int i=0; i<size-1; ++i){
for(int j=i+1; j<size; ++j){
int temp=*(arr+i);
*(arr+i)=*(arr+j);
*(arr+j)=temp;
}
}
}

 
int main(){
cout<<"Enter size of array: ";
int size; 
cin>>size;

while(size%2!=0){
cout<<"Invalid size (Enter even): ";
cin>>size;
}
int arr[size];
cout<<"Enter elements of array: ";
for(int i=0; i<size; ++i){
cin>>arr[i];
}

void (*FuncPtr) (int*,int);

FuncPtr=display(arr,size);

cout<<"Enter the number to check sum: ";
int num;
cin>>num;
bool (*FuncPtr2) (int*,int,int);
FuncPtr2=checkSum(arr,size,num);

if(FuncPtr){
cout<<"Fantastic shot! Sum is equal";
}
else{
cout<<"Ohh! Invalid sum (Have another shot)";
}

void (*FuncPtr3) (int*,int);
FuncPtr3=swap(arr,size);

return 0;
}
