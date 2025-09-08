#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> small, large;
        
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                small.push_back(i);           // smaller divisor
                if (i != n / i) large.push_back(n / i);  // paired larger divisor
            }
        }

        reverse(large.begin(), large.end());   // put larger divisors in order
        small.insert(small.end(), large.begin(), large.end());
        return small;
    }
};

int main() {
    Solution sol;
    
    int n = 36;
    vector<int> result = sol.divisors(n);
    
    cout << "Divisors of " << n << ": ";
    for (int d : result) cout << d << " ";
    cout << endl;
    
    return 0;
}
