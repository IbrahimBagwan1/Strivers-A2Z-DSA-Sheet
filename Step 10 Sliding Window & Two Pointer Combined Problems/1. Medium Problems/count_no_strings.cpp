#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        int n = s.size();

        map<char,int> mp;
        mp['a'] = -1;
        mp['b'] = -1;
        mp['c'] = -1;

        for(int i=0; i<n; i++){
            mp[s[i]] = i;
            if(mp['a']!=-1 && mp['b']!=-1 && mp['c']!=-1){
                count = count + (1 + min(mp['a'], min(mp['b'], mp['c'])));
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