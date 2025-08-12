#include <iostream>
using namespace std;

class Solution {
public:
  bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) return false;
    }
    return true;
  }
};

int main() {
  Solution sol;
  int n;
  cout << "Enter a number: ";
  cin >> n;
  if (sol.isPrime(n)) {
    cout << n << " is a prime number." << endl;
  } else {
    cout << n << " is not a prime number." << endl;
  }
  return 0;
}