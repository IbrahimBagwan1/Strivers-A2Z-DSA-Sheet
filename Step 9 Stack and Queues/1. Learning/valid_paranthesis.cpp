#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 != 0) return false;
        stack<char> temp;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push(s[i]);
            } else {
                if(temp.empty()) return false;
                char ch = temp.top();
                temp.pop();
                if((ch == '(' && s[i] != ')')) return false;
                if((ch == '[' && s[i] != ']')) return false;
                if((ch == '{' && s[i] != '}')) return false;
            }
        }
        return temp.empty();
    }
};

int main() {
    Solution sol;

    string s1 = "()";
    string s2 = "([{}])";
    string s3 = "(]";
    string s4 = "(((";

    cout << s1 << " -> " << (sol.isValid(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (sol.isValid(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (sol.isValid(s3) ? "Valid" : "Invalid") << endl;
    cout << s4 << " -> " << (sol.isValid(s4) ? "Valid" : "Invalid") << endl;

    return 0;
}
