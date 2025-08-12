#include <iostream>
using namespace std;

class Solution {
public:
  int count_dig(int n) {
    int count = 0;
    while (n != 0) {
      count++;
      n /= 10;
    }
    return count;
  }

  bool isArmstrong(int n) {
    int dig = count_dig(n);
    int dup = n;
    int sum = 0;
    while (n > 0) {
      int last = n % 10;
      n /= 10;
      int ans = 1;
      for (int i = 0; i < dig; i++) {
        ans = ans * last;
      }
      sum = sum + ans;
    }
    return (sum == dup);
  }
};

int main() {
  Solution sol;
  int num;
  cout << "Enter a number: ";
  cin >> num;
  if (sol.isArmstrong(num)) {
    cout << num << " is an Armstrong number." << endl;
  } else {
    cout << num << " is not an Armstrong number." << endl;
  }
  return 0;
}