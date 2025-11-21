#include <iostream>
using namespace std;

struct Runner{
    int time;
    string name;
};
//merge sort
void merge(Runner arr[],int left,int right, int mid){
    int n1=mid-left+1;
    int n2=right-mid;
    Runner L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        R[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=left;
    while(i<n1 && j<n2){
        if(L[i].time<=R[j].time){
            arr[k]=L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
        while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
     while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(Runner arr[],int left, int right){
    if (left<right){
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}


int main(){
  Runner runs[10];
  for(int i=0;i<10;i++){
      cout << "Enter name and finish line for runner " << i+1 << " : " ;
      cin >> runs[i].name;
      cin >> runs[i].time;
      cout << endl;
  }
 mergeSort(runs,0,9);
 for(int i=0;i<5;i++){
     cout << runs[i].name << " " << runs[i].time << endl;
 }
}
