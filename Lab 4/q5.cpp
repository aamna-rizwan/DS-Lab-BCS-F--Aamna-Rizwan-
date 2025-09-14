#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int interpolationSearch(int arr[], int n, int key) {
    int low=0, high=n-1;
    while (low<=high && key>=arr[low] && key<=arr[high]) {
        if(low==high){
            if(arr[low]==key) return low;
            return -1;
        }
        int pos=low+((double)(high-low)/(arr[high]-arr[low])) *(key - arr[low]);
        if (arr[pos]==key)
            return pos;
        if (arr[pos]<key)
            low=pos+1;
        else
            high=pos-1;
    }

    return -1;
}

int main(){
    int n;
    cout << "enter no. of elements\n";
    cin >> n;
    int *arr=new int[n]{};
    for(int i=0;i<n;i++){
        cout << "Enter element " << i+1 << endl;
        cin >> arr[i];
    }
    cout << "before sort:\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    bool found=false; 
    int val;
    insertionSort(arr,n);
    cout << "\nafter sort:\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\nEnter value to search\n";
    cin >> val;
    int result = interpolationSearch(arr,n,val);
    if(result!=-1){
        cout << "element found at" << result << endl;
    }else
    cout << "element not found\n";
    
    delete[] arr;
}
