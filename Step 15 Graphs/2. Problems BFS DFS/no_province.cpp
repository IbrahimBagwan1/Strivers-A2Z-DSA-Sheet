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
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (edges[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
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

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        return findNumberOfComponent(V, isConnected);
    }
};

int main() {
    Solution obj;

    // Example input
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int result = obj.findCircleNum(isConnected);
    cout << "Number of Provinces: " << result << endl;

    return 0;
}
