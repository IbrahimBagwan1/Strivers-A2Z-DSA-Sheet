#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
 
        while(x!=0){
            int last = x%10;
            x/=10;
            if (reverse > INT_MAX / 10 || (reverse == INT_MAX / 10 && last > 7)) return 0;
            if (reverse < INT_MIN / 10 || (reverse == INT_MIN / 10 && last < -8)) return 0;
            reverse = reverse *10 + last;
        }
        return reverse;
    }

    int reverese(int x){
        int rev = 0;

        while(x!=0){
            int last = x%10;
            x = x/10;
            rev = rev *10 + last;
        }
    }
};