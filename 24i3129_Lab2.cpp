#include<iostream>
using namespace std;
class Book{
string title;
string ISBN;
string author;
int quantity;
public: 
Book(string t="", string isb="", string n="", int q=0) : title(t),ISBN(isb),author(n),quantity(q){};
};

class Inventory{
int count;
public: 
Inventory(Book* book=nullptr, int count=0){
book=new Book[count];
};

~Inventory(){
delete book;
}

void Add(){

while(true){
cout<<"Enter Book's title: ";
string t;
getline(t);
cout<<"Enter ISBN: ";
string isb;
getline(isb);
cout<<"Enter Author's name: ";
string name;
getline(name);
cout<<"Enter quantity of the books to be added: ";
int q;
cin>>q;
while(q<0){
cout<<"Sorry! Invalid quantity, Re-Enter: ";
cin>>q;
}

for(int i=0; i<count+q; ++i){
Book* book[count++]=new Book(t,isb,name,q);
}

cout<<"Do you want to continue(Y/N)";
char flag;
cin.get(flag);
if(flag=='N'){
break;
}
}
}

void Sell(Book* book){
while(true){
cout<<"Enter Book's title: ";
string t;
getline(t);
cout<<"Enter ISBN: ";
string isb;
getline(isb);
cout<<"Enter Author's name: ";
string name;
getline(name);
cout<<"Enter quantity of the books to be added: ";
int q;
cin>>q;
while(q<0){
cout<<"Sorry! Invalid quantity, Re-Enter: ";
cin>>q;
}
for(int i=0; i<count; ++i){
if(book[i].title==t){
book[i]=nullptr;
count--;
}
}
cout<<"Do you want to continue(Y/N)";
char flag;
cin.get(flag);
if(flag=='N'){
break;
}
}
}

void display(Book* book){
for(int i=0; i<count; ++i){
cout<<"Title: "<<book[i].title<<"\n"
<<"ISBN"<<book[i].ISBN<<"\n"
<<"Author's name: "<<book[i].author<<"\n"
<<"Quantity: "<<book[i].quantity<<"\n"
}
}

void search(string t){
for(int i=0; i<count; ++i){
if(book[i].title==t){
cout<<"Available!"
}
}
cout<<"Not Available";
}

void deletebook(string){
for(int i=0; i<count; ++i){
if(book[i].title==t){
book[i]=nullptr;
count--;
}
}
}

void reporting(){
for(int i=0; i<count; ++i){
cout<<"Title: "<<book[i].title<<"\n"
<<"ISBN"<<book[i].ISBN<<"\n"
<<"Author's name: "<<book[i].author<<"\n"
<<"Quantity: "<<book[i].quantity<<"\n"
}
}
};


int main(){
Inventory invent;
cout<<"Enter your choice from below to procede\n"
<<"1. Add\n"
<<"2. delete\n"
<<"3. display\n"
<<"4. search\n"
<<"5. reporting\n"
<<"6. sell\n";
int choice; 
cin>>choice;
while(choice<1 || choice>6){
cout<<"Invalid value! Re-Enter: ";
cin>>choice;
}

switch(choice){
case 1: 
	invent.Add();
	break;
case 2: 
{
	cout<<"Enter title of the book to delete: ";
	string n;
	getline(n);
	invent.deletebook(n);
}
	break;
case 3: 
	invent.display();
	break;
case 4: 
{
	cout<<"Enter title of the book to delete: ";
	string n;
	getline(n);
	invent.search();
}
	break;
case 5: 
	invent.report();
	break;
case 6:
{
	cout<<"Enter title of the book to delete: ";
	string n;
	getline(n);
	invent.sell(n)
}
	break;
default: 
cout<<"Invalid choice\n";
}


return 0;
}
