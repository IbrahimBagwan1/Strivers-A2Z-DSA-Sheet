#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int node = r * n + c;
                        int neighbor = nr * n + nc;
                        ds.unionBySize(node, neighbor);
                    }
                }
            }
        }

        int mx = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    mx = max(mx, ds.size[ds.findulp(r * n + c)]);
                    continue;
                }

                unordered_set<int> components;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        components.insert(ds.findulp(nr * n + nc));
                    }
                }

                int currentSize = 1;
                for (auto it : components) {
                    currentSize += ds.size[it];
                }
                mx = max(mx, currentSize);
            }
        }

        return mx == 0 ? 1 : mx;
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> grid1 = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    cout << "Test 1: " << sol.largestIsland(grid1) << endl;
    
    vector<vector<int>> grid2 = {
        {1, 1},
        {1, 1}
    };
    cout << "Test 2: " << sol.largestIsland(grid2) << endl;
    
    vector<vector<int>> grid3 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << "Test 3: " << sol.largestIsland(grid3) << endl;
    
    vector<vector<int>> grid4 = {
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 1, 1}
    };
    cout << "Test 4: " << sol.largestIsland(grid4) << endl;
    
    return 0;
}