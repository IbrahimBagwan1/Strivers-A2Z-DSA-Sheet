#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool detectLoop(int i, vector<int> adj[], vector<int> &visited){
        visited[i]=1;
        queue<pair<int,int>> q;
        q.push({i, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it: adj[node]){
                if(!visited[it]){
                    q.push({it, node});
                    visited[it]=1;
                }
                else if(parent!=it){
                        return true;
                }
                
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectLoop(i, adj, visited)) return true;
            }
        }
        return false;
    }
};

int main(){
    int V = 5;
    vector<int> adj[V];
    
    // Add edges
    adj[0].push_back(1);
    adj[1].push_back(0);
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    adj[4].push_back(1);
    adj[1].push_back(4);
    
    Solution sol;
    if(sol.isCycle(V, adj)){
        cout << "Cycle detected\n";
    } else {
        cout << "No cycle\n";
    }
    
    return 0;
}
