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
    Node *reverse (Node* head){
        Node *prev=NULL;
        Node *curr=head;
        while(curr!=NULL){
            Node *nextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }return prev;
    }
    bool palindrome(){
        Node *h=head;
        Node *t=head;
        while(h->next!=NULL && h->next->next!=NULL){
            t=t->next;
            h=h->next->next;
        }
    
    Node *second=reverse(t->next);
    Node *n1=head;
    Node *n2=second;
    bool r=true;
    while(n2!=NULL){
        if(n1->data!=n2->data){
            r=false;
            break;
        }
        n1=n1->next;
        n2=n2->next;
    }
    return r;
    }
};


int main() {
    Singly obj;
    int n, val;
    cout << "enter elements : \n";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> val;
        obj.insert(val);
    }
    obj.display();
    if(obj.palindrome()){
        cout << "\npalindrome\n";
    }else
    cout << "\nNot a palindrome\n";

}
