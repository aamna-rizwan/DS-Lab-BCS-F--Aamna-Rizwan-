#include <iostream>
using namespace std;

int main(){
int bench, seat;
cout << "Enter benches\n";
cin >> bench;
cout << "Enter seats\n";
cin >> seat;

int **arr = new int *[bench];
for(int i=0;i< bench;i++){
    arr[i] = new int[seat];
}

cout << "enter 0 for unoccupied and 1 for occupied\n";
for(int i=0;i<bench;i++){
    for(int j=0;j<seat;j++){
        cout << "Enter for bench " << i+1 <<" and seat  " << j+1 << endl;
        cin >> arr[i][j];
    }
}

cout << "final form :\n";
for(int i=0;i<bench;i++){
    for(int j=0;j<seat;j++){ 
        cout << arr[i][j] << " ";
    }
    cout << endl;
}

for(int i=0;i<bench;i++){
    delete[] arr[i];
}
delete[] arr;

}

