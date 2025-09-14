#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
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
    selectionSort(arr,n);
    cout << "\nafter sort;\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    
    delete[] arr;
}
