#include <bits/stdc++.h>
using namespace std;

class Solution {	
public:
    int xorUptoNum(int n) {
        if (n % 4 == 0) return n;
        if (n % 4 == 1) return 1;
        if (n % 4 == 2) return n + 1;
        return 0;
    }

    int findRangeXOR(int l, int r) {
        return xorUptoNum(r) ^ xorUptoNum(l - 1);
    }
};

int main() {
    Solution sol;

    int l = 3, r = 9;  // example test
    cout << "XOR from " << l << " to " << r << " = " << sol.findRangeXOR(l, r) << endl;

    // You can test with more ranges
    cout << "XOR from 1 to 4 = " << sol.findRangeXOR(1, 4) << endl;
    cout << "XOR from 5 to 5 = " << sol.findRangeXOR(5, 5) << endl;
    cout << "XOR from 0 to 7 = " << sol.findRangeXOR(0, 7) << endl;

    return 0;
}
