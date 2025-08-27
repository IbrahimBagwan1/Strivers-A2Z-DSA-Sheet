#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Solution {
public:
    long long myPowRecursive(int x, long n){
        if(n==0) return 1;

        long long half = myPowRecursive(x, n/2);
        if(n%2==0){
            return (half * half) % MOD;
        }
        return ((half * half) % MOD * x) % MOD;
    }

    int countGoodNumbers(long long n) {
        long even = n/2 + n%2; // number of even indices
        long odd = n/2;        // number of odd indices

        long long ans = (myPowRecursive(5, even) * myPowRecursive(4, odd)) % MOD;
        return (int)(ans % MOD);
    }
};

int main() {
    Solution s;
    long long n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Count of good numbers = " << s.countGoodNumbers(n) << endl;
    return 0;
}
