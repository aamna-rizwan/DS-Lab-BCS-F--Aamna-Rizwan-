#include <iostream>
#include <vector>
using namespace std;

    int parent(int i){return (i-1)/2;}
    int leftChild(int i){return (2*i)+1;}
    int rightChild(int i){return (2*i)+2;}
    
    
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

    void convert(vector<int> &arr){
        int n=arr.size();
        for(int i=(n/2)-1;i>=0;i--){
            heapifyDown(arr,n,i);
        }
    }
    void display(vector<int> arr){
        for(int val:arr){
       cout << val << " " ;
   }cout << endl;
    }


int main() {
   vector<int> arr = {3,5,9,6,8,20,10,12,18,9};
   cout << "Original array : " << endl;
   display(arr);
   convert(arr);
   cout << "Converted array : " << endl;
   display(arr);
   

}
