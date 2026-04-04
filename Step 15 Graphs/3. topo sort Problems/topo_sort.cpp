#include <bits/stdc++.h>
using namespace std;

// Class containing the solution logic
class Solution {
public:
    // Function to perform DFS
    void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        // Mark the current node as visited
        vis[node] = 1;

        // Explore all neighbors of this node
        for (auto it : adj[node]) {
            // If the neighbor is not visited, recursively perform DFS
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }

        // After visiting all neighbors, push this node into the stack
        st.push(node);
    }

    // Function to perform Topological Sort
    vector<int> topoSort(int V, vector<int> adj[]) {
        // Create a visited array to mark visited vertices
        vector<int> vis(V, 0);

        // Stack to store vertices in finishing order
        stack<int> st;

        // Perform DFS from each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Prepare the result array
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        // Return the topological ordering
        return ans;
    }
};

// Driver code
int main() {
    // First hardcoded input
    // Number of vertices and edges
    int V1 = 6, E1 = 6;

    // Adjacency list representation of the graph
    vector<int> adj1[V1];
    adj1[5].push_back(0);
    adj1[5].push_back(2);
    adj1[4].push_back(0);
    adj1[4].push_back(1);
    adj1[2].push_back(3);
    adj1[3].push_back(1);

    // Create an object of Solution
    Solution obj;

    // Get the topological order
    vector<int> res1 = obj.topoSort(V1, adj1);

    // Print the result
    cout << "Topological Sort for first graph: ";
    for (auto it : res1) {
        cout << it << " ";
    }
    cout << endl;

    // Second hardcoded input
    // Number of vertices and edges
    int V2 = 4, E2 = 4;

    // Adjacency list representation of the graph
    vector<int> adj2[V2];
    adj2[0].push_back(1);
    adj2[0].push_back(2);
    adj2[1].push_back(2);
    adj2[1].push_back(3);
    adj2[2].push_back(3);

    // Get the topological order
    vector<int> res2 = obj.topoSort(V2, adj2);

    // Print the result
    cout << "Topological Sort for second graph: ";
    for (auto it : res2) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}