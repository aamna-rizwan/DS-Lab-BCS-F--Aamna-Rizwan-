#include <iostream>
#include <vector>
using namespace std;

struct Task {
    int id;
    int prio; 
    Task(int i, int p) {
        id = i;
        prio = p;
    }
};

class QNode {
public:
    Task t;
    QNode* next;
    QNode(Task tt) : t(tt) {
        next = NULL;
    }
};

class MyQueue {
    QNode* front;
    QNode* back;
public:
    MyQueue() {
        front = NULL;
        back = NULL;
    }
    bool empty() {
        return front == NULL;
    }
    void add(Task t) {
        QNode* n = new QNode(t);
        if (!n) {
            cout << "No memory\n";
            return;
        }
        if (back == NULL) {
            front = back = n;
        } else {
            back->next = n;
            back = n;
        }
    }
    Task remove() {
        if (empty()) {
            cout << "Queue empty!\n";
            return Task(-1, -1);
        }
        QNode* temp = front;
        Task t = front->t;
        front = front->next;
        if (front == NULL) back = NULL;
        delete temp;
        return t;
    }
    void show() {
        QNode* temp = front;
        while (temp != NULL) {
            cout << "Task " << temp->t.id << " prio " << temp->t.prio << endl;
            temp = temp->next;
        }
    }
};

class Node {
public:
    Task t;
    Node* next;
    Node(Task tt) {
        t = tt;
        next = NULL;
    }
};

class MyStack {
    Node* top;
public:
    MyStack() {
        top = NULL;
    }
    bool empty() {
        return top == NULL;
    }
    void push(Task t) {
        Node* n = new Node(t);
        if (!n) {
            cout << "No memory\n";
            return;
        }
        n->next = top;
        top = n;
    }
    Task pop() {
        if (empty()) {
            cout << "Stack empty!\n";
            return Task(-1, -1);
        }
        Node* temp = top;
        Task t = top->t;
        top = top->next;
        delete temp;
        return t;
    }
    void show() {
        Node* temp = top;
        while (temp != NULL) {
            cout << "Task " << temp->t.id << " prio " << temp->t.prio << endl;
            temp = temp->next;
        }
    }
};
void doScheduler() {
    MyQueue q;
    MyStack s;
    q.add(Task(1, 5));
    q.add(Task(2, 8));
    q.add(Task(3, 3));
    q.add(Task(4, 7));
    q.add(Task(5, 2));
    cout << "Arrived:\n";
    q.show();
    vector<Task> all;
    while (!q.empty()) {
        all.push_back(q.remove());
    }
    for (int i = 0; i < all.size() - 1; i++) {
        for (int j = i + 1; j < all.size(); j++) {
            if (all[i].prio < all[j].prio) {
                Task temp = all[i];
                all[i] = all[j];
                all[j] = temp;
            }
        }
    }

    for (int i = 0; i < all.size(); i++) {
        s.push(all[i]);
    }

    cout << "\nExecution order:\n";
    s.show();
}

int main() {
    doScheduler();
    return 0;
}
