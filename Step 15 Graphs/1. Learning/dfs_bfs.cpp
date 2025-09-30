#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helperDfs(int node, int visited[], vector<int> &dfs, vector<int> adj[]) {
        visited[node] = 1;
        dfs.push_back(node);

        for (auto it : adj[node]) {
            if (!visited[it]) {
                helperDfs(it, visited, dfs, adj); // recursive DFS
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        int visited[V] = {0};
        helperDfs(0, visited, dfs, adj);  // starting from node 0
        return dfs;
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        queue<int> q;
        int visited[V] = {0};
        
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected graph
    }

    Solution obj;

    vector<int> dfs = obj.dfsOfGraph(V, adj);
    cout << "DFS Traversal: ";
    for (int node : dfs) cout << node << " ";
    cout << endl;

    vector<int> bfs = obj.bfsOfGraph(V, adj);
    cout << "BFS Traversal: ";
    for (int node : bfs) cout << node << " ";
    cout << endl;

    return 0;
}
