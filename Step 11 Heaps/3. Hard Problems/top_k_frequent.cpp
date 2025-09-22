#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(auto x : m){
            int first = x.first;
            int second = x.second;
            pi p = {second,first};
            pq.push(p);
            if(pq.size() > k) pq.pop();
        }
        while(pq.size() > 0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top " << k << " frequent elements: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
