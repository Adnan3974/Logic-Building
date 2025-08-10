#include<iostream>
using namespace std;
int main(){
int arr[10] {2,5,3,9,10,25,-3,0,1,12};
cout<<"Selection Sort\n";
cout<<"Before Sorting:\n";
for(int i=0; i<10; ++i){
    cout<<arr[i]<<" ";
}

for(int i=0; i<9; ++i){
    int minValue = arr[i];
    int minIndex = i;
    for(int j=i+1; j<10; ++j){
        if(arr[j]<minValue){
            minValue = arr[j];
            minIndex = j;
        }
    }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
}

cout<<"\nAfter Sorting:\n";
for(int i=0; i<10; ++i){
    cout<<arr[i]<<" ";
}
}
