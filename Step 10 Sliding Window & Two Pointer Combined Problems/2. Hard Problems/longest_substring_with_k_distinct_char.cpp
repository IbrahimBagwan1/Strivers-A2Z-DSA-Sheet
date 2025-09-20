#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int l=0;
        int maxCount=0;

        map<char, int> mp;

        for(int r=0; r<n; r++){
            mp[s[r]] ++;
 
            if(mp.size() > k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()<=k) maxCount = max(maxCount, (r-l+1));         
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    string s = "eceba";
    int k = 2;

    cout << sol.kDistinctChar(s, k) << endl;

    return 0;
}
