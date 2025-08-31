#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout << "Enter number of days\n";
    cin >> n;
    cout << "Enter number of different times of day\n";
    cin >> m;
    int **arr= new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        cout << "Enter data for day " << i+1 << endl;
        for(int j=0;j<m;j++){
            cout << "Enter data for time " << j+1 << endl;
            cin >> arr[i][j];
        }    
    }
    cout << "Average temperatures\n";
    int avg,max,min,cold,hot;
    for (int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            sum=sum+arr[i][j];
        }
        avg = sum/m;
        cout << "Day " << i +1 << " : " << avg << endl;
        if(i==0){
            max=avg;
            min=avg;
            cold=1;
            hot=1;
        }else {
            if (avg < min) {
                min = avg;
                cold = i + 1;
            }
            if (avg > max) {
                max = avg;
                hot = i + 1;
            }
    }
    }
    cout << "Coldest Day : " << cold << endl;
    cout << "Hottest Dat : " << hot << endl;
    
    
    for(int i=0;i<n;i++){
        delete[] arr[i];
    }
    delete[] arr;
    
}
