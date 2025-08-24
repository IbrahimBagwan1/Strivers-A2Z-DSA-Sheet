#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();

        map<char, int> mp;
        mp['I']=1; 
        mp['V']=5; 
        mp['X']=10; 
        mp['L']=50; 
        mp['C']=100; 
        mp['D']=500; 
        mp['M']=1000;

        int ans =0;
        for(int i=0; i<n ; i++){
            if(i+1 < n && mp[s[i]] < mp[s[i+1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;

    string s1 = "III";      // input 1
    string s2 = "MCMXCIV";  // input 2

    cout << s1 << " -> " << obj.romanToInt(s1) << endl;
    cout << s2 << " -> " << obj.romanToInt(s2) << endl;

    return 0;
}
