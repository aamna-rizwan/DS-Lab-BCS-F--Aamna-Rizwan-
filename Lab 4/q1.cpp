#include <iostream>
using namespace std;

int main() {
  int n;
  int num;
  bool found = false;
  cout << "Enter number of elements\n";
  cin >> n;
  int *arr = new int[n]{};
  for(int i =0;i<n;i++){
      cout << "Enter element " << i+1 << endl;
      cin >> arr[i];
  }
  cout << "Enter the value you want to search for\n";
  cin >> num;
   for(int i =0;i<n;i++){
      if (found==false){
          if(arr[i]==num){
              cout << "Index of value :  " << i << endl;
              found=true;
              return 0;
          }
      }
  }cout << "not found!\n";
}
