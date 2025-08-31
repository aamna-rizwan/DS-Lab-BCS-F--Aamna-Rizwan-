#include <iostream>
using namespace std;

int main(){
    int row,col;
    cout << "Enter rows\n"; cin >> row;
    cout << "Enter columns\n"; cin >> col;
    int **arr1 = new int*[row]{};
    for(int i=0;i<row;i++){
        arr1[i]=new int[col];
    }
    int **arr2 = new int*[row]{};
    for(int i=0;i<row;i++){
        arr2[i]=new int[col];
    }
    cout << "entering data for matrix 1\n";
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout << "Enter for row " << i+1 <<" and column  " << j+1 << endl;
        cin >> arr1[i][j];
    }
}
 cout << "entering data for matrix 2\n";
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout << "Enter for row " << i+1 <<" and column  " << j+1 << endl;
        cin >> arr2[i][j];
    }
}
cout << "Matrix 1 :\n";
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ 
        cout << arr1[i][j] << " ";
    }
    cout << endl;
}
cout << "Matrix 2 :\n";
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ 
        cout << arr2[i][j] << " ";
    }
    cout << endl;
}
int choice;
cout << "Enter 2 for addition and 3 for subtraction\n";
cin >> choice;
if(choice==2){
    cout << "you chose addition\n";
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ 
        cout << arr1[i][j] + arr2[i][j] << " ";
    }
    cout << endl;
    }
}else{
    cout << "you chose subtraction\n";
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ 
        cout << arr1[i][j] - arr2[i][j] << " ";
    }
    cout << endl;
}
}

for(int i=0;i<row;i++){
    delete[] arr1[i];
}
delete[] arr1;
for(int i=0;i<row;i++){
    delete[] arr2[i];
}
delete[] arr2;




}
