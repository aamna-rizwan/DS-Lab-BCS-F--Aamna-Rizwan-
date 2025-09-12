#include <iostream>
using namespace std;
int main() {
    int CEO = 0;
    int CTO = 1;
    int CFO = 2;
    int VP = 3;
    int MGR = 4;
    int EMP = 5;
    int n = 8;
    int arr[n] = {EMP,CFO,MGR,EMP,VP,CTO,MGR,CEO};
    for (int i=1;i<n;i++) {
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    string d;
    cout << "After sort" << endl;
    for(int i=0;i<n;i++) {
       if(arr[i]==0) d="CEO";
       else if(arr[i]==1) d="CTO";
       else if(arr[i]==2) d="CFO";
       else if(arr[i]==3) d="VP";
       else if(arr[i]==4) d="MGR";
       else if(arr[i]==5) d="EMP";
       cout << d << endl;
    }
}
