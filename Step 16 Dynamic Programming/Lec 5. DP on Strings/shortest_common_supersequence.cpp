#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();

        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        int i=n1;
        int j=n2;
        string superSeq;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                superSeq += str1[i-1];
                i--;
                j--;
            }

            else if(dp[i][j-1] > dp[i-1][j]) {
                superSeq += str2[j-1];
                j--;
            }
            else{
                superSeq += str1[i-1];
                i--;
            }
        }

        while(i>0){
            superSeq += str1[i-1];
            i--;
        } 
        while(j>0){
            superSeq += str2[j-1];
            j--;
        } 
        reverse(superSeq.begin(), superSeq.end());
        return superSeq;
    }
};

int main() {
    Solution obj;

    string str1 = "abac";
    string str2 = "cab";

    string result = obj.shortestCommonSupersequence(str1, str2);

    cout << "Shortest Common Supersequence: " << result << endl;

    return 0;
}