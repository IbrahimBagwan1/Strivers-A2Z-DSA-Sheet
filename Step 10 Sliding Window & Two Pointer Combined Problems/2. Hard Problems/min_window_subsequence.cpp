#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX;
        int start = -1;

        int i = 0; // pointer for s1
        while (i < n) {
            // Step 1: move forward to try matching s2
            int j = 0;
            while (i < n) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == m) break; // matched full s2
                }
                i++;
            }
            if (j < m) break; // s2 not found till end of s1

            // Step 2: move backward to minimize window
            int end = i; // end of window
            j = m - 1;
            while (i >= 0) {
                if (s1[i] == s2[j]) {
                    j--;
                    if (j < 0) break; // reached start of s2
                }
                i--;
            }
            int startIdx = i;
            int winLen = end - startIdx + 1;
            if (winLen < minLen) {
                minLen = winLen;
                start = startIdx;
            }

            // Step 3: move i just after startIdx to search next window
            i = startIdx + 1;
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }
};

int main() {
    Solution sol;

    string s1 = "abcdebdde";
    string s2 = "bde";

    cout << "Minimum window subsequence: "
         << sol.minWindow(s1, s2) << endl;

    return 0;
}
