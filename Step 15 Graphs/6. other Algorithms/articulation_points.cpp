#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], 
             vector<int> &mark, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                child++;
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                
                // Check if node is an articulation point
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
            } else {
                // Back-edge: update low value
                low[node] = min(low[node], tin[it]);
            }
        }
        // Special case for root
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i] == 1) ans.push_back(i);
        }
        
        if (ans.size() == 0) return {-1};
        return ans;
    }
};

int main() {
    int V = 5;
    vector<int> adj[V];
    
    // Adding edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[0].push_back(2);
    adj[2].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[1].push_back(3);
    adj[3].push_back(1);
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    Solution sol;
    vector<int> result = sol.articulationPoints(V, adj);
    
    cout << "Articulation Points: ";
    for (int point : result) {
        cout << point << " ";
    }
    cout << endl;
    
    return 0;
}
