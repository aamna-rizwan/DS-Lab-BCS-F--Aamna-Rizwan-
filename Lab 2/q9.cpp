#include <iostream>
using namespace std;

int main(){
    int row,col;
    cout << "Enter rows\n"; cin >> row;
    cout << "Enter columns\n"; cin >> col;
    int **arr = new int*[row]{};
    for(int i=0;i<row;i++){
        arr[i]=new int[col];
    }
    cout << "entering data for matrix \n";
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout << "Enter for row " << i+1 <<" and column  " << j+1 << endl;
        cin >> arr[i][j];
    }
}

cout << "Matrix  :\n";
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ 
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
cout << "Matrix in compressed form  :\n";
for(int i=0;i<row;i++){
    cout << "\nRow : " << i+1 << endl;
    for(int j=0;j<col;j++){ 
        cout << "\nColumn : " << j+1 << endl;
        if(arr[i][j]!=0){
        cout << "Value : " <<  arr[i][j] << " ";}
    }
    cout << endl;
}

for(int i=0;i<row;i++){
    delete[] arr[i];
}
delete[] arr;
}



