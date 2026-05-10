#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> hash(n);

        int maxi = 1;
        int lastIdx = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){

            hash[i] = i;

            for(int prev = 0; prev < i; prev++){

                if((nums[i] % nums[prev] == 0) && (1 + dp[prev] > dp[i])){

                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }

        vector<int> lis;

        while(hash[lastIdx] != lastIdx){

            lis.push_back(nums[lastIdx]);
            lastIdx = hash[lastIdx];
        }

        lis.push_back(nums[lastIdx]);

        reverse(lis.begin(), lis.end());

        return lis;
    }
};

int main(){

    Solution obj;

    vector<int> nums = {1, 2, 4, 8};

    vector<int> ans = obj.largestDivisibleSubset(nums);

    for(auto el : ans){
        cout << el << " ";
    }

    return 0;
}