#include<iostream>
using namespace std;
/*
Write a program to print the following pyramid using loops.
Note: User enters number of rows only.
     1
    232
   34543
  4567654
 567898765
*/

void print(int);
int main()
{
cout<<"Enter no of rows: ";
int rows; cin>>rows;
while(rows<=0 || rows>5){
cout<<"Invalid rows! Re-Enter: ";
cin>>rows;
}
print(rows);
return 0;
}

void print(int rows){
if(rows==1){
cout<<"1";
return;
}

for(int i=1; i<=rows; ++i){
for(int j=i; j<=rows; ++j){
cout<<" ";
}

int num=i;

for(int k=1; k<=i; ++k){
cout<<num++;
}

num -= 2;
for (int j = 1; j <= i - 1; j++) {
cout << num--;
}

cout<<endl;
}

}
