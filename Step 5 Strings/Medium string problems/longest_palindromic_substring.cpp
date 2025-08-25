#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void expandFromCenter(string &s, int n, int left, int right, int &bestStart, int &bestLength){
        while(left>=0 && right<n && s[left]==s[right]){
            int currLength = right - left + 1;
            if(currLength > bestLength){
                bestLength = currLength;
                bestStart = left;
            }
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        int bestStart = 0;
        int bestLength = 1;

        for(int i=0; i<n; i++){
            expandFromCenter(s, n, i, i, bestStart, bestLength);     // odd
            expandFromCenter(s, n, i, i+1, bestStart, bestLength);   // even
        }
        return s.substr(bestStart, bestLength);
    }
};

int main() {
    Solution sol;

    // hardcoded input 1
    string s1 = "babad";
    cout << "Input: " << s1 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s1) << endl;

    // hardcoded input 2
    string s2 = "cbbd";
    cout << "Input: " << s2 << endl;
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s2) << endl;

    return 0;
}
