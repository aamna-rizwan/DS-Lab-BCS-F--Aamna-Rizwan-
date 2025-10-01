#include <iostream>
using namespace std;

int sumTail(int n, int total=0){
    if(n==0){
        return total;
    }
    return sumTail(n-1,total+n);
} 

int sumNonTail (int n){
    int total;
    if(n==0){
        return 0;
    }
    return n + sumNonTail(n-1);
}

int main() {
  int result = sumTail(5,0);
  cout << result << endl;
  int result2 = sumNonTail (6);
  cout << result2 << endl;
  
  /*tail recursion passes each call forward, so no work left after recursion*/
  /*non-tail recursion creates a to do list where each call has to wait for the recursive call to perform the next operation*/
}
