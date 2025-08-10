#include<iostream>
using namespace std;
/*
Task:1
Read elements of a matrix and check whether identity or not.
*/

bool checkIdentity(int** arr, int rows, int cols){
bool identity=true;
for(int i=0; i<rows; i++){
for(int j=0; j<rows; j++){

if((i==j && arr[i][j]!=1)){
identity=false;
break;
}

if(i!=j && arr[i][j]!=0){
identity=false;
break;
}

}
}
return identity;
}

void get(int& n){
while(cin.fail()){
cin.clear();
cin.ignore(1000,'\n');
cout<<"Invalid data type! Re-Enter: ";
cin>>n;
}

}

int main(){
int rows,cols;
cout<<"Enter rows: ";
cin>>rows;
get(rows);

cout<<"Enter cols: ";
cin>>cols;
get(cols);

while(rows!=cols || rows<=0 || cols<=0){
cout<<"Rows and cols should be equal. Re-Enter: ";
cin>>rows>>cols;
}

int** array=new int*[rows];
for(int i=0; i<rows; i++){
array[i]=new int[cols];
}
cout<<"Enter elements of matrix:\n";
for(int i=0; i<rows; i++){
for(int j=0; j<cols; j++){
cin>>array[i][j];
}
}

cout<<"Display matrix:\n";
for(int i=0; i<rows; i++){
for(int j=0; j<cols; j++){
cout<<array[i][j]<<" ";
}
cout<<endl;
}

if(checkIdentity(array,rows,cols))
cout<<"Status = Identity";
else
cout<<"Status = Not Identity";

for(int i=0; i<rows; ++i){
delete array[i];
}

delete[] array;
array=nullptr;

return 0;
}
