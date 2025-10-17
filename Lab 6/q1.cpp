#include <iostream>
using namespace std;

const int MAX = 50;

class Stack{
    int top;
    public : 
    int array[MAX];
    Stack(){
        top = -1;
    }
    bool push(int element){
        if(top >= MAX ){
             cout << "stack is full \n";
             return false;
        }
        top= top+1;
        array[top] = element;
        //array[++top] = element; samething
       
        cout << "Element " << element << " pushed into stack\n";
        return true;
    }
    
    int pop(){
        if(top < 0){
            cout <<"underflow : stack is empty\n";
            return 0;
        }
        int x = array[top];
        top = top - 1;
        return x;
    }
    
    int peek(){
        if(top < 0){
            cout <<"underflow : stack is empty\n";
            return 0;
        }
        int x = array[top];
        return x;
    }
    
     
    bool isEmpty(){
        return (top < 0);
    }
    int getTop(){
        return array[top];
    }
    void display()
    {
        if(isEmpty()==true){
            cout << "empty stack\n";
            return;
        }
        cout << "Elements from top to bottom:\n";
        while(!isEmpty()){
            cout << getTop() << " ";
            pop();
        }
    }
};

int main() {
    Stack s1;
    s1.push(5);
    s1.push(7);
    s1.push(8);
    s1.display();
}
