#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int matrixMultiplication(vector<int>& nums){
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=n-1; i>=1; i--){
            for(int j=i+1; j<n; j++){
                int minimum = 1e9;

                for(int k=i; k<j; k++){
                    int steps = (nums[i-1] * nums[k] * nums[j]) + dp[i][k] + dp[k+1][j];
                    minimum = min(steps, minimum);
                }

                dp[i][j] = minimum;
            }
        }

        return dp[1][n-1];
    }
};

int main(){
    Solution obj;

    vector<int> nums = {10,20,30,40,50};

    cout << obj.matrixMultiplication(nums);

    return 0;
}