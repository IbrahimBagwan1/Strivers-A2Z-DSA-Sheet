#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The Solution class contains the logic to solve the problem.
class Solution {
public:
    int numberOfSubstrings(std::string s) {
        int count = 0;
        int n = s.size();
        int left = 0;
        vector<int> freq = {0, 0, 0}; // Frequency for 'a', 'b', 'c'

        for (int right = 0; right < n; ++right) {
            freq[s[right] - 'a']++; // Expand the window to the right

            // While the window is valid (contains 'a', 'b', and 'c'),
            // add the number of valid substrings and shrink from the left.
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                // If the window [left..right] is valid, then any substring
                // starting at 'left' and ending at 'right' or later is also valid.
                // There are (n - right) such substrings.
                count += (n - right);
                
                // Shrink the window from the left
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return count;
    }
};

// The main function is the entry point of the program.
int main() {
    // Create an instance of the Solution class
    Solution sol;

    // 1. First hardcoded input value
    string test_string_1 = "abcabc";
    int result_1 = sol.numberOfSubstrings(test_string_1);
    cout << "Input string: " << test_string_1 << std::endl;
    cout << "Number of substrings containing 'a', 'b', and 'c': " << result_1 << std::endl;

    // 2. Second hardcoded input value
    string test_string_2 = "aaacb";
    int result_2 = sol.numberOfSubstrings(test_string_2);
    cout << "\nInput string: " << test_string_2 << std::endl;
    cout << "Number of substrings containing 'a', 'b', and 'c': " << result_2 << endl;

    return 0; // Indicate successful execution
}