#include<iostream>
using namespace std;
// Queues using arrays
struct Queue{
    int size;
    int *que;
    int front = -1;
    int rear = -1;
    Queue(int val){
        size = val;
        que = new int[size];
        front = -1;
        rear = -1;
    }
    void insert(int val){
        if(rear == size-1){
            cout<<"Queue is full!\n";
            return;
        }
        if(front == -1){
        front++; rear++;
        que[front] = val;
        }
        else{
            rear++;
            que[rear]=val;
        }
    }
    void remove(){
        if(rear == -1){
            cout<<"Queue is empty!\n";
            return;
        }
        que[rear] = -1;
        rear--;
    }
    void display(){
        for(int i=0; i<rear; ++i){
            cout<<que[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    cout<<"Enter size of the queue: ";
    int s; cin>>s;
    Queue que(s);
    cout<<"Entering elements in Queue: ";
    for(int i=12; i<=20; ++i){
        que.insert(i);
    }
    que.display();
    cout<<"After removing 2 elements: ";
    que.remove();
    que.remove();
    que.display();
}