#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// Input: str1 = "abcde", str2 = "abfce"
// Output: 2
// Explanation: The longest common substring is "ab", which has a length of 2.

class Solution{
public: 
  
  int longestCommonSubstr (string str1, string str2){
      int len1 = str1.size(); // 5  asdfg
      int len2 = str2.size(); // 5  asdjk
      int m = len1+1;// 6
      int n = len2+1;// 6
      vector<vector<int>> dp(m, vector<int> (n, 0));

      for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
          if(str1[i-1] == str2[j-1]){
            dp[i][j] = dp[i-1][j-1] +1;
          }

          else dp[i][j] =0;
        }
      }

      return dp[m-1][n-1];
  }

};


int main(){
  Solution sol;
  // Test Case 1: Standard LCS
  string s1 = "abcde";
  string s2 = "ace";
  cout << "Test Case 1 (abcde, ace): ";
  cout << sol.longestCommonSubstr(s1, s2) << " (Expected:  3)" << endl;

  // Test Case 2: No common subsequence
  string s3 = "abc";
  string s4 = "def";
  cout << "Test Case 2 (abc, def): ";
  cout << sol.longestCommonSubstr(s3, s4) << " (Expected: 0)" << endl;

  // Test Case 3: Strings are identical
  string s5 = "placement";
  string s6 = "placement";
  cout << "Test Case 3 (placement, placement): ";
  cout << sol.longestCommonSubstr(s5, s6) << " (Expected: 9)" << endl;
  return 0;
}