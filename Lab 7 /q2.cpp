#include <iostream>
using namespace std;

//radix sort
class Node{
    public:
    int data;
    Node *next;
    Node (int val): data(val),next(nullptr){}
};

void insert(Node *&head, int val){
    Node *newNode = new Node(val);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void clear(Node *head){
    Node *temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        delete temp;
    }
}

int getMax(int arr[], int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

void radixSortAsc(int arr[],int n){
    int max=getMax(arr,n);
    int expt=1;
    
    Node *buckets[10];
    
    while((max/expt) >0){
        for(int i=0;i<10;i++){
            buckets[i]=NULL;
        }
        for(int i=0;i<n;i++){
            int digit=(arr[i]/expt) %10;
            insert(buckets[digit],arr[i]);
        }
        
        int idx=0;
        for(int i=0;i<10;i++){
            Node *temp=buckets[i];
            while(temp!=NULL){
                arr[idx]=temp->data;
                idx++;
                temp=temp->next;
            }
            clear(buckets[i]);
        }
        expt=expt*10;
    }
}

void radixSortDesc(int arr[],int n){
    int max=getMax(arr,n);
    int expt=max;
    
    Node *buckets[10];
    
    while((max/expt) >0){
        for(int i=0;i<10;i++){
            buckets[i]=NULL;
        }
        for(int i=0;i<n;i++){
            int digit=(arr[i]/expt) %10;
            insert(buckets[digit],arr[i]);
        }
        
        int idx=0;
        for(int i=9;i>=0;i--){
            Node *temp=buckets[i];
            while(temp!=NULL){
                arr[idx]=temp->data;
                idx++;
                temp=temp->next;
            }
            clear(buckets[i]);
        }
        expt=expt*10;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}


int main() {
   int arr[] = {36, 987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
   int n = sizeof(arr)/sizeof(arr[0]);
   //before sort
   cout << "before : " << endl;
   printArray(arr,n);
   //after 
   cout << "after ascending sort : " << endl;
   radixSortAsc(arr,n);
   printArray(arr,n);
   cout << "after descending sort : " << endl;
   radixSortDesc(arr,n);
   printArray(arr,n);
}
