#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);
        int sum = 0;

        pq.push({0, 0});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = 1;
            sum += wt;

            for (auto it : adj[node]) {
                int neighbor = it[0];
                int edgeWeight = it[1];

                if (!visited[neighbor]) {
                    pq.push({edgeWeight, neighbor});
                }
            }
        }

        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    addEdge(0, 1, 2);
    addEdge(0, 3, 6);
    addEdge(1, 2, 3);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    Solution solution;
    int result = solution.spanningTree(V, adj);

    cout << "Minimum Spanning Tree weight: " << result << endl;
    return 0;
}
