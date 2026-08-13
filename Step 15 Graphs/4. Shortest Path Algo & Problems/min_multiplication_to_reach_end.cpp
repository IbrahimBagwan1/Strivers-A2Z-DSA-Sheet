#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

#define MOD 100000

    int minimumMultiplications(vector<int> &arr, int start, int end) {

        // Queue stores:
        // {current value, number of steps taken to reach it}
        //
        // Example:
        // {30, 2} means we reached value 30 in 2 multiplications.
        queue<pair<int, int>> q;

        // dist[x] = minimum number of steps needed to reach x
        //
        // There are 100000 possible values:
        // 0 -> 99999
        vector<int> dist(100000, INT_MAX);

        // We start from 'start' with 0 steps
        q.push({start, 0});

        while (!q.empty()) {

            // Take the current value and number of steps
            int multiplyNode = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we have reached the destination,
            // return the number of steps.
            if (multiplyNode == end)
                return steps;

            // Try multiplying the current value
            // with every number present in arr
            for (int num : arr) {

                // Generate the next value
                //
                // Example:
                // multiplyNode = 3
                // num = 5
                //
                // nextSol = (3 * 5) % 100000 = 15
                int nextSol = (num * multiplyNode) % MOD;

                // If we found a way to reach nextSol
                // in fewer steps than before
                if (steps + 1 < dist[nextSol]) {

                    // Store the minimum steps
                    dist[nextSol] = steps + 1;

                    // Push the new value into the queue
                    q.push({nextSol, dist[nextSol]});
                }
            }
        }

        // If the destination was never reached,
        // return -1.
        //
        // Otherwise return the minimum distance.
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};

int main() {

    Solution obj;

    // Example 1
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    int answer = obj.minimumMultiplications(arr, start, end);

    cout << "Minimum steps: " << answer << endl;

    return 0;
}