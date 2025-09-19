//in working
#include <iostream>
using namespace std;
int ackermann(int m, int n){
    if(m==0){
        return n+1;
    }else if(m>0 && n==0){
        return ackermann(m-1,1);
    }else if(m>0 && n>0){
        return ackermann(m-1, ackermann(m, n-1));
    }
    return 0;
}
int main() {
  cout << "enter num1 ";
  int num1,num2;
  cin >> num1;
  cout << "enter num2 ";
  cin >> num2;
  int result = ackermann(num1,num2);
  cout << result << " ";
}
