#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1); // Initialize size to 1, not 0
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findulp(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findulp(parent[n]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // We need space for maxRow (0..maxRow) and maxCol (0..maxCol)
        // Offset columns by maxRow + 1
        DisjointSet ds(maxRow + maxCol + 1);

        unordered_map<int, int> stoneNodes;

        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cntComponents = 0;
        for (auto it : stoneNodes) {
            // Check if this active row/col is an ultimate parent
            if (ds.findulp(it.first) == it.first) {
                cntComponents++;
            }
        }

        // CORRECT LOGIC: All stones - Number of Components
        return (int)stones.size() - cntComponents;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<vector<int>> stones1 = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << "Test 1: " << sol.removeStones(stones1) << endl;
    
    // Test case 2
    vector<vector<int>> stones2 = {{0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}};
    cout << "Test 2: " << sol.removeStones(stones2) << endl;
    
    // Test case 3
    vector<vector<int>> stones3 = {{0, 0}};
    cout << "Test 3: " << sol.removeStones(stones3) << endl;
    
    return 0;
}
