#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j=0;
        for(int i=1; i<n ;i++){
            if(nums[j] != nums[i]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};

int main() {
  vector<int> nums = {1, 1, 2};
  Solution sol;
  int k = sol.removeDuplicates(nums);
  cout << k << ", nums = [";
  for (int i = 0; i < nums.size(); ++i) {
    if (i < k)
      cout << nums[i];
    else
      cout << "_";
    if (i != nums.size() - 1)
      cout << ",";
  }
  cout << "]" << endl;
  return 0;
}