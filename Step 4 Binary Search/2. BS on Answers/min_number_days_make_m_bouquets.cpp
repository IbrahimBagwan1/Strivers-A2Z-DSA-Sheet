#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  int maximum(vector<int>& bloomDay, int n) {
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
      maxi = max(bloomDay[i], maxi);
    }
    return maxi;
  }

  bool bouquet(vector<int>& bloomDay, int mid, int m, int k) {
    int count = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
      if (mid >= bloomDay[i]) {
        count++;
        if (count == k) {
          m--;
          if (m == 0) return true;
          count = 0;
        }
      } else {
        count = 0;
      }
    }
    return m == 0;
  }

  int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (1LL * m * k > n) return -1;
    int maxi = maximum(bloomDay, n);
    int left = *min_element(bloomDay.begin(), bloomDay.end());
    int right = maxi;
    int ans = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (bouquet(bloomDay, mid, m, k)) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  int n, m, k;
  cout << "Enter number of flowers, bouquets, and flowers per bouquet: ";
  cin >> n >> m >> k;
  vector<int> bloomDay(n);
  cout << "Enter bloom days: ";
  for (int i = 0; i < n; ++i) {
    cin >> bloomDay[i];
  }
  Solution sol;
  int result = sol.minDays(bloomDay, m, k);
  cout << "Minimum number of days to make " << m << " bouquets: " << result << endl;
  return 0;
}