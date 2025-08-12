#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int dup = x;
    long long rev = 0;
    while (x > 0) {
      int last = x % 10;
      x /= 10;
      rev = rev * 10 + last;
    }
    return (dup == rev);
  }
};

int main() {
  Solution sol;
  int num;
  cout << "Enter an integer: ";
  cin >> num;
  if (sol.isPalindrome(num)) {
    cout << num << " is a palindrome." << endl;
  } else {
    cout << num << " is not a palindrome." << endl;
  }
  return 0;
}