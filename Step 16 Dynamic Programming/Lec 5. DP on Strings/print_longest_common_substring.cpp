#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    string lcs(string str1, string str2) {
        int lens1 = str1.size();
        int lens2 = str2.size();
        vector<vector<int>> dp(lens1+1, vector<int> (lens2+1, 0));

        // shifting of indexes...
        for(int i=1; i<=lens1; i++){
            for(int j=1; j<=lens2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] =  1+ dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }


        int i=lens1, j=lens2;
        int lenAns = dp[i][j];
        string ans;
        for(int i=0; i<lenAns; i++) ans += '$';
        int idx = lenAns-1;

        while(i>0 && j>0){
          if(str1[i-1] == str2[j-1]){
            ans[idx] = str1[i-1];
            i--;
            j--;
            idx--;
          }

          else if(dp[i-1][j] > dp[i][j-1]){
            i--;
          }
          else{
            j--;
          }
        }
        return ans;
    }
};


int main() {
    Solution sol;

    // Test Case 1: Standard LCS
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Test Case 1 (abcde, ace): ";
    cout << sol.lcs(s1, s2) << " (Expected:  'ace')" << endl;

    // Test Case 2: No common subsequence
    string s3 = "abc";
    string s4 = "def";
    cout << "Test Case 2 (abc, def): ";
    cout << sol.lcs(s3, s4) << " (Expected: 0)" << endl;

    // Test Case 3: Strings are identical
    string s5 = "placement";
    string s6 = "placement";
    cout << "Test Case 3 (placement, placement): ";
    cout << sol.lcs(s5, s6) << " (Expected: 'placement')" << endl;

    return 0;
}