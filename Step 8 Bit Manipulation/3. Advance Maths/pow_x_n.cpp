#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1) return 1;
        double ans = 1;
        bool check = false;
        long long N;
        if (n < 0) {
            N = -((long long)n);
            check = true;
        } else {
            N = n;
        }
        while (N >= 1) {
            if (N % 2 == 1) {
                ans *= x;
                N -= 1;
            }
            x = x * x;
            N = N / 2;
        }
        return (check ? 1.0 / ans : ans);
    }
};

int main() {
    Solution sol;

    cout << sol.myPow(2.0, 10) << endl;   // 1024
    cout << sol.myPow(2.1, 3) << endl;    // ~9.261
    cout << sol.myPow(2.0, -2) << endl;   // 0.25
    cout << sol.myPow(5.0, 0) << endl;    // 1

    return 0;
}
