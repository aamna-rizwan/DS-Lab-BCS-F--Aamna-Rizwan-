#include <iostream>
using namespace std;

void sorting(vector<int> arr, int k){
    if(k==0){
        return;
    }
    int i=0;
    int max=arr[0];
    if(max>arr[i]){
        max=arr[i];
        i++
    }
    arr.pop_back()
    sorting(arr[],k-1);
}
}
