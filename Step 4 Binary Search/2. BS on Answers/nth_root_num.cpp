#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
  int NthRoot(int N, int M) {
    int raise = -1;
    int left = 1;
    int right = M;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      long long val = 1;
      for (int i = 0; i < N; ++i) {
        val *= mid;
        if (val > M) break;
      }
      if (val == M) return mid;
      else if (val > M) right = mid - 1;
      else left = mid + 1;
    }
    return raise;
  }
};

int main() {
  int N, M;
  cout << "Enter N and M: ";
  cin >> N >> M;
  Solution sol;
  int result = sol.NthRoot(N, M);
  cout << "The " << N << "th root of " << M << " is: " << result << endl;
  return 0;
}