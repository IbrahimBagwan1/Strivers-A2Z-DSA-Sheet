#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long MOD = 1e9+7;

        vector<pair<int,long long>> adj[n];
        for(int i=0; i<roads.size() ;i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long > distance(n, 1e15);
        vector<long long> ways(n, 0);

        priority_queue<pair<long long,int>, vector<pair<long long ,int>> , greater<pair<long long,int>>> pq;
            // 0 indexed
        pq.push({0, 0});
        distance[0] = 0;
        ways[0] = 1;


        while(!pq.empty()){
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > distance[node]) continue;

            for(auto it: adj[node]){
                int neighbour = it.first;
                long long neighbourCost = it.second;

                long long totalCost = cost + neighbourCost;

                if(totalCost <= distance[neighbour]){
                    if(distance[neighbour] == totalCost){
                        ways[neighbour] = (ways[neighbour] + ways[node])% MOD;
                    }
                    else{
                        pq.push({totalCost, neighbour});
                        distance[neighbour] = totalCost;
                        ways[neighbour]= ways[node];
                    }
                }
            }
        }
        return (ways[n-1] % MOD);
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> roads = {{0,1,2},{0,2,3},{1,2,1},{1,3,4},{2,3,5},{3,4,1}};
    cout << sol.countPaths(n, roads) << endl;
    return 0;
}