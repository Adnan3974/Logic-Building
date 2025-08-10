#include<iostream>
#include<vector>
using namespace std;

void unionOfArrays(int[], int, int[], int);

int main(){
int arr1[] = {2,5,34,4,1,6,03,2,4,06,5,7,9};
int arr2[] = {6,42,54,7,80,9,2,32,4,06,1,07,85,9,0};

cout<<"Union of arrays: ";

unionOfArrays(arr1,12,arr2,14);
return 0;
}

void unionOfArrays(int arr1[], int size1, int arr2[], int size2){
int size3=size1+size2;
int arr3[size3];
int k=0;

for(int i=0; i<size1; ++i){
bool found=false;
for(int j=0; j<k; ++j){
if(arr1[i]==arr3[j]){
found=true;
break;
}
}
if(!found)
arr3[k++]=arr1[i];
}

for(int i=0; i<size2; ++i){
bool found=false;
for(int j=0; j<k; ++j){
if(arr2[i]==arr3[j]){
found=true;
break;
}
}
if(!found)
arr3[k++]=arr2[i];
}

for(int i=0; i<k; ++i){
cout<<arr3[i]<<" ";
}
}
