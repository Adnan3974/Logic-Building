#include<iostream>
using namespace std;
/*
You are given two integers `nums1` and `nums2` of lengths `m` and `n` respectively. 
Store the numbers in 2 arrays such that `arraynums1` and `arraynums2` represent the digits of two numbers. 
You are also given an integer `k`.  
Create the maximum number of length k<=m+n from digits of the two numbers. 
The order of the digits from the same array must be preserved.  
Return an array of the `k` digits representing the answer.  
**Example 1:**  
Input: nums1 = 3465, nums2 = 912583, k = 5  
Output: [9,8,6,5,3]  
**Example 2:**  
Input: nums1 = 67, nums2 = 604, k = 5  
Output: [6,7,6,0,4]  
**Example 3:**  
Input: nums1 = 39, nums2 = 89, k = 3  
Output: [9,8,9]
*/
void sum(int arr[], int s1, int arr2[], int s2){
    cout<<"\nEnter k: ";
    int k; cin>>k;
    int result[k];
    int max = arr[0];
    for(int i=0; i<k; ++i){
        for(int i=1; i<s1; ++i){
        if(arr[i]>max)
        max = arr[i];
        }
        for(int i=0; i<s2; ++i){
        if(arr2[i]>max)
        max = arr2[i];
        }
        result[i] = max;
    }
    cout<<"Max result: ";
    for(int i=0; i<k; ++i) cout<<result[i]<<" ";
}
int main(){
    cout<<"Enter size1 and size2: ";
    int s1, s2; cin>>s1>>s2;
    cout<<"Enter elements of arr1: ";
    int arr[s1], arr2[s2];
    for(int i=0; i<s1; ++i) 
    cin>>arr[i];
    cout<<"Enter elements of arr2: ";
    for(int i=0; i<s2; ++i) 
    cin>>arr2[i];
    cout<<"Arr1: ";
    for(int i=0; i<s1; ++i) cout<<arr[i];
    cout<<"\nArr2: ";
    for(int i=0; i<s2; ++i) cout<<arr2[i];
    sum(arr, s1, arr2, s2);
}