#include <iostream>
using namespace std;
const int MAX = 10;
int front = -1;
int rear = -1;
int arr[MAX];

bool isFull(){
    return rear == MAX -1;
}
bool isEmpty(){
    return front == -1 || front > rear;
}

void enqueue(int val){
    if(isFull()){
        cout << "Queue is full\n";
        return;
    }
    if(front==-1){
        front=0;
    }
    rear=rear+1;
    arr[rear]=val;
}

void dequeue(){
    if(isEmpty()){
        cout << "Empty Queue\n";
        return;
    }
    int val = arr[front];
    cout << endl;
    cout << val << " dequeued" << endl;
    front=front+1;
}
void display(){
     if(isEmpty()){
        cout << "Empty Queue\n";
        return;
    }
    cout << "\nQueue : " ;
    for(int i=front;i<rear;i++){
        cout << arr[i] << " ";
    }
}

int main() {
  enqueue(14);
  enqueue(15);
  enqueue(16);
  display();
  dequeue();
  display();
}
