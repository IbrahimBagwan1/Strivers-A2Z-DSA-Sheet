#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int node, vector<int> &visited, vector<int> adj[], stack<int> &st){
        visited[node] =1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, visited, adj, st);
            }
        }
        
        st.push(node);
    }
    
    
    void dfs2(int node, vector<int> & visited, vector<int> adj[]){
        visited[node] =1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs2(it, visited, adj);
            }
        }
    }
    
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<int> visited(V, 0);
        stack<int> st;
        vector<int> adj[V];
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
        vector<int> adjT[V];
        for(int i=0; i<V; i++){
            visited[i] = 0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                scc++;
                dfs2(node, visited, adjT);
            }
        }
        
        return scc;
        
    }
};

int main() {
    Solution sol;
    
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        {2, 4}
    };
    
    int result = sol.kosaraju(V, edges);
    cout << "Number of Strongly Connected Components: " << result << endl;
    
    return 0;
}