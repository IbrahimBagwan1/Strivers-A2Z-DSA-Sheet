#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int sign = 1; // 1 is positive...
        int i=0;
        long long  ans=0;
        bool check = false;

        // step 1: go towards where number starts.
        while(  i<n && !isdigit(s[i])){
            
            if(s[i] == '-'){
                sign = -1;
                if(check) return 0;
                check = true;
            }
            if(s[i] == '+'){
                if(check) return 0;
                check = true;
            }
            if(check && s[i]==' ') return 0;

            if(s[i]!='+' && s[i]!='-' && s[i]!=' '){
                return 0;
            }
            i++;
        }

        string change = s.substr(i, s.size()-i);

        // step 2: remove leading zeros
        int j=0;
        while(change[j]=='0')j++;

        // step 3: convert to integer.
        string final_conv = change.substr(j, s.size()-j);
        
        int len2 = final_conv.size()-1;
        int len=0;
        while(len <= len2){
            if(!isdigit(final_conv[len])){
                    break;
                }
            int first = final_conv[len] - '0';
            ans = ans*10 + first;
            len++;
            if(ans*sign > INT_MAX) return INT_MAX;
            if(ans*sign < INT_MIN) return INT_MIN;

        }

        ans *= sign ;
        return ans;
    }
};

int main() {
    Solution obj;

    string s1 = "words and 987";     // should return 0
    string s2 = "   -91283472332";   // should clamp to INT_MIN

    cout << s1 << " -> " << obj.myAtoi(s1) << endl;
    cout << s2 << " -> " << obj.myAtoi(s2) << endl;

    return 0;
}
