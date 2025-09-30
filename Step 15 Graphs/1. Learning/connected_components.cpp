#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected
        }

        vector<int> visited(V, 0);
        int count = 0;

        // Run DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adj, visited);
            }
        }

        return count;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    Solution obj;
    cout << "Number of Connected Components = "
         << obj.findNumberOfComponent(V, edges) << endl;

    return 0;
}
