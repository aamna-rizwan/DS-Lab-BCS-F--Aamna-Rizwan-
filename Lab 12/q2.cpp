#include <iostream>
#include <string>  
using namespace std;

const int PRIME_BASE = 31;
const int MODULUS = 1000000007;

long long calculateHash(string str, int len) {
    long long hash = 0;
    long long power = 1;
    for (int i = 0; i < len; ++i) {
        hash = (hash + (str[i] * power)) % MODULUS;
        power = (power * PRIME_BASE) % MODULUS;
    }
    return hash;
}

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    if (m == 0||m > n) {
        return;
    }
    long long patternHash = calculateHash(pattern, m);
    long long textWindowHash = calculateHash(text, m);
    long long highestPower = 1;
    for (int i = 0; i < m - 1; ++i) {
        highestPower = (highestPower * PRIME_BASE) % MODULUS;
    }

    for (int i = 0; i <= n - m; ++i) {
        if (patternHash == textWindowHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < n - m) {
            textWindowHash = (textWindowHash
                              - (text[i] * highestPower)) % MODULUS;
            textWindowHash = (textWindowHash * PRIME_BASE
                              + text[i + m]) % MODULUS;
            if (textWindowHash < 0) {
                textWindowHash += MODULUS;
            }
        }
    }
}

int main(){
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier" ;
    string pattern = "Algorithms" ;
    rabinKarp(text, pattern);
 
}
