#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // index for children
        int j = 0; // index for cookies

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // child is satisfied
            }
            j++; // move to next cookie
        }

        return i; // number of satisfied children
    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3}; // greed of children
    vector<int> s = {1, 1};    // sizes of cookies

    int result = sol.findContentChildren(g, s);
    cout << "Number of satisfied children: " << result << endl;

    return 0;
}
