#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int helperlcs(string str1, string str2, int lens1, int lens2, vector<vector<int>> & dp){
        if(lens1 <0 || lens2<0) return 0;
        
        if(dp[lens1][lens2] != -1) return dp[lens1][lens2];

        if(str1[lens1] == str2[lens2]){
            return 1+helperlcs(str1, str2, lens1-1, lens2-1, dp);
        }

        return dp[lens1][lens2] = max(helperlcs(str1, str2, lens1, lens2-1, dp), helperlcs(str1, str2, lens1-1, lens2, dp));
    }

    int lcs(string str1, string str2) {
        int lens1 = str1.size();
        int lens2 = str2.size();
        vector<vector<int>> dp(lens1+1, vector<int> (lens2+1, 0));
        // return helperlcs(str1, str2, lens1-1, lens2-1, dp); 

        // shifting of indexes...
        // for(int j=0; j<lens1; j++) dp[0][j] =0;
        // for(int i=0; i<lens2; i++) dp[i][0] =0;

        for(int i=1; i<=lens1; i++){
            for(int j=1; j<=lens2; j++){
                if(str1[lens1-1] == str2[lens2-1]){
                    dp[i][j] =  1+ dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // else take the maximum till this index.
            }
        }

        return dp[lens1][lens2];
    }
};


int main() {
    Solution sol;

    // Test Case 1: Standard LCS
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Test Case 1 (abcde, ace): ";
    cout << sol.lcs(s1, s2) << " (Expected: 3 for 'ace')" << endl;

    // Test Case 2: No common subsequence
    string s3 = "abc";
    string s4 = "def";
    cout << "Test Case 2 (abc, def): ";
    cout << sol.lcs(s3, s4) << " (Expected: 0)" << endl;

    // Test Case 3: Strings are identical
    string s5 = "placement";
    string s6 = "placement";
    cout << "Test Case 3 (placement, placement): ";
    cout << sol.lcs(s5, s6) << " (Expected: 9)" << endl;

    return 0;
}