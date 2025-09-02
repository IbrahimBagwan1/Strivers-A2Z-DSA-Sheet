#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getPermutationsStrings(string digits, map<int,string>&mp, vector<string> &ans, int idx, string result){
        int n = digits.length();
        if(idx >= n) {
            ans.push_back(result);
            return ;
        }
        int number = digits[idx]-'0';
        string add = mp[number];
        int string_len = add.length();

        for(int i=0; i < string_len; i++){
            result.push_back(add[i]);
            getPermutationsStrings(digits, mp, ans, idx+1, result);
            result.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        map<int,string> mp;
        mp[0] = "";
        mp[1] = "";
        mp[2] = "abc"; 
        mp[3] = "def"; 
        mp[4] = "ghi"; 
        mp[5] = "jkl"; 
        mp[6] = "mno"; 
        mp[7] = "pqrs"; 
        mp[8] = "tuv"; 
        mp[9] = "wxyz";
        vector<string> ans;
        getPermutationsStrings(digits, mp, ans, 0, "");
        return ans;
    }
};

int main() {
    Solution s;
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = s.letterCombinations(digits);

    cout << "Possible letter combinations:\n";
    for(string &combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getPermutationsStrings(string digits, map<int,string>&mp, vector<string> &ans, int idx, string result){
        int n = digits.length();
        if(idx >= n) {
            ans.push_back(result);
            return ;
        }
        int number = digits[idx]-'0';
        string add = mp[number];
        int string_len = add.length();

        for(int i=0; i < string_len; i++){
            result.push_back(add[i]);
            getPermutationsStrings(digits, mp, ans, idx+1, result);
            result.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        map<int,string> mp;
        mp[0] = "";
        mp[1] = "";
        mp[2] = "abc"; 
        mp[3] = "def"; 
        mp[4] = "ghi"; 
        mp[5] = "jkl"; 
        mp[6] = "mno"; 
        mp[7] = "pqrs"; 
        mp[8] = "tuv"; 
        mp[9] = "wxyz";
        vector<string> ans;
        getPermutationsStrings(digits, mp, ans, 0, "");
        return ans;
    }
};

int main() {
    Solution s;
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> result = s.letterCombinations(digits);

    cout << "Possible letter combinations:\n";
    for(string &combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}