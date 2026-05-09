#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
   
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
                temp[idx] = nums[i];
            }
        }

        return len;
    }    
};


int main(){
    Solution sol;
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout<< sol.lengthOfLIS(arr);
    return 0;
}
