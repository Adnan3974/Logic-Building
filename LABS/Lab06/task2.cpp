#include<iostream>
using namespace std;

int mltply(int a,int b){
if(b<=0){
    return 0;
}
return a+=mltply(a,b-1); //only using + operator for *
}

int main(){
    cout<<"Enter two numbers: \n";
    int a,b; cin>>a>>b;
    while(a<0 || b<0){
        cout<<"Ivnalid input: ";
        cin>>a>>b;
    }
    cout<<"\n"<<"Result: "<<mltply(a,b);
    return 0;
}
/*
5*6
*/