#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    public: 
    vector<int> heap;
    int parent(int i){return (i-1)/2;}
    int leftChild(int i){return (2*i)+1;}
    int rightChild(int i){return (2*i)+2;}
    
    void heapifyUp(int i){
        while( i>0 && heap[parent(i)] < heap[i]){
            swap(heap[i],heap[parent(i)]);
            i=parent(i);
        }
    }
    
    void heapifyDown(vector<int> &arr,int n,int i){
        int largest =i;
        int left = leftChild(i);
        int right = rightChild(i);
        if(left<n && arr[left] > arr[largest]){
            largest=left;
        }if(right<n && arr[right] > arr[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapifyDown(arr,n,largest);
        }
    }

    
    bool isHeap(const vector<int> &arr){
        int n=arr.size();
        for(int i=0;i<=(n/2)-1;i++){
            int left=2*i+1;
            int right=2*i+2;
            if(left<n && arr[left]>arr[i]){
                return false;
            }
            if(right<n && arr[right]>arr[i]){
                return false;
            }
        }return true;
    }
    void heapSort(vector<int> &arr){
        int n=arr.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapifyDown(arr,n,i);
        }
        
        for(int j=n-1;j>0;j--){
            swap(arr[0],arr[j]);
            heapifyDown(arr,j,0);
        }
    }
};

int main() {
    MaxHeap heap;
    vector<int> num ={8,7,6,5,4};
    if(heap.isHeap(num)){
        for(int x:num){
        cout << x << " " ;
        }cout << endl;
    }else
    cout << "not a max heap" << endl;
    
    heap.heapSort(num);
     for(int x:num){
        cout << x << " " ;
        }cout << endl;

}
