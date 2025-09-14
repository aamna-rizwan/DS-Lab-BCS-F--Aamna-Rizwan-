#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *child;
    Node(int val){
        data=val;
        next=NULL;
        child=NULL;
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
        Node *newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    
    Node *flatten(Node *head){
        if(!head){
            return NULL;
        }
        Node *curr=head;
        while(curr){
            if(curr->child){
                Node *nextNode=curr->next;
                Node *childHead=flatten(curr->child);
                curr->next=childHead;
                Node* temp=childHead;
                while (temp->next){
                    temp=temp->next;
                }
                temp->next= nextNode;
                curr->child=NULL;
            }
            curr=curr->next;
        }
       return head;
    }
};

int main(){
    Singly list;
    int n,val;
    cout << "Enter no. of elements\n";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "enter element " << i+1 << endl;
        cin >> val;
        list.insert(val);
    }
    Node *second=list.head->next;
    second->child=new Node(4);
    second->child->next=new Node(5);
    list.display();
}
