class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n = s.length();
        int i = n-1;
        while(i>=0 && s[i]== ' ') i--;

        while(i>=0){
            int end = i;
            
            while(i>=0 && s[i]!=' ') i--;

            ans+= s.substr(i+1, end-i);
            ans+= ' ';

            while(i>=0 && s[i]== ' ') i--;
        }
        if(!ans.empty()) ans.pop_back();
                
        return ans;
    }
};