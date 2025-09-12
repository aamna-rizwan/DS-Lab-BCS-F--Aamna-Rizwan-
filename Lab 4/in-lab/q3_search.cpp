#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x){
    int low=0;
    int high=n-1;
    while(low<=high && x>=arr[low] && x<=arr[high]){
        if(low=high){
            if(arr[low]==x) return low;
            return -1;
        }
        int pos = low +((x-arr[low])*(high-low))/arr[high]-arr[low];
        if (arr[pos]==x) return pos;
        if(arr[pos]<x) low=pos+1;
        else high = pos-1;
    }
    return -1;
}

int main() {
  int n;
  int num;
  cout << "Enter number of elements\n";
  cin >> n;
  int *arr = new int[n]{};
  for(int i =0;i<n;i++){
      cout << "Enter account balance " << i+1 << endl;
      cin >> arr[i];
  }
  cout << "before sort\n";
  for(int i =0;i<n;i++){
      cout << arr[i] << " " ;
  }
  for(int i=0;i<n;i++){
      for(int j=0;j<n-1;j++){
          if(arr[j]>arr[j+1]){
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1]=temp;
          }
      }
  }
   cout << "\nafter sort:\n";
  for(int i =0;i<n;i++){
      cout << arr[i] << " " ;
  }
  int x;
  cout << "\nenter value to search\n";
  cin >> x;
  int index = interpolationSearch(arr,n,x);
  cout << "Value at index " << index << endl;
  delete[] arr;

 
}
