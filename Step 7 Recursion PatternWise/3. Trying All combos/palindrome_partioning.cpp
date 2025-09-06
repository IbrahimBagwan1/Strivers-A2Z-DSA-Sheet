#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }

    void getSubstring(string s, vector<vector<string>> &ans, vector<string> &temp, int idx){
        int n = s.size();
        if(idx == n){
            ans.push_back(temp);
            return ;
        }
        for(int i = idx; i < n; i++){
            if(palindrome(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                getSubstring(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.length() == 1) return {{s}};
        vector<string> temp;
        getSubstring(s, ans, temp, 0);
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    vector<vector<string>> result = obj.partition(s);

    cout << "All possible palindrome partitions:\n";
    for(auto &vec : result){
        cout << "[ ";
        for(auto &str : vec){
            cout << str << " ";
        }
        cout << "]\n";
    }

    return 0;
}
