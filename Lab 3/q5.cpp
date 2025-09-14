#include <iostream>
using namespace std;

class Single{
    public:
    int data;
    Single *next;
    
    Single(int val){
        data=val;
        next=NULL;
    }
};

class Double{
    public:
    int data;
    Double* next;
    Double* prev;
    Double(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
    
class Singly{
    Single* head;
    Single* tail;
    Singly(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        Single* n = new Single(val);
        if(head==NULL){
            head=n;
            tail=n;
        }else
        tail->next=n;
        tail=n
    }
    void display(){
        Single *temp=head;
        while(temp){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
    Double* convertD(){
        Single *temp=head;
        Double *dhead=new Double(temp->data);
        Double *dcurr=dhead;
        temp=temp->next;
        while(temp){
            Double *newNode=new Double(temp->data);
            dcurr->next=newNode;
            newNode->prev=dcurr;
            dcurr=newNode;
            temp=temp->next;
        }
        return dhead;
    }
    
    Single *convertC(){
        tail->next=head;
        return head;
    }
    void display(){
        Singly *temp=head;
        while(temp!=NULL){
            cout << temp->data << " "; 
        }
    }
};

int main() {
    Singly list;
    int n,val;
    cout << "Enter no. of elements in single list\n";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> val;
        list.insert(val);
    }
    cout << "single list : \n";
    list.display;
    Double *dhead=list.convertD();
    Single *shead=list.convertC();


}
