#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:

    bool compareBoth(string &first, string &second){

        int len1 = first.length();
        int len2 = second.length();

        if(len1 != len2 - 1) return false;

        int i = 0, j = 0;

        while(i < len1 && j < len2){

            if(first[i] == second[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }

        return (i == len1);
    }

public:

    int longestStrChain(vector<string>& words) {

        int n = words.size();

        sort(words.begin(), words.end(),
            [](string &a, string &b){
                return a.length() < b.length();
            });

        vector<int> dp(n, 1);

        int maxi = 1;

        for(int i = 1; i < n; i++){

            for(int prev = 0; prev < i; prev++){

                if(compareBoth(words[prev], words[i]) &&
                   1 + dp[prev] > dp[i]){

                    dp[i] = 1 + dp[prev];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

int main(){

    Solution obj;

    vector<string> words = {"a","b","ba","bca","bda","bdca"};

    cout << obj.longestStrChain(words);

    return 0;
}