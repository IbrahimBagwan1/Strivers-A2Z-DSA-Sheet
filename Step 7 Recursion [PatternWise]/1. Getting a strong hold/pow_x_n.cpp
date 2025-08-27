#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPowRecursive(double x, long n) {
        if(n == 0) return 1.0;   // base case
        double half = myPowRecursive(x, n/2);  // divide the power by 2
        if(n % 2 == 0) {
            return half * half;  // even case
        } else {
            return half * half * x;  // odd case
        }
    }

    double myPow(double x, int n) {
        long N = n;   // use long to handle -INT_MIN safely
        if(N < 0) {
            return 1.0 / myPowRecursive(x, -N);
        }
        return myPowRecursive(x, N);
    }
};

int main() {
    Solution sol;

    // Test case 1
    double x1 = 2.0;
    int n1 = 10;
    cout << "Input: x=" << x1 << ", n=" << n1 
         << " -> Output: " << sol.myPow(x1, n1) << endl;

    // Test case 2
    double x2 = 2.0;
    int n2 = -3;
    cout << "Input: x=" << x2 << ", n=" << n2 
         << " -> Output: " << sol.myPow(x2, n2) << endl;

    return 0;
}
