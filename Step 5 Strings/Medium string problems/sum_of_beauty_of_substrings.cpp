#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beautysum = 0;

        for(int i=0; i<n; i++){
            vector<int> temp(26,0);

            for(int j=i; j<n; j++){
                temp[s[j]-'a']++;

                int maxFreq = 0 ,  minFreq = INT_MAX;
                for(int k=0; k<26; k++){
                    if(temp[k]>0){
                        minFreq = min(minFreq, temp[k]);
                        maxFreq = max(maxFreq, temp[k]);
                    }
                }
                beautysum += (maxFreq - minFreq);
            }
        }
        return beautysum;
    }
};

int main() {
    Solution sol;

    // Hardcoded inputs (2 test cases)
    string s1 = "aabcb";
    string s2 = "zzzz";

    cout << "Beauty sum of \"" << s1 << "\": " << sol.beautySum(s1) << endl;
    cout << "Beauty sum of \"" << s2 << "\": " << sol.beautySum(s2) << endl;

    return 0;
}
