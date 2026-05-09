#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1);
        vector<int> hash(n);
        int maxi=0;
        int lastIdx =0;

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
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
        for(auto el : lis){
            cout<< el<< " ";
        }
        cout<<endl;
        return maxi;
    }    
};


int main(){
    Solution sol;
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<< sol.lengthOfLIS(arr);
    return 0;
}
