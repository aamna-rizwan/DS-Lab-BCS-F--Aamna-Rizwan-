#include <iostream>
using namespace std;

class MaxHeap{
    private: 
    int *arr;
    int capacity;
    int size =0;
    public:
    MaxHeap(int c) : capacity(c){
        arr = new int[capacity];
    }
    int parent(int i) {return(i-1)/2;}
    int left(int i) {return(2*i+1);}
    int right(int i) {return(2*i+2);}
    
    void heapify_up(int i){
        while(i!=0 && arr[i]>arr[parent(i)]){
            int temp = arr[i];
            arr[i]=arr[parent(i)];
            arr[parent(i)] = temp;
            i=parent(i);
        }
    }
    
    void insert(int val){
        if(size>=capacity){
            cout << "Overflow" << endl;
            return;
        }
        arr[size]=val;
        heapify_up(size);
        size++;
    } 
    
    void heapify_down(int i){
        int largest=i;
        int l =left(i);
        int r = right(i);
        
        if(l<size && arr[l] > arr[largest])
        largest = 1;
        if(r<size && arr[r] > arr[largest])
        largest = r;
        
        if(largest!=i){
            int temp = arr[i];
            arr[i]=arr[largest];
            arr[largest] = temp;
            heapify_down(largest);
        }
    }
    
    void update_key(int i, int new_val){
        if(i>=capacity){
            cout << "overflow" << endl;
            return;
        }
        arr[i]=new_val;
    }
    
    void delete_val(int arr[],int i){
        int num = arr[size];
        int temp=arr[0];
        arr[0]=arr[size];
        arr[size]=temp;
    
        heapify_down(i);
    }
    
    
};

int main() {
   
}
