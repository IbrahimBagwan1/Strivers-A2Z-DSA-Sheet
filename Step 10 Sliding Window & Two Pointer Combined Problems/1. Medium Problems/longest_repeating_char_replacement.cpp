#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int right = 0, left = 0;
        map<char,int> mp;
        int maxSize = k+1;
        int maxLen = 0;
        int maxFreq = 0;

        while (right < n) {
            mp[s[right]]++;
            maxFreq = max(maxFreq, mp[s[right]]);

            if ((right - left + 1) - maxFreq > k) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            if ((right - left + 1) - maxFreq <= k) {
                maxLen = max(maxLen, (right - left + 1));
            }
            right++;
        }
        return maxLen;
    }
};

int main() {
    Solution sol;

    // Hardcoded input
    string s = "AABABBA";
    int k = 1;

    int ans = sol.characterReplacement(s, k);
    cout << "Result: " << ans << endl;

    return 0;
}
