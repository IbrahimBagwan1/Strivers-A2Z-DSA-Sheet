#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
        }
        for (int i = 0; i < t.length(); i++) {
            map2[t[i]]++;
        }

        for (auto x : map1) {
            char ch1 = x.first;
            int f1 = x.second;

            if (map2.find(ch1) != map2.end()) {
                int f2 = map2[ch1];
                if (f1 != f2) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test cases
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";

    cout << "Test 1: " << (sol.isAnagram(s1, t1) ? "True" : "False") << endl;
    cout << "Test 2: " << (sol.isAnagram(s2, t2) ? "True" : "False") << endl;

    return 0;
}
