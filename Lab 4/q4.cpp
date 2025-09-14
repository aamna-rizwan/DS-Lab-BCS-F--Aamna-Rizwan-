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
    cout << "\nenter value to search\n";
    cin >> val;
    for(int i=0;i<n;i++){
        while(!found){
        if(arr[i]==val){
            found=true;
            cout << "element " << val << "found at  " << i << endl;
            return 0;
        }
    }
    }
    cout << "element not found";
    
    delete[] arr;
}
