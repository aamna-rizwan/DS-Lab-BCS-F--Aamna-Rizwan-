#include <iostream>
#include <vector>
using namespace std;

    int parent(int i){return (i-1)/2;}
    int leftChild(int i){return (2*i)+1;}
    int rightChild(int i){return (2*i)+2;}
    void heapify(vector<int> &arr,int n,int i){
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
            heapify(arr,n,largest);
        }
    }
    
    int find(vector<int> arr,int k){
        int n =arr.size();
        if(k<=0 || k>n){
            cout << "invalid value of k" << endl;
            return -1;
        }
        //build heap
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
        //extract
        for(int i=n-1;i>=n-k+1;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
        return arr[0];
    }


int main() {
  vector<int> arr= {1, 23, 12, 9, 30, 2, 50};
  int n;
  cout << "Enter k" << endl;
  cin >> n;
  int result = find(arr,n);
  cout << n << " largest element : " << result << endl;
  
}
