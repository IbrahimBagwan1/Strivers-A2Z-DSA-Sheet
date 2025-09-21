#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> replaceElementsByRank(vector<int> &nums){
        int n = nums.size();
        priority_queue<int , vector<int>, greater<int>> pq; 
        for(auto &ele : nums) pq.push(ele);

        map<int,int> mp;
        int i = 1;
        while(!pq.empty()){
            auto ele = pq.top(); pq.pop();
            mp.insert({ele, i});
            i++;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(mp[nums[i]]);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {40, 10, 20, 30};
    vector<int> result1 = sol.replaceElementsByRank(nums1);

    cout << "Ranks for nums1: ";
    for(int x : result1) cout << x << " ";
    cout << endl;

    vector<int> nums2 = {100, 100, 50, 200};
    vector<int> result2 = sol.replaceElementsByRank(nums2);

    cout << "Ranks for nums2: ";
    for(int x : result2) cout << x << " ";
    cout << endl;

    vector<int> nums3 = {20 ,15 ,26 ,2 ,98 ,6};
    vector<int> result3 = sol.replaceElementsByRank(nums3);

    cout << "Ranks for nums3: ";
    for(int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
