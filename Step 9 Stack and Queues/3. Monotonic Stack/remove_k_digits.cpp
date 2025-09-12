#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k) return "0";

        stack<char> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && k && (st.top()-'0') > (num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);        
        }
        while(k>0) {
            st.pop();
            k--;
        }
        
        string resk;
        while(!st.empty()){
            resk += st.top();
            st.pop();
        }
        while(resk.size() > 0 && resk[resk.size()-1] == '0')
            resk.pop_back();
        reverse(resk.begin(), resk.end());

        if(resk.size()==0) return "0";
        return resk;
    }
};

int main() {
    Solution sol;
    string num;
    int k;

    cout << "Enter number: ";
    cin >> num;
    cout << "Enter k: ";
    cin >> k;

    string result = sol.removeKdigits(num, k);
    cout << "Smallest number after removing " << k << " digits: " << result << endl;

    return 0;
}
