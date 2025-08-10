#include<iostream>
using namespace std;
int main(){
const int size=10;
int arr[size] =  {0,1,2,3,4,5,6,7,8,9};
//Easy because size is fixed
cout<<"Initial array: \n";
for(int i=0; i<size; ++i){
cout<<arr[i]<<" ";
}

for(int i=0; i<size/2; ++i){
int temp=arr[i]; 
arr[i]=arr[size-i-1];
arr[size-i-1]=temp;
}

cout<<"\nReversed array:\n";
for(int i=0; i<size; ++i){
cout<<arr[i]<<" ";
}

return 0;
}
