#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int n= nums.size();
    if(n==0) return 0;
    unordered_set<int> st;

    for(int i=0; i<n; i++){
      st.insert(nums[i]);
    }

    int longestSeq = 1;

    for(int ele: st){
      if(st.find(ele-1)==st.end()){
        int count =1;
        int x = ele;
        while(st.find(x+1) != st.end()){
          count++;
          x =x+1;
        }
        longestSeq = max(count, longestSeq);
      }
    }
    return longestSeq;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << endl;
  return 0;
}