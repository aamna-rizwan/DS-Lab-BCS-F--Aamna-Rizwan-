#include <iostream>
#include <string>
using namespace std;

void bruteForce(string input, string pattern){
    int n=input.length();
    int m=pattern.length();
    int c=0;
    for(int i=0;i<=n-m;i++){
        int j=0;
        while(j<m && input[i+j]==pattern[j]){
            j++;
        }
        if(j==m){
            cout << "Pattern found at " << i << endl;
        }
        c++;
    }
    cout << "Number of comparisions taken : " << c << endl;
}

int main(){
    string msg = "the quick brown fox jumps over the lazy dog";
    string key = "the";
    bruteForce(msg,key);
}
