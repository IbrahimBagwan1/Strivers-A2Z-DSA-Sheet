#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> primeFactors(vector<int>& queries) {
        int n = queries.size();
        int maxElement = *max_element(queries.begin(), queries.end());
        vector<int> spf(maxElement+1);
        for(int i=2; i<=maxElement; i++) spf[i]=i;

        for(int i=2; i*i<=maxElement; i++){
            if(spf[i] == i){
                for(int j=i*i; j<=maxElement; j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int num = queries[i];
            vector<int> temp;

            while(num!=1){
                temp.push_back(spf[num]);
                num = num / spf[num];
            }
            
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> queries = {2, 3, 4, 5, 6, 12, 18, 72};

    vector<vector<int>> result = sol.primeFactors(queries);

    for (int i = 0; i < result.size(); i++) {
        cout << "Prime factors of " << queries[i] << ": ";
        for (int x : result[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}
