#include<bits/stdc++.h>
using namespace std;

void recursive_bs(vector<int> nums, int lo, int hi, int target){
  if(hi < lo) return;
  int mid = lo + (hi-lo)/2;

  if(nums[mid]== target){
    cout<<"Found";
    return ;
  }
  else if (nums[mid] < target) {
    return recursive_bs(nums, mid+1, hi, target);
  }
  else{
    return recursive_bs(nums, lo, mid-1, target);
  }
}


int main(){
  vector<int> nums = {3,4,5,6,7,8,19,1992,3999,94999};
  int target =3999;
  recursive_bs(nums, 0, nums.size()-1, target);
  return 0;
}