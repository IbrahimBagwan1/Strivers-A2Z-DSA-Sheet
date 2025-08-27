#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myStoiRecursive(string& s, int i, long num, int sign){
        if(i>=s.size() || !isdigit(s[i])) return (int)(sign*num);

        int digit = s[i]-'0';
        num = num*10 + digit;

        if(sign*num >= INT_MAX) return INT_MAX;
        if(sign*num <= INT_MIN) return INT_MIN;

        return myStoiRecursive(s, i+1, num, sign);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        while(i<n && s[i] == ' ') i++;
        int sign=1;
        if(i<n && (s[i]=='+' || s[i] == '-')){
            sign = (s[i]=='-')? -1: 1 ;
            i++;
        }
        return myStoiRecursive(s, i, 0L, sign);
    }
};

int main() {
    Solution sol;

    string s1 = "   -42";
    string s2 = "4193 with words";

    cout << "Input: \"" << s1 << "\" -> Output: " << sol.myAtoi(s1) << endl;
    cout << "Input: \"" << s2 << "\" -> Output: " << sol.myAtoi(s2) << endl;

    return 0;
}
