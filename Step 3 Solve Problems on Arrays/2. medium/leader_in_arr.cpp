#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int n = nums.size();
      int big = INT_MIN;
      vector<int> ans;
      for(int i=n-1; i>=0; i--){
        if(big < nums[i]){
            big = nums[i];
            ans.push_back(big);
        }
      }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main(){

  Solution sol;
  vector<int> ans;
  vector<int> nums ={1, 2, 5, 3, 1, 2};
  vector<int> nums2 ={-3, 4, 5, 1, -4, -5};
  
  ans =  sol.leaders(nums2);
  for(auto ele: ans){
    cout<<ele<<" ";
  }
  return 0;
}