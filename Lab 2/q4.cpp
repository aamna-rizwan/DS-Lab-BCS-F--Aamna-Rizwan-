#include <iostream> //still in work
using namespace std;

int *resizeArray( int *old, int oldSize, int newSize){
    if(newSize==oldSize){
        return old;
    }
    int *newArr = new int[newSize];
    int limit;
    if(oldSize < newSize){
        limit=oldSize;
    }else{limit=newSize;}

    for(int i=0;i<limit;i++){
        newArr[i] = old[i];
    }
    
    delete[] old;
    return newArr;

}

int main(){
int n;
cout << "Enter number of months\n";
cin >> n;

int* arr=new int[n]{};
 for(int i=0;i<n;i++){
        cout << "Enter the value at position " << i+1 << endl;
        cin >> arr[i];
    }
cout << "original Array\n";
 for(int i=0;i<size ;i++){
        cout << arr[i] << ", " ;
    }
int num,size;
cout << "enter 1 to resize or enter 2 for not\n";
cin>>num;
if(num==1){
    cout << "enter new size\n";
    cin>>size;
    arr = resizeArray(arr,n, size);
    for (int i=n; i<size;i++){
        cin >> arr[i];
    }
    cout << "resized to bigger array\n";
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
        cout << "\n";
    }

}

delete[] arr;



}
