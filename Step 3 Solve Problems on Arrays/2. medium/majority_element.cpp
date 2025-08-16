#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0, count2=0, el1=INT_MIN, el2=INT_MIN;
        for(int i=0; i<n; i++){

            if(count1==0 && nums[i] != el2){
                count1=1;
                el1=nums[i];
            }
            else if(count2==0 && nums[i] != el1){
                count2=1;
                el2=nums[i];
            }
            else if(nums[i] == el1) count1++;
            else if(nums[i] == el2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1=0, count2=0;
        for(int i=0; i<n ;i++){
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }

        if(count1 > n/3){
            ans.push_back(el1);
        }
        if(count2 > n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  vector<int> result = sol.majorityElement(nums);
  cout << "Majority Element: ";
  for (int el : result) {
      cout << el << " ";
  }
  cout << endl;
  return 0;
}