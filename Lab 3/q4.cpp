#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int val){
        data=val;
        next=NULL;
    }

};

class Circular{
    public:
    Node *head;
    Node *tail;
    
    Circular(){
        head=NULL;
        tail=NULL;
    }
    void display(){
    Node *temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
    }
    void insertAtEnd(int val){
        Node *n=new Node(val);
        if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        tail->next=n;
        tail=tail->next;
        tail->next=head;
    }
    void insertAtFront(int val){
        Node *n=new Node(val);
           if(head==NULL){
            head=n;
            tail=n;
            tail->next=head;
        }
        tail->next=n;
        n->next=head;
        head=n;
    }
    int pos(int k){
        Node *curr=head;
        Node *prev=tail;
        while(curr->next!=curr){
            for(int i=1;i<k;i++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            if(curr==head){
                head=curr->next;
            }
            delete curr;
            curr=prev->next;
        }
        return curr->data;
    }
};

int main() {
    Circular list;
    int n, val;
    cout << "enter no. of elements for list : \n";
    cin >> n;
    for(int i=0;i<n;i++){
        list.insertAtEnd(i);
    }
    int k;
    cout << "enter k\n";
    cin >> k;
    int position = list.pos(k);
    cout << "\nposition : \n" << position;

}
