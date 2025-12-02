#include <iostream>
#include <string>
using namespace std;

#define NO_OF_CHARS 256

void badCharHeuristic(const string &pattern,int badChar[]) {
    int m = pattern.length();
    for (int i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1; 
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    int badChar[NO_OF_CHARS];
    badCharHeuristic(pattern, badChar);

    int s = 0; 
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
            
        } else {
            int shift = max(1, j - badChar[text[s + j]]);
            s += shift;
        }
    }
}

int main() {
    string text = "ACGTACGTGACG";
    string pattern = "ACG";
    boyerMooreSearch(text, pattern);
}

