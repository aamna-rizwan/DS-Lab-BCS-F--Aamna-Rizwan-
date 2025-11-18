#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
    private: 
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
    
    void heapifyDown(int i){
        int largest =i;
        int left = leftChild(i);
        int right = rightChild(i);
        if(left < heap.size() && heap[left] > heap[largest]){
            largest=left;
        }if(right<heap.size() && heap[right] > heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i],heap[largest]);
            heapifyDown(largest);
        }
    }
    
    
    public:
    void buildHeap(vector<int> arr){
        heap=arr;
        for(int i = (heap.size()/2) -1;i>=0;i--){
            heapifyDown(i);
        }
    }
    
    void update_key(int i, int new_val){
        if(i<0 || i>=heap.size()){
            cout << "invalid" << endl;
            return;
        }
        int old = heap[i];
        heap[i] = new_val;
        if(new_val > old) heapifyUp(i);
        else heapifyDown(i);
    }
    
    void deleteElement(int i){
        if(i<0 || i>=heap.size()){
            cout << "inavlid" << endl;
            return;
        }
        heap[i]=heap.back();
        heap.pop_back();
        heapifyUp(i);
        heapifyDown(i);
    }
    void display(){
        for(int val:heap){
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxHeap heap;
    vector<int> num ={8,7,6,5,4};
    heap.buildHeap(num);
    heap.display();
    heap.update_key(2,1);
    heap.display();
    heap.deleteElement(1);
    heap.display();

}
