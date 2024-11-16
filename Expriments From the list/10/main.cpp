// AIM: Compare the performance of Rabin-Karp, Knuth-Morris-Pratt and naive string matching algorithms.
#include <iostream>
#include <string>
using namespace std;
#define d 256

void naiveSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    cout << "Naive Matching Indices: ";
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) break;
        }
        if (j == m) {
            cout << i << " ";
        }
    }
    cout << endl;
}

void rabinKarpSearch(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();
    int h = 1;  // hash multiplier
    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for text
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    cout << "Rabin-Karp Matching Indices: ";
    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) cout << i << " ";
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    cout << endl;
}

void computeLPSArray(string pattern, int m, int lps[]) {
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int lps[m];
    computeLPSArray(pattern, m, lps);
    int i = 0, j = 0;
    cout << "KMP Matching Indices: ";
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << (i - j) << " ";
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    cout << endl;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);
    naiveSearch(text, pattern);
    int q=101;
    rabinKarpSearch(text, pattern, q);
    KMPSearch(text, pattern);
    return 0;
}