#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo + ((double)(hi-lo) / (arr[hi]-arr[lo])*(x-arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
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
  int index = interpolationSearch(arr,0,n-1,x);
  cout << "Value at index " << index << endl;
  delete[] arr;
 
}
