#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool oddEven(int n) {
      return ((n & 1)==0);
    }
};

int main() {
    Solution sol;

    int n = 13; // binary: 1101
    cout<<n<<endl;
    n = sol.oddEven(n);
    cout<<(n? "Even": "Odd")<<endl;

    return 0;
}
