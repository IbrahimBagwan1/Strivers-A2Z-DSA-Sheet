#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int rowWithMax1s(vector<vector<int>> &nums) {
    int max_count = 0;
    int idx = -1;
    int m = nums[0].size();
    for (int i = 0; i < nums.size(); i++) {
      int lower = lower_bound(nums[i].begin(), nums[i].end(), 1) - nums[i].begin();
      int total = m - lower;
      if (max_count < total) {
        max_count = total;
        idx = i;
      }
    }
    return idx;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> nums(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> nums[i][j];

  Solution sol;
  int res = sol.rowWithMax1s(nums);
  cout << res << endl;
  return 0;
}