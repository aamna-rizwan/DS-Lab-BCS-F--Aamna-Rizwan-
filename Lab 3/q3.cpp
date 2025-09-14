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

class Singly{
    public:
    Node *head;
    Node *tail;
    
    Singly(){
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
    void insert(int val){
        Node *newNode = new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node *reversed(int k, Node *head){
        if(head==NULL){
            return NULL;
        }
        Node *curr=head;
        Node *prev=NULL;
        Node *next=NULL;
        int count =0;
        Node *temp=head;
        for(int i=0;i<k;i++){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
        }
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            head->next=reversed(k,next);
        }
        return prev;
    }
    
};


int main() {
    Singly list;
    int n, val;
    cout << "enter no. of elements for list : \n";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> val;
        list.insert(val);
    }
    list.display();
    int k;
    cout << "enter k\n";
    cin >> k;
    list.head=list.reversed(k,list.head);
    cout << "after k groups:\n";
    list.display();
}
