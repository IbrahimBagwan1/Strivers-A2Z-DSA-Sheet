#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int ceil  ; //lower_bound();
        int floor =-1;  // use function.
        ceil = lower_bound(nums.begin(), nums.end(), x)-nums.begin();
        int left =0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = left + (right - left) /2;

            if( nums[mid] <= x ){
                floor = mid;
                left = mid+1;
            }
            else if( nums[mid] > x ){
                right = mid-1;
            }
        }
        return {nums[floor],nums[ceil]};
    }
};

int main(){
  vector<int> nums = {3, 4, 4, 7, 8, 10};
  int target = 5;
  Solution sol;
  vector<int> temp = sol.getFloorAndCeil(nums, target);
  cout<< "Floor:"<<temp[0]<< "\tCeil: "<<temp[1];
  return 0;
}