#include<iostream>
using namespace std;

class Node{
public: 
int data;
Node* next;
};

class Stack{
Node* top;
Node* head;
public:
Stack(){
	top = NULL;
}
bool isEmpty(){
	return top->data == -1;
}
void push(int x){
	top->data = x;
	top->next = NULL;
	head->next = top;
}
int pop(){
	if(isEmpty()){
		cout<<"Stack empty!";
		return 0;
	}
	Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	top->next = temp;
	int val = top->data;
	delete temp;
	temp = NULL;
	return val;
}
void display(){
	Node* temp = head;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}
};

int main(){
	Stack stack;
	for(int  i=0; i<10; ++i){
	stack.push(i+12);	
	}
	cout<<"After pushing 10 elements\n";
	stack.display();
	cout<<"popping elements: \n";
	for(int i=0; i<4; ++i){
		cout<<stack.pop()<<" ";
	}
	cout<<"After pop out of 4 elements\n";
	stack.display();
	return 0;
}