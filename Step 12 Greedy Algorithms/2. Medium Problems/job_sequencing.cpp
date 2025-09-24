#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> JobScheduling(vector<vector<int>>& Jobs) {
        // Step 1: Sort by profit descending
        sort(Jobs.begin(), Jobs.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] > b[2];
        });

        int n = Jobs.size();
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, Jobs[i][1]);
        }

        // Step 2: Slot array, index = time slot
        vector<int> slot(maxDeadline + 1, -1);

        int count = 0, maxProfit = 0;

        // Step 3: Place jobs
        for (int i = 0; i < n; i++) {
            int idx = Jobs[i][1]; // deadline
            // find nearest free slot
            while (idx > 0 && slot[idx] != -1) {
                idx--;
            }
            if (idx > 0) {
                slot[idx] = Jobs[i][0]; // assign job id
                count++;
                maxProfit += Jobs[i][2];
            }
        }

        return {count, maxProfit};
    }
};

int main() {
    Solution sol;

    vector<vector<int>> Jobs1 = {{1,4,20}, {2,1,10}, {3,1,40}, {4,1,30}};
    vector<int> res1 = sol.JobScheduling(Jobs1);
    cout << res1[0] << " " << res1[1] << endl; // 2 60

    vector<vector<int>> Jobs2 = {{1,2,100}, {2,1,19}, {3,2,27}, {4,1,25}, {5,1,15}};
    vector<int> res2 = sol.JobScheduling(Jobs2);
    cout << res2[0] << " " << res2[1] << endl; // 2 127

    return 0;
}
