#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node* link;
    Node(T v) {
        data = v;
        link = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T>* top;
public:
Stack():top(nullptr){}
~Stack() {
    while(!isEmpty()) {
        Node<T>* temp=top;
        top=top->link;
        delete temp;
    }
}
bool isEmpty() {
    return top==nullptr;
}

void push(T x) {
    Node<T>* n = new Node<T>(x);
    if(!n) {
        cout << "Heap is full!" << endl;
        return;
    }
    n->link = top;
    top = n; 
}
void pop() {
    if(isEmpty()) return;
    Node<T>* temp =top;
    top = top->link;
    delete temp;
}

T peek() {
    return top->data;
}
};

bool isRightAssociative(char c) {return c=='^';}

int precedence(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '*' || c == '/') {
        return 2;
    }
    else if(c == '+' || c == '-') {
        return 1;
    }
    else return -1;
}

string toPreFix(const string& infix) {
    string revInfix = infix;
    std::reverse(revInfix.begin(), revInfix.end());
    for(char &c : revInfix) {
        if(c=='(') c = ')';
        else if(c==')') c= '(';
    }
    string prefix = ""; 
    Stack<char> s;

    for(char c: revInfix) {
        if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')) {
            prefix += c;
        }
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                char op = s.peek();
                prefix += op;
                s.pop();
            }
            if (!s.isEmpty() && s.peek()=='(') { s.pop(); }
        }
        else {
            while(!s.isEmpty() && s.peek() != '(' && (precedence(c) < precedence(s.peek()) || (precedence(c) == precedence(s.peek()) && isRightAssociative(c)))) {
                char op = s.peek();
                prefix += op;
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()) {
        char op = s.peek();
        prefix += op;
        s.pop();
    }
    std::reverse(prefix.begin(), prefix.end());
    return prefix;
}

int applyOp(int a, int b, char op) {
    switch (op)
    {
    case '+': return a+b;
    case '-': return a-b;
    case '*': return a*b; 
    case '/': return a/b; 
    case '^': return static_cast<int>(pow(a, b)); 
    default: return 0;
    }
}

int evaluate(const string& prefix) {
    Stack<int> s;

    for(int i=prefix.length()-1; i>=0; i--) {
        if(prefix[i] >= '0' && prefix[i] <='9') { s.push(prefix[i] - '0'); }
        else {
            if(s.isEmpty()) return 0;
            int op1 = s.peek(); 
            s.pop();
            if(s.isEmpty()) return 0;
            int op2 = s.peek(); 
            s.pop();
            int res = applyOp(op1, op2, prefix[i]);
            s.push(res);
        }
    }
    if(s.isEmpty()) return 0;
    return s.peek();
}

int main()
{
    string infix;
    cout << "Enter infix (single digit num for evaluation): ";
    cin >> infix;
    string prefix = toPreFix(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Result: " << evaluate(prefix) << endl;
    return 0;
}
