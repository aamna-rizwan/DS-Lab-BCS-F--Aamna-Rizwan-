#include <iostream>
using namespace std;

int main(){
    int size;
    cout << "enter the size\n";
    cin >> size;
    int *arr = new int[size]{}; //curly brackets sey zero intialize hogya
    for(int i=0;i<size;i++){
        cout << "Enter the value at position " << i+1 << endl;
        cin >> arr[i];
    }
    cout << "You entered:\n";
    for(int i=0;i<size;i++){
        cout << arr[i] << ", " ;
    }

    delete[] arr;

}
