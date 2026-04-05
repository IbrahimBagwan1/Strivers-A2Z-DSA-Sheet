#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n + 1);
        
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            if (d > dist[node]) continue;

            for (auto it2 : adj[node]) {
                int adjNode = it2.first;
                int wt = it2.second;

                if (d + wt < dist[adjNode]) {
                    dist[adjNode] = d + wt;
                    parent[adjNode] = node;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        if (dist[n] == 1e9) return {-1};

        vector<int> path;
        int node = n;

        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());

        vector<int> result;
        result.push_back(dist[n]);
        for (auto x : path) result.push_back(x);

        return result;
    }
};

int main() {
    Solution sol;
    
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, 1},
        {2, 4, 5},
        {3, 4, 8},
        {4, 5, 2}
    };
    
    vector<int> result = sol.shortestPath(n, m, edges);
    
    cout << "Shortest Distance and Path: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}
