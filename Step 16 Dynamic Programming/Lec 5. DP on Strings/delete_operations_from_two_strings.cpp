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
        vector<vector<int>> dp(lens1+1, vector<int> (lens2+1, -1));
        return helperlcs(str1, str2, lens1-1, lens2-1, dp); 
    }

    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        int lcsSize = lcs(word1, word2);
        return n1-lcsSize + n2-lcsSize;
    }
};


int main() {
    Solution sol;

    // Test Case 1
    string s1 = "mart";
    string s1next = "karma";
    cout << "String: " << s1 << ',' << s1next << "\nNumber of steps required to make word1 and word2 the same: " << sol.minDistance(s1, s1next) << endl; 


    // Test Case 2
    string s2 = "sea";
    string s2next = "eat";
    cout << "\nString: " << s2 << ',' << s2next << "\nNumber of steps required to make word1 and word2 the same: " << sol.minDistance(s2, s2next) << endl; 


    // Test Case 3
    string s3 = "character";
    string s3next = "character";
    cout << "\nString: " << s3 << ',' << s3next << "\nNumber of steps required to make word1 and word2 the same: " << sol.minDistance(s3, s3next) << endl; 


    return 0;
}