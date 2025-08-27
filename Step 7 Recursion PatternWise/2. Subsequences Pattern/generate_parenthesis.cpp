#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void parenthesis(vector<string>&a, string v,int op, int cl, int n){
        if(cl == n){
            a.push_back(v);
            return ;
        }
        if(op < n) parenthesis(a, v+'(', op+1, cl, n);
        if(cl < op) parenthesis(a, v+')', op, cl+1, n);
    }

    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> a;
        parenthesis(a, s, 0, 0, n);
        return a;
    }
};

int main() {
    Solution s;

    vector<int> testCases = {1, 2, 3, 4, 5}; // 5 hardcoded inputs

    for(int n : testCases){
        cout << "Parentheses combinations for n = " << n << ":\n";
        vector<string> res = s.generateParenthesis(n);
        for(auto &str : res){
            cout << str << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
