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
    Node *merge(Node *head1,Node *head2){
        Node *mergeNode = NULL;
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        if(head1->data<=head2->data){
            mergeNode=head1;
            mergeNode->next=merge(head1->next,head2);
        }else{
            mergeNode=head2;
            mergeNode->next=merge(head1,head2->next);
        }
        return mergeNode;
    }
    
};


int main() {
    Singly list1;
    Singly list2;
    int n1,n2, val;
    cout << "enter no. of elements for list1 : \n";
    cin >> n1;
    for(int i=0;i<n1;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> val;
        list1.insert(val);
    }
    cout << "enter no. of elements for list2 : \n";
    cin >> n2;
    for(int i=0;i<n2;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> val;
        list2.insert(val);
    }
    list1.display();
    list2.display();
    Singly merged;
    merged.head= merged.merge(list1.head,list2.head);
    cout << "\nafter merge \n";
    merged.display();
}
