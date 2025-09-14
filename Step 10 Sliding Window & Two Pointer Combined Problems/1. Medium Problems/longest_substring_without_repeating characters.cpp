#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.size();

        int maxLen=0;
        int left=0;
        for(int right =0; right<n; right++){
            if(mp.find(s[right])==mp.end()){
                mp[s[right]]=right;
            }
            else{
                int item = mp[s[right]];
                mp[s[right]] = right;
                if(left < item){
                    left = item +1;
                }
                else if (item==left){
                    left += 1;
                }
            }
            int len = (right-left+1);
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = sol.lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;

    return 0;
}
