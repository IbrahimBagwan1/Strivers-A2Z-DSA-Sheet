#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>> pq;
        for(auto ele : mp){
            pq.push({ele.second, ele.first});
        }

        string ans="";
        while(!pq.empty()){
            auto top = pq.top();
            ans.append(top.first, top.second);
            pq.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s1 = "tree";
    string s2 = "cccaaa";

    cout << "Input: " << s1 << " -> Output: " << sol.frequencySort(s1) << endl;
    cout << "Input: " << s2 << " -> Output: " << sol.frequencySort(s2) << endl;

    return 0;
}
