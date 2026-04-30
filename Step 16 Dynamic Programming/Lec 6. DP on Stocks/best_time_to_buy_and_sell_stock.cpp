#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProf = 0;
        int mini = prices[0];

        for(int i=0; i<n; i++){
            int cost = prices[i]-mini;
            maxProf = max(cost, maxProf);
            mini = min(mini, prices[i]);
        }
        return maxProf;
    }
};

int main(){
  Solution sol;
  vector<int> arr = {7,1,5,3,6,4};
  cout << sol.maxProfit(arr);
  return 0;
}