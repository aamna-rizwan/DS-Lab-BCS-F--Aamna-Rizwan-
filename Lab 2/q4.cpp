#include <iostream>
using namespace std;

int *resizeArray(int *oldArr, int oldSize, int newSize){
    if(newSize==oldSize){return oldArr;}
    int *newArr = new int[newSize]{};
    int limit;
    if(oldSize<newSize){
        limit=oldSize;
    }else limit=newSize;
    for(int i=0;i<limit;i++){
        newArr[i]=oldArr[i];
    }
    delete[] oldArr;
    return newArr;
}


int main(){
    int n;
    cout << "Enter number of months\n";
    cin >> n;
    int* arr = new int[n]{};
    for(int i=0;i<n;i++){
        cout << "Enter expense for month " << i+1 << endl;
        cin >> arr[i];
    }
    cout << "Expenses entered :\n";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    int choice;
    cout << "do you want to resize or exit, press 2 to resize or 3 to exit\n";
    cin >> choice;
    if(choice==3){
        return 0;
    }else
    cout << "Enter number for new size\n";
    int newSize;
    cin >> newSize;
    arr=resizeArray(arr,n,newSize);
     for(int i=n;i<newSize;i++){
        cout << "Enter expense for month " << i+1 << endl;
        cin >> arr[i];
    }
    cout << "Expenses entered :\n";
    for(int i=0;i<newSize;i++){
        cout << arr[i] << " ";
    }
    

}
