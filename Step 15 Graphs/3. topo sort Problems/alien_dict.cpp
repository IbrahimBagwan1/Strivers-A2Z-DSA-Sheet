#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        // 1. Build the graph by comparing consecutive words
        for (int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());
            
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    // Convert char to index: 'b' - 'a' = 1
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }

        // 2. Kahn's Algorithm (Topological Sort)
        vector<int> indegree(K, 0);
        for (int i = 0; i < K; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < K; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        string topo = "";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            // Convert index back to char: 1 + 'a' = 'b'
            topo += (char)(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topo;
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<string> dict(N);
    for(int i = 0; i < N; i++) {
        cin >> dict[i];
    }
    Solution sol;
    string order = sol.findOrder(dict.data(), N, K);
    cout << order << endl;
    return 0;
}