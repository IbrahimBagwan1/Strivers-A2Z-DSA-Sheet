#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> edges1 = {{0, 1, 5}, {0, 2, 3}, {1, 2, 2}, {2, 3, 7}, {1, 3, 4}};
    int V1 = 4;
    int src1 = 0;
    vector<int> dist1 = sol.bellmanFord(V1, edges1, src1);
    cout << "Test 1 distances:";
    for (int d : dist1) cout << " " << d;
    cout << "\n";

    vector<vector<int>> edges2 = {{0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1}, {2, 3, 5}};
    int V2 = 4;
    int src2 = 0;
    vector<int> dist2 = sol.bellmanFord(V2, edges2, src2);
    cout << "Test 2 distances:";
    for (int d : dist2) cout << " " << d;
    cout << "\n";

    return 0;
}
