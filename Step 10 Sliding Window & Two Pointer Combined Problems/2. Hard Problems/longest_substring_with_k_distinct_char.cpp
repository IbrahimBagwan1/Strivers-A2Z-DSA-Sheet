#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int l = 0;
        int maxCount = 0;

        map<char, int> mp;

        for (int r = 0; r < n; r++) {
            mp[s[r]]++;

            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }

            maxCount = max(maxCount, r - l + 1);
        }
        return maxCount;
    }
};

int main() {
    Solution sol;
    string s = "eceba";
    int k = 2;

    cout << "Longest substring length with at most " << k 
         << " distinct characters: " 
         << sol.kDistinctChar(s, k) << endl;

    return 0;
}
