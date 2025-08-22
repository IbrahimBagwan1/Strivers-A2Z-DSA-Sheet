#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
  long long calculate(vector<int>& piles, int hourly) {
    long long total_req = 0;
    for (int i = 0; i < piles.size(); i++) {
      total_req += ceil(double(piles[i]) / double(hourly));
    }
    return total_req;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int max_elem = INT_MIN;
    for (int i = 0; i < n; i++) max_elem = max(piles[i], max_elem);
    int ans = 0;
    int left = 1;
    int right = max_elem;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (calculate(piles, mid) <= (long long)h) {
        ans = mid;
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> piles(n);
  for (int i = 0; i < n; ++i) {
    cin >> piles[i];
  }
  Solution sol;
  cout << sol.minEatingSpeed(piles, h) << endl;
  return 0;
}