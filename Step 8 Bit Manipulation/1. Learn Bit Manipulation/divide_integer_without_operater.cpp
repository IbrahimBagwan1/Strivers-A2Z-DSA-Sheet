#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        bool sign = true;

        if(dividend >=0 && divisor<0) sign = false;
        else if(dividend <0 && divisor>=0) sign = false;

        long n = labs((long)dividend);
        long d = labs((long)divisor);

        long quotient = 0;

        while(n >= d){
            int count = 0;
            while(n >= (d << (count+1))){
                count += 1;
            }
            quotient += 1 << count;
            n -= (d << count);
        }

        if(quotient == (1L<<31) && sign){
            return INT_MAX;
        }
        
        if(quotient == (1L<<31) && !sign){
            return INT_MIN;
        }

        return (sign ? quotient : -quotient);
    }
};

int main() {
    Solution sol;
    
    cout << sol.divide(10, 3) << endl;     // 3
    cout << sol.divide(7, -3) << endl;     // -2
    cout << sol.divide(-2147483648, -1) << endl; // INT_MAX
    cout << sol.divide(-2147483648, 2) << endl;  // -1073741824
    
    return 0;
}
