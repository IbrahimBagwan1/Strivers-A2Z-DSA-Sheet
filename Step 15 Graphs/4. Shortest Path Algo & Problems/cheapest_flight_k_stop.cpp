#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it: flights){  // node, cost
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue< pair<int,pair<int,int>>> pq; // storing  {stops, {node, cost}} 
        
        vector<int> dist(n, 1e9);

        pq.push({0, {src, 0}});
        dist[src]=0;

        while(!pq.empty()){
            int node = pq.front().second.first;
            int stopsTaken = pq.front().first;
            int parentCost = pq.front().second.second;

            pq.pop();

            if(stopsTaken > k) continue;

            for(auto it: adj[node]){
                int newNode = it.first;
                int cost = it.second;

                if(dist[newNode] > cost+parentCost && stopsTaken<=k){
                    dist[newNode] = cost+parentCost;
                    pq.push({stopsTaken+1, {newNode, dist[newNode]}});
                }
            }

        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};

int main() {
    Solution sol;

    vector<vector<int>> flights1 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500}
    };
    int result1 = sol.findCheapestPrice(3, flights1, 0, 2, 1);
    cout << "Cheapest price for input 1: " << result1 << '\n';

    vector<vector<int>> flights2 = {
        {0, 1, 100},
        {1, 2, 100},
        {0, 2, 500},
        {2, 3, 100}
    };
    int result2 = sol.findCheapestPrice(4, flights2, 0, 3, 2);
    cout << "Cheapest price for input 2: " << result2 << '\n';

    return 0;
}
