#include<iostream>
using namespace std;

void Functions(char);

int main(){
cout<<"Enter a letter: ";
char ch;
cin.get(ch);
Functions(ch);
return 0;
}

void Functions(char ch){
if(isupper(ch)) 
cout<<"Upper\n";
else 
cout<<"!Upper\n";
if(isalnum(ch))
cout<<"Letter or Number\n";
else 
cout<<"!Letter or Number\n";
if(isalpha(ch))
cout<<"Alpha\n";
else
cout<<"!Alpha\n";
if(islower(ch))
cout<<"Lower\n";
else
cout<<"!Lower\n";
if(isprint(ch))
cout<<"Is printable\n";
else 
cout<<"!Is printable\n";
if(isspace(ch))
cout<<"Space\n";
else
cout<<"!Space";
}

