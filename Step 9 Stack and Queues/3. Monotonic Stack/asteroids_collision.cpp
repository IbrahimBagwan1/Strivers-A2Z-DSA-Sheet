#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int stone : asteroids) {
            bool alive = true;

            // Collision only possible if stone is left-moving (<0) and stack top is right-moving (>0)
            while (alive && !st.empty() && stone < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(stone)) {
                    st.pop(); // top asteroid destroyed, check again
                } else if (abs(st.top()) == abs(stone)) {
                    st.pop(); // both destroyed
                    alive = false;
                } else {
                    alive = false; // current asteroid destroyed
                }
            }

            if (alive) st.push(stone);
        }

        // Move from stack to result (reverse order)
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {-2, -1, 1, 2},
        {1, -1, -2, -2}
    };

    for (auto& arr : testCases) {
        vector<int> result = sol.asteroidCollision(arr);
        cout << "Input: [";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << (i+1 < arr.size() ? "," : "");
        }
        cout << "] -> Output: [";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i+1 < result.size() ? "," : "");
        }
        cout << "]" << endl;
    }

    return 0;
}
