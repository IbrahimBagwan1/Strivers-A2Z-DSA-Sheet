#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open_count = 0;   // Unmatched '('
        int close_needed = 0; // Unmatched ')'

        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else if (c == ')') {
                if (open_count > 0) {
                    // We have an unmatched '(', so we pair them up
                    open_count--;
                } else {
                    // No unmatched '(' available, so this ')' is invalid
                    close_needed++;
                }
            }
        }

        // The total additions required is the sum of both unmatched counters
        return open_count + close_needed;
    }
};

int main(){
    string s = "())";

    Solution sol;
    cout << sol.minAddToMakeValid(s);
}