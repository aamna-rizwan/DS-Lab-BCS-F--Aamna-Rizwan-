#include <iostream>
using namespace std;

int calculateFactorial(int n){
    if(n==0 || n==1){
        return n;
    }else
    return n*calculateFactorial(n-1);
}
int main() {
    cout << "Enter number\n";
    int r;
    cin >> r;
    int result = calculateFactorial(r);
    cout << "factorial is  " << result << endl;
}
