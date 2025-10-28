
#include <iostream>
using namespace std;

class CircularQueue {
    private:
    int front;
    int rear;
    int size;
    int cap;
    public:
    CQueue(int maxSize) {
        cap = maxSize;
        size = 0;
        front = -1;
        rear = -1;
    }
    
    int *a = new int[cap];
    bool isEmpty() {
        return (front==-1 && rear==-1);
    }
    bool isFull() {
        return ((rear+1)%cap == front);
    }
    void enqueue(int x) {
        if(isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        else if(isEmpty()) { front=rear=0; }
        else { rear = (rear+1)%cap; }
        a[rear] = x;
        size++;
    }
    int dequeue() {
        int x = 0;
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return x;
        }
        else if(front == rear) {
            x = a[front];
            front = rear= -1;
        }
        else {
            x = a[front];
            front = (front+1)%cap;
        } 
        size--;
        return x; 
    }
    void display() {
        if(isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        int i = front;
        for(int k=0; k<size; k++) {
            cout << a[i] << " ";
            i = (i+1)%cap;
        }
    }

    ~CircularQueue() {
        delete[] a;
    }
};

int main()
{
    CircularQueue q(5);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    q.enqueue(13);
    q.display();
    cout << "\nDequeuing" << endl;
    cout << "Removing: " << q.dequeue() << endl;
    cout << "Queue: " << endl;
    q.display();
    cout << "\nEnqueuing " << endl;
    q.enqueue(5);
    cout << "Queue: " << endl;
    q.display();
    return 0;
}
