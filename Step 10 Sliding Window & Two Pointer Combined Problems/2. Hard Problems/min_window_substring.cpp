#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
        int n = s.size();
        int m = t.size();
        if(m>n) return "";

        for(int i=0; i<m; i++){
            mp[t[i]]++;
        }
        int minIdx=-1;
        int minLen = INT_MAX;
        int count =0;
        int l=0;
        int r=0;

        while(r<n){
            if(mp[s[r]] > 0){
                count++;
            }
            mp[s[r]]--;
            
            while(count==m){
                if((r-l+1) < minLen){
                    minIdx = l;
                    minLen = r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) count--;
                l++;
            }
            r++;
        }

        return minIdx==-1? "" : s.substr(minIdx, minLen); 
    }
};

int main() {
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;

    return 0;
}
