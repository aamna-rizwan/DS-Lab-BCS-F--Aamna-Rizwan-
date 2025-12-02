#include <iostream>
#include <string>
using namespace std;

void computeLPS(const string &pattern, int lps[]){
    int m=pattern.length();
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMPsearch(const string &text, const string &pattern){
    int n=text.length();
    int m=pattern.length();
    int lps[1000]; //assumed pattern length is <1000
    computeLPS(pattern,lps);
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            cout << "pattern found at index : " << i-j << endl;
            j = lps[j-1];
        }
        
        else if(i<n && text[i]!=pattern[j]){
            if(j!=0){
                j=lps[j-1];
            }else{
                i++;
            }
        }
    }
}


int main() {
  string text = "ababababc";
  string pattern = "abab" ;
  KMPsearch(text,pattern);
}
