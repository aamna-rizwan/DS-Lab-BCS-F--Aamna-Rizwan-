#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Stack{
    public:
    Node *head;
    Stack(){head=nullptr;}
    
    void push(int data){
        Node *newNode = new Node(data);
        Node *temp = head;
        newNode->next = temp;
        head = newNode;
    }
    void pop(){
        if (head == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    void display(){
        if (head == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nfrom top to bottom\n";
        Node *temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp=temp->next;
        }
    }
};


int main() {
   Stack s;
   s.push(5);
   s.push(6);
   s.push(7);
   s.display();
   s.pop();
   s.display();
}
