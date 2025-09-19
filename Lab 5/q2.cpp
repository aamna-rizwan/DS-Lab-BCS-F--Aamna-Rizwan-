#include <iostream>
using namespace std;
int functionA(int n);
int functionB(int n);

int printNumbers(int n){
    if(n!=1){
        cout << n << endl;
        return printNumbers(n-1);
    }else 
    return n;
}

int functionA(int n){
    if(n==0){
        return 0;
    }else
    if (n%2!=0){
        cout << n << " " ;
       return functionB(n-1);
    }
    else if(n%2==0){
        cout << n << " " ;
        return functionA(n-1);
    }
    return 0;
}   

int functionB(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        cout << n << " " ;
        return n;
    }else if(n%2!=0){
        cout << n << " " ;
        return functionB(n-1);
    }
     else if(n%2==0){
        cout << n << " " ;
        return functionA(n-1);
    }
    return 0;
}


int main() {
    cout << "Enter number for func A and B " ;
    int n;
    cin >> n;
    int result=functionA(n);
    cout << result << " ";
    cout << "\nEnter number for printNumber func " ;
    int num;
    cin >> num;
    int final;
    final=printNumbers(num);
    cout << final << endl;
}
   
