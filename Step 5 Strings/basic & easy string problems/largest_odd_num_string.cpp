#include<string>
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int idx=-1;
        for(int i=n-1; i>=0 ;i--){
            if((num[i]-'0') % 2 == 1  ){ 
                return num.substr(0, i+1);
            }
        }
        return "";
    }
};