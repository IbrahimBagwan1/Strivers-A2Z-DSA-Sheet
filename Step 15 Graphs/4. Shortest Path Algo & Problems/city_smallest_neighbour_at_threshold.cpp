#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int i = 0; i < edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int cityCount = n;
        int resultCity = -1;

        for (int i = 0; i < n; i++) {
            int currentCity = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold && i != j) {
                    currentCity++;
                }
            }
            if (currentCity <= cityCount) {
                cityCount = currentCity;
                resultCity = i;
            }
        }

        return resultCity;
    }
};

int main() {
    Solution solution;

    {
        int n = 4;
        vector<vector<int>> edges = {
            {0, 1, 3},
            {1, 2, 1},
            {1, 3, 4},
            {2, 3, 1}
        };
        int distanceThreshold = 4;
        cout << "Result 1: " << solution.findTheCity(n, edges, distanceThreshold) << '\n';
    }

    {
        int n = 5;
        vector<vector<int>> edges = {
            {0, 1, 2},
            {0, 4, 8},
            {1, 2, 3},
            {1, 4, 2},
            {2, 3, 1},
            {3, 4, 1}
        };
        int distanceThreshold = 2;
        cout << "Result 2: " << solution.findTheCity(n, edges, distanceThreshold) << '\n';
    }

    return 0;
}
