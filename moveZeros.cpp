#include<iostream>
using namespace std;
/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the
non-zero elements.
Note that you must do this in-place without making a copy of the array.
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
*/

void moveZeros(int arr[],int s);
int main(){

cout<<"Enter size of array: ";
int size; 
cin>>size;
cout<<"Enter elements in array: ";
int arr[size];
for(int i=0; i<size; ++i)
cin>>arr[i];

moveZeros(arr,size);

for(int i=0; i<size; ++i)
cout<<arr[i]<<" ";

return 0;
}

void moveZeros(int arr[],int s){
for(int i=0; i<s-1; ++i){
for(int j=i+1; j<s; ++j){
if(arr[i] == 0){
int temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
}

