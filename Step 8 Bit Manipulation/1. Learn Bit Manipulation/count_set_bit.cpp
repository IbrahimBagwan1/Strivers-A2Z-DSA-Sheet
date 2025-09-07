#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBit(int n) {
      return __builtin_popcount(n);
    }

    int countSetBit1(int n) {
      int count = 0;
      while(n!=0){
        n = n & n-1;
        count++;
      }
      return count;
    }
};

int main() {
    Solution sol;

    int n = 13; // binary: 1101
    cout<<n<<endl;
    n = sol.countSetBit1(n);
    cout<<n<<endl;

    return 0;
}
