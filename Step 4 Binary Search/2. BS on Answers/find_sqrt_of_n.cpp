#include <iostream>
using namespace std;

class Solution {
public:
  long long floorSqrt(long long n)  {
    long long left = 0, right = n, ans = 0;
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      if (mid * mid <= n) {
        ans = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  long long n;
  cout << "Enter n: ";
  cin >> n;
  cout << "Floor sqrt of " << n << " is " << sol.floorSqrt(n) << endl;
  return 0;
}