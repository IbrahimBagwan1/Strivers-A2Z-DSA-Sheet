#include <bits/stdc++.h>
using namespace std;

//Driver Code Ends
vector<int> shortestPath(int n, vector<vector<int>>& edges, int src) {
    // Build adjacency list
    vector<int> adj[n];
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // Distance array initialized to INF
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // BFS queue
    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto &nbr : adj[node]) {
            if (dist[node] + 1 < dist[nbr]) {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }

    // Replace unreached nodes with -1
    for (int i = 0; i < n; i++)
        if (dist[i] == INT_MAX)
            dist[i] = -1;

    return dist;
}
//Driver Code Starts

int main() {
    vector<vector<int>> edges = {
        {0,1}, {0,3}, {3,4}, {4,5}, {5,6}, {1,2}, {2,6}, {6,7}, {7,8}, {6,8}
    };
    int n = 9;
    int src = 0;

    vector<int> ans = shortestPath(n, edges, src);
    for (int d : ans) cout << d << " ";
    return 0;
}
